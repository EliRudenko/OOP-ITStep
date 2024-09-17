const express = require('express');
const path = require('path');
const fs = require('fs');
const bodyParser = require('body-parser');
const app = express();

app.use(express.static(path.join(__dirname, 'data')));
app.use(bodyParser.urlencoded({ extended: true }));  // Для обработки данных формы

// Главная страница
app.get('/', (req, res) => {
    res.sendFile(path.join(__dirname, 'data', 'index.html'));
});

// Страница новостей
app.get('/news', (req, res) => {
    res.sendFile(path.join(__dirname, 'data', 'news.html'));
});

// О нас
app.get('/about', (req, res) => {
    res.sendFile(path.join(__dirname, 'data', 'about.html'));
});

// Логин
app.get('/login', (req, res) => {
    res.sendFile(path.join(__dirname, 'data', 'login', 'login.html'));
});

// Регистрация
app.get('/register', (req, res) => {
    res.sendFile(path.join(__dirname, 'data', 'register', 'register.html'));
});

// Добавление продукта - форма
app.get('/add-product', (req, res) => {
    res.sendFile(path.join(__dirname, 'data', 'add-product.html'));
});

// Добавление продукта - обработка данных
app.post('/add-product', (req, res) => {
    const newProduct = {
        name: req.body.name,
        price: req.body.price,
        description: req.body.description,
        image: req.body.image,
        condition: req.body.condition,
        seller: req.body.seller,
        pickup: req.body.pickup,
        delivery: req.body.delivery
    };

    const productString = `name: ${newProduct.name}, price: ${newProduct.price}, description: ${newProduct.description}, image: ${newProduct.image}, condition: ${newProduct.condition}, seller: ${newProduct.seller}, pickup: ${newProduct.pickup}, delivery: ${newProduct.delivery}\n`;

    fs.appendFile(path.join(__dirname, 'data/products/product.txt'), productString, (err) => {
        if (err) {
            return res.status(500).send('Ошибка при сохранении продукта.');
        }
        res.send('Продукт успешно добавлен!');
    });
});

// Страница продукта по имени
app.get('/name/:productName', (req, res) => {
    const productName = req.params.productName.toLowerCase();

    fs.readFile(path.join(__dirname, 'data/products/product.txt'), 'utf8', (err, data) => {
        if (err) {
            return res.status(500).send('Ошибка чтения файла с продуктами');
        }

        const products = data.split('\n');
        let productInfo = null;

        products.forEach(product => {
            if (product.toLowerCase().includes(`name: ${productName}`)) {
                productInfo = product;
            }
        });

        if (productInfo) {
            const productDetails = productInfo.split(', ').reduce((acc, pair) => {
                const [key, value] = pair.split(': ');
                if (key && value) {
                    acc[key.trim()] = value.trim();
                }
                return acc;
            }, {});

            fs.readFile(path.join(__dirname, 'data', 'product-template.html'), 'utf8', (err, template) => {
                if (err) {
                    return res.status(500).send('Ошибка чтения шаблона');
                }

                let page = template
                    .replace(/{productName}/g, productDetails['name'] || 'Неизвестное имя')
                    .replace(/{productDescription}/g, productDetails['description'] || 'Нет описания')
                    .replace(/{productPrice}/g, productDetails['price'] || 'Неизвестная цена')
                    .replace(/{productImage}/g, productDetails['image'] || 'Нет изображения')
                    .replace(/{productCondition}/g, productDetails['condition'] || 'Нет информации')
                    .replace(/{productSeller}/g, productDetails['seller'] || 'Неизвестный продавец')
                    .replace(/{pickupInfo}/g, productDetails['pickup'] || 'Нет информации о самовывозе')
                    .replace(/{deliveryInfo}/g, productDetails['delivery'] || 'Нет информации о доставке');

                res.send(page);
            });

        } else {
            res.status(404).send(`<h1>Продукт с именем ${productName} не найден</h1>`);
        }
    });
});

// Запуск сервера
const PORT = 8080;
app.listen(PORT, () => {
    console.log(`Сервер запущен на порту ${PORT}`);
});
