var express = require('express');
var mssql = require('mssql');
var path = require('path');
var bodyParser = require('body-parser');

var app = express();
var port = 8080;


var config = 
{
    server: 'Elin-TUF\\ELI',
    database: 'userdb',

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


app.get('/', function (req, res) 
{
    res.sendFile(path.join(__dirname, 'data', 'index.html'));
});

app.get('/news', function (req, res) 
{
    res.sendFile(path.join(__dirname, 'data', 'news.html'));
});


app.get('/register', function (req, res) 
{
    res.sendFile(path.join(__dirname, 'data', 'register.html'));
});


app.post('/register', function (req, res)
{
    const { name, login, password } = req.body; 


    const request = new mssql.Request();
    request.query(`SELECT * FROM Users WHERE Login = '${login}'`, (err, result) => 
    {
        if (err) 
        {
            console.error('Error checking login:', err);
            res.send('Error checking login.');
        } 
        else if (result.recordset.length > 0) 
        {
            res.send('Login already exists. Try a different one.');
        } 
        else 
        {
            request.query(`INSERT INTO Users (Name, Login, Password) VALUES ('${name}', '${login}', '${password}')`, (err) => 
            {
                if (err) 
                {
                    console.error('Error inserting user:', err);
                    res.send('Error registering user.');
                } 
                else 
                {
                    res.send('Registration successful!');
                }
            });
        }
    });
});
  




app.get('/login', function (req, res) 
{
    res.sendFile(path.join(__dirname, 'data', 'login.html'));
});


app.post('/login', function (req, res) 
{
    const { login, password } = req.body;
    const request = new mssql.Request();


    if (login === 'admin' && password === 'admin') 
    {
        request.query('SELECT * FROM Users', (err, result) => 
        {
            if (err) 
            {
                console.error('Error fetching users:', err);
                res.send('Error loading user list.');
            } 
            else 
            {
                let userTableHTML = `
                <!DOCTYPE html>
                <html lang="en">
                <head>
                    <meta charset="UTF-8">
                    <meta name="viewport" content="width=device-width, initial-scale=1.0">
                    <title>User List</title>
                    <style>
                        body { font-family: Arial, sans-serif; background-color: #f4f4f4; padding: 20px; }
                        h1 { text-align: center; color: #333; }
                        table { width: 60%; border-collapse: collapse; margin: 20px auto; }
                        table, th, td { border: 1px solid #ccc; }
                        th, td { padding: 10px; text-align: center; }
                        th { background-color: #5cb85c; }
                    </style>
                </head>
                <body>
                    <h1>User List</h1>
                    <table>
                        <thead>
                            <tr>
                                <th>ID</th>
                                <th>Name</th>
                                <th>Login</th>
                            </tr>
                        </thead>
                        <tbody>
                `;

                result.recordset.forEach(user => 
                {
                    userTableHTML += `
                        <tr>
                            <td>${user.Id}</td>
                            <td>${user.Name}</td>
                            <td>${user.Login}</td>
                        </tr>
                    `;
                });

                userTableHTML += `
                        </tbody>
                    </table>
                </body>
                </html>
                `;

                res.send(userTableHTML); 
            }
        });
    } 
    else 
    {
        request.query(`SELECT * FROM Users WHERE Login = '${login}' AND Password = '${password}'`, (err, result) => 
        {
            if (err) 
            {
                console.error('Error logging in:', err);
                res.send('Error during login.');
            } 
            else if (result.recordset.length > 0) 
            {
                res.sendFile(path.join(__dirname, 'data', 'index.html'));
            } 
            else
            {
                res.send('Invalid login or password.');
            }
        });
    }
});


app.listen(port, function () 
{
    console.log('App listening on port ' + port);
});
