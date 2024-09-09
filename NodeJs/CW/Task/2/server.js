var http = require('http'); 
var fs = require('fs'); 
var url = require('url'); 
var path = require('path'); 

var port = 8080;

var server = http.createServer(function(req, res) 
{

    req.on('error', function (err) { console.log(err); });

    if (req.method === "GET" && req.url === "/") 
    {
        var file_path = path.join(__dirname, 'index.html');
        fs.readFile(file_path, function (err, data) 
        {
            if (err) 
            {
                console.log(err);
                res.writeHead(404, { 'Content-Type': 'text/plain' });
                res.write('Not Found!');
            } 
            else
            {
                res.writeHead(200, { 'Content-Type': 'text/html' });
                res.write(data.toString());
            }

            res.end();
        });

    } 
    else if (req.method === "POST" && req.url === "/submit") 
    {
        let body = '';

        req.on('data', function (chunk) { body += chunk.toString(); });

        req.on('end', function () 
        {
            var params = new URLSearchParams(body);
            var name = params.get('name') || "Гость";

            res.writeHead(200, { 'Content-Type': 'text/html' });
            res.write(`<h1>Привет, ${name}!</h1>`);
            res.end();
        });
    } 
    else
    {
        res.writeHead(404, { 'Content-Type': 'text/html' });
        res.end('Resource not found');
    }

}).listen(port);

console.log('server running on port ' + port);
