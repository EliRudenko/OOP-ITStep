const express = require('express');
const path = require('path');
const fs = require('fs');
const app = express();

app.use(express.static(path.join(__dirname, 'data')));

app.get('/', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'index.html'));
});

app.get('/news', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'news.html'));
});

app.get('/about', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'about.html'));
});

app.get('/login', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'login', 'login.html'));
});

app.get('/register', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'register', 'register.html'));
});



app.get('/name/:productName', (req, res) => 
{
    const productName = req.params.productName.toLowerCase();

    fs.readFile(path.join(__dirname, 'data/products/product.txt'), 'utf8', (err, data) => 
    {
        if (err) 
        {
            return res.status(500).send('Ошибка чтения файла с продуктами');
        }

        const products = data.split('\n');
        let productInfo = null;

        products.forEach(product => 
        {
            if (product.toLowerCase().includes(`name: ${productName}`))
            {
                productInfo = product;
            }
        });

        if (productInfo) 
        {
            const productDetails = productInfo.split(', ').reduce((acc, pair) => 
            {
                const [key, value] = pair.split(': ');

                if (key && value) 
                {
                    acc[key.trim()] = value.trim();
                } 
                else {
                    console.error(`Неверный формат пары: ${pair}`);
                }

                return acc;
            }, {});

            fs.readFile(path.join(__dirname, 'data', 'product-template.html'), 'utf8', (err, template) => 
            {
                if (err) 
                {
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

        } 
        else {
            res.status(404).send(`<h1>Продукт с именем ${productName} не найден</h1>`);
        }
    });
});

const PORT = 8080;
app.listen(PORT, () => { console.log(`Сервер запущен на порту ${PORT}`); });
