var http = require('http');
var fs = require('fs');
var path = require('path');
var qs = require('querystring');

var port = 8080;

var server = http.createServer(function (req, res) 
{

    if (req.method === 'GET' && req.url === '/') 
    {
        var filePath = path.join(__dirname, 'index.html');
        fs.readFile(filePath, function (err, data) 
        {
            if (err) 
            {
                res.writeHead(500, { 'Content-Type': 'text/plain' });
                res.end('Ошибка при загрузке страницы');
            } 
            else 
            {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.end(data);
            }
        });
    }

    else if (req.method === 'POST' && req.url === '/submit') 
    {
        var body = '';
        req.on('data', function (chunk) { body += chunk.toString(); });

        req.on('end', function () 
        {
            var formData = qs.parse(body);
            var logData = `Логин: ${formData.login}, Пароль: ${formData.password}\n`;


            fs.appendFile('registrations.txt', logData, function (err) 
            {
                if (err) 
                {
                    res.writeHead(500, { 'Content-Type': 'text/plain' });
                    res.end('Ошибка при записи данных');
                    return;
                }

                res.writeHead(200, { 'Content-Type': 'text/plain' });
                res.end('Регистрация успешна!');

                console.log('Регистрация успешна!');
            });
        });
    } 
    else 
    {
        res.writeHead(404, { 'Content-Type': 'text/plain' });
        res.end('Страница не найдена');
    }
});

server.listen(port, function() { console.log('Сервер запущен на порту ' + port); });
