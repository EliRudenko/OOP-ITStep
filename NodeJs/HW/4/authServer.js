const http = require('http');
const fs = require('fs');
const querystring = require('querystring');


const server = http.createServer((req, res) => 
{

    if (req.method === 'GET' && req.url === '/') 
    {
        fs.readFile('form.html', (err, data) => 
        {
            if (err) 
            {
                res.writeHead(500, { 'Content-Type': 'text/plain; charset=utf-8' });
                res.end('Ошибка на сервере');
            } 
            else {
                res.writeHead(200, { 'Content-Type': 'text/html; charset=utf-8' });
                res.end(data);
            }
        });
    }

    else if (req.method === 'POST' && req.url === '/login') 
    {
        let body = '';

        req.on('data', chunk => { body += chunk.toString(); });

        req.on('end', () => 
        {
            const parsedData = querystring.parse(body);
            const username = parsedData.username;
            const password = parsedData.password;

            console.log(`Логин: ${username}, Пароль: ${password}`);

            res.writeHead(200, { 'Content-Type': 'text/plain; charset=utf-8' });
            res.end('Авторизация выполнена успешно.');
        });
    } 
    else 
    {
        res.writeHead(404, { 'Content-Type': 'text/plain; charset=utf-8' });
        res.end('Страница не найдена');
    }
});


server.listen(8080, () => { console.log('Сервер запущен на http://localhost:8080'); });
