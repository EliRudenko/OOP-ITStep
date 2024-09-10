const express = require('express');
const path = require('path');
const app = express();

app.use(express.static(path.join(__dirname, 'data')));


app.get('/', (req, res) => { res.sendFile(path.join(__dirname, 'data', 'index.html')); });

app.get('/news', (req, res) => { res.sendFile(path.join(__dirname, 'data', 'news.html')); });

app.get('/about', (req, res) => { res.sendFile(path.join(__dirname, 'data', 'about.html')); });

app.get('/login', (req, res) => { res.sendFile(path.join(__dirname, 'data', 'login', 'login.html')); });

app.get('/register', (req, res) => { res.sendFile(path.join(__dirname, 'data', 'register', 'register.html')); });


const PORT = 8080;
app.listen(PORT, () => { console.log(`Сервер запущен на порту ${PORT}`); });
