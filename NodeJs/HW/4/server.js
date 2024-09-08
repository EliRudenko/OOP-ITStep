var http = require('http');
var querystring = require('querystring');


var server = http.createServer(function (req, res) 
{

    if (req.method === 'GET') 
    {
        res.writeHead(200, {'Content-Type': 'text/plain; charset=utf-8'});
        res.end('GET запрос принят.');
    }

    else if (req.method === 'POST') 
    {
        var body = '';
        req.on('data', function (chunk) { body += chunk.toString(); });

        req.on('end', function () 
        {
            var parsedData = querystring.parse(body);
            res.writeHead(200, {'Content-Type': 'text/plain; charset=utf-8'});
            res.end('POST запрос с данными: ' + JSON.stringify(parsedData));
        });
    }

    else {
        res.writeHead(405, {'Content-Type': 'text/plain; charset=utf-8'});
        res.end('Метод не поддерживается');
    }
});


server.listen(8080, function() { console.log('Сервер запущен на порту 8080'); });
