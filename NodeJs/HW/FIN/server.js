const express = require('express');
const mssql = require('mssql');
const path = require('path');
const bodyParser = require('body-parser');
const session = require('express-session');

const app = express();
const port = 8080;

var config = 
{
    server: 'Elin-TUF\\ELI',
    database: 'PizzaDB',

    user: 'admin',
    password: 'admin',

    options: 
    {
        encrypt: true,
        trustServerCertificate: true
    },
    port: 1433
};

mssql.connect(config, err => 
{
    if (err)
    {
        console.error('Error connecting to the database:', err);
    } 
    else { console.log('Connected to the database'); }
});

app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static(path.join(__dirname, 'data')));

app.use(session({
    secret: 'SecretKey',
    resave: false,
    saveUninitialized: true
}));

app.get('/', (req, res) => 
{
    if (req.session.isAdmin) 
    {
        res.redirect('/admin');
    } 
    else if (req.session.username) 
    {
        res.send(`Добро пожаловать, ${req.session.username}!`);
    } 
    else { res.sendFile(path.join(__dirname, 'data', 'index.html')); }
});



app.get('/pizzas', async (req, res) => 
{
    const request = new mssql.Request();
    try 
    {
        const result = await request.query('SELECT * FROM Pizzas');
        res.json(result.recordset);
    } 
    catch (err) 
    {
        console.error('Ошибка при получении данных о пиццах:', err);
        res.status(500).send('Ошибка при получении данных о пиццах.');
    }
});





app.get('/register', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'register.html'));
});
app.post('/register', async (req, res) => 
{
    const { login, password } = req.body;
    const pool = await mssql.connect(config);
    const transaction = new mssql.Transaction(pool);

    try 
    {
        await transaction.begin();
        const request = new mssql.Request(transaction);
        const result = await request.query(`SELECT * FROM Users WHERE Login = '${login}'`);

        if (result.recordset.length > 0) 
        {
            await transaction.rollback();
            res.send('Логин уже существует. Попробуйте другой.');
        } 
        else 
        {
            await request.query(`INSERT INTO Users (Login, Password) VALUES ('${login}', '${password}')`);
            await transaction.commit();
            res.send('Регистрация успешна!');
        }

    } 
    catch (err) 
    {
        console.error('Ошибка при регистрации пользователя:', err);
        await transaction.rollback();
        res.send('Ошибка при регистрации.');
    }
});




app.get('/login', (req, res) =>
{
    res.sendFile(path.join(__dirname, 'data', 'login.html'));
});
app.post('/login', (req, res) => 
{
    const { login, password } = req.body;
    const request = new mssql.Request();

    if (login === 'admin' && password === 'admin') 
    {
        req.session.isAdmin = true;
        req.session.username = 'admin';
        res.redirect('/admin');
    } 
    else 
    {
        request.query(`SELECT * FROM Users WHERE Login = '${login}' AND Password = '${password}'`, (err, result) => 
        {
            if (err) 
            {
                console.error('Ошибка при входе:', err);
                res.send('Ошибка при входе.');
            } 
            else if (result.recordset.length > 0) 
            {
                req.session.username = login;
                res.send(`Добро пожаловать, ${login}!`);
            } 
            else { res.send('Неверный логин или пароль.'); }
        });
    }
});




app.get('/admin', (req, res) => 
{
    if (!req.session.isAdmin) 
    {
        res.redirect('/');
        return;
    }

    const request = new mssql.Request();
    request.query('SELECT * FROM Pizzas', (err, result) => 
    {
        if (err) 
        {
            console.error('Ошибка при получении данных о пиццах:', err);
            res.send('Ошибка загрузки списка пицц.');
        } 
        else 
        {
            let pizzaTableHTML = `
            <!DOCTYPE html>
            <html lang="en">
            <head>
                <meta charset="UTF-8">
                <meta name="viewport" content="width=device-width, initial-scale=1.0">
                <title>Pizza Management</title>
                <style>
                    body { font-family: Arial, sans-serif; background-color: #f4f4f4; padding: 20px; }
                    h1 { text-align: center; color: #333; }
                    table { width: 80%; border-collapse: collapse; margin: 20px auto; }
                    table, th, td { border: 1px solid #ccc; }
                    th, td { padding: 10px; text-align: center; }
                    th { background-color: rgb(79, 79, 79); color: rgb(255, 255, 255); }
                    img { width: 50px; height: 50px; }
                    a { text-decoration: none; color: rgb(255, 255, 255); background-color: rgb(254, 0, 33); padding: 10px; border-radius: 5px;}
                    a:hover { background-color: rgb(190, 23, 27);}
                </style>
            </head>
            <body>
                <h1>Pizza Management</h1>
                <a href="/add-pizza">Добавить пиццу</a>
                <table>
                    <thead>
                        <tr>
                            <th style="width: 25%; height: auto;">Картинка</th>
                            <th>Название</th>
                            <th style="width: 10%; height: auto;">Цена</th>
                            <th>Описание</th>
                            <th style="width: 20%; height: auto;">Действия</th>
                        </tr>
                    </thead>
                    <tbody>`;

            result.recordset.forEach(pizza => 
            {
                pizzaTableHTML += `
                    <tr>
                        <td><img style="width: 50%; height: 50%;" src="${pizza.ImageUrl}" alt="${pizza.Name}"></td>
                        <td style="font-weight: 600;">${pizza.Name}</td>
                        <td style="font-weight: 600;">${pizza.Price} грн</td>
                        <td>${pizza.Description}</td>
                        <td>
                            <a href="/edit-pizza/${pizza.PizzaId}">Редактировать</a>
                            <a href="/delete-pizza/${pizza.PizzaId}" onclick="return confirm('Вы уверены, что хотите удалить эту пиццу?')">Удалить</a>
                        </td>
                    </tr>`;
            });

            pizzaTableHTML += `
                    </tbody>
                </table>
            </body>
            </html>`;

            res.send(pizzaTableHTML);
        }
    });
});




app.get('/add-pizza', (req, res) => 
{
    if (!req.session.isAdmin) 
    {
        res.redirect('/');
        return;
    }

    res.sendFile(path.join(__dirname, 'data', 'add-pizza.html'));
});
app.post('/add-pizza', async (req, res) => 
{
    const { name, price, description, imageUrl } = req.body;
    const pool = await mssql.connect(config);
    const transaction = new mssql.Transaction(pool);

    try 
    {
        await transaction.begin();
        const request = new mssql.Request(transaction);

        request.input('name', mssql.NVarChar, name);
        request.input('price', mssql.Decimal, price);
        request.input('description', mssql.NVarChar, description);
        request.input('imageUrl', mssql.NVarChar, imageUrl);

        await request.query('INSERT INTO Pizzas (Name, Price, Description, ImageUrl) VALUES (@name, @price, @description, @imageUrl)');
        await transaction.commit();
        res.redirect('/admin');
    } 
    catch (err) 
    {
        console.error('Ошибка при добавлении пиццы:', err);
        await transaction.rollback();
        res.send('Ошибка при добавлении пиццы.');
    }
});
  

app.get('/edit-pizza/:id', async (req, res) => 
{
    const pizzaId = req.params.id;
    const request = new mssql.Request();

    try 
    {
        const result = await request.query(`SELECT * FROM Pizzas WHERE PizzaId = ${pizzaId}`);

        if (result.recordset.length > 0) 
        {
            const pizza = result.recordset[0];
            res.send(`
                <style>
                    body {font-family: Arial, sans-serif; background-color: #f4f4f4; margin: 0; padding: 20px; }

                    h1 {text-align: center; color: #333; }

                    form {
                        max-width: 400px;
                        margin: 0 auto;
                        background: #fff;
                        padding: 20px;
                        border-radius: 5px;
                        box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
                    }

                    label {
                        display: block;
                        margin-bottom: 5px;
                        color: #555;
                    }

                    input[type="text"],
                    input[type="password"], textarea
                    {
                        width: 95%;
                        padding: 10px;
                        margin-bottom: 15px;
                        border: 1px solid #ccc;
                        border-radius: 3px;
                    }

                    button {
                        width: 100%;
                        padding: 10px;
                        background-color: rgb(254, 0, 33);
                        border: none;
                        border-radius: 3px;
                        color: white;
                    }
                   button:hover { background-color: rgb(190, 23, 27);}
                </style>
                <h1>Edit Pizza</h1>
                <form action="/edit-pizza/${pizza.PizzaId}" method="POST">
                    <label for="name">Название:</label><br>
                    <input type="text" id="name" name="name" value="${pizza.Name}"><br>
                    
                    <label for="price">Цена:</label><br>
                    <input type="text" id="price" name="price" value="${pizza.Price}"><br>
                    
                    <label for="description">Описание:</label><br>
                    <textarea id="description" name="description">${pizza.Description}</textarea><br>
                    
                    <label for="imageUrl">URL картинки:</label><br>
                    <input type="text" id="imageUrl" name="imageUrl" value="${pizza.ImageUrl}"><br>
                    
                    <button type="submit">Сохранить изменения</button>
                </form>
            `);
        } 
        else { res.send('Пицца не найдена.'); }
    } 
    catch (err) 
    {
        console.error('Ошибка при получении данных пиццы:', err);
        res.send('Ошибка при получении данных.');
    }
});

app.post('/edit-pizza/:id', async (req, res) => 
{
    const pizzaId = req.params.id;
    const { name, price, description, imageUrl } = req.body;
    const request = new mssql.Request();

    try 
    {
        await request.query(`
            UPDATE Pizzas 
            SET Name = '${name}', Price = '${price}', Description = '${description}', ImageUrl = '${imageUrl}' 
            WHERE PizzaId = ${pizzaId}
        `);
        res.redirect('/admin');
    } 
    catch (err) 
    {
        console.error('Ошибка при обновлении пиццы:', err);
        res.send('Ошибка при обновлении пиццы.');
    }
});




app.get('/delete-pizza/:id', async (req, res) => 
{
    const pizzaId = req.params.id;
    const request = new mssql.Request();

    try 
    {
        await request.query(`DELETE FROM Pizzas WHERE PizzaId = ${pizzaId}`);
        res.redirect('/admin');
    } 
    catch (err) 
    {
        console.error('Ошибка при удалении пиццы:', err);
        res.send('Ошибка при удалении пиццы.');
    }
});



app.listen(port, () => 
{
    console.log(`Server is running on port ${port}`);
});
