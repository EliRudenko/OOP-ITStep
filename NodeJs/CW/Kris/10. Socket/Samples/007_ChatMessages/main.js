// подключение express и socket.io 
var app = require('express')();
var server = require('http').Server(app);
var io = require('socket.io')(server);

var path = require('path'); 

var port = 8080; 

var connections = [];
var users = {};

app.get('/', function (req, res) {
    res.sendFile(path.join(__dirname, 'index.html'));
});

app.get('/client.js', function (req, res) {
    res.sendFile(path.join(__dirname, 'client.js')); 
});


io.on('connection', function (socket) 
{

    let userName = '';  

    connections.push(socket);
    console.log('Connected: %s sockets connected', connections.length); 


    socket.on('register user', function (data) 
    {
        userName = data.name;  
        users[socket.id] = userName; 
        console.log('User registered: ' + userName);

        io.emit('update user list', Object.values(users)); 
    });


    socket.on('disconnect', function () 
    {
        delete users[socket.id];  
        connections.splice(connections.indexOf(socket), 1);
        console.log('Disconnected: %s sockets connected', connections.length); 

        io.emit('update user list', Object.values(users)); 
    });

    socket.on('send message', function (data) 
    {
        if (userName) 
        {
            io.sockets.emit('chat message', { name: userName, text: data.text }); 
        }
    });
});

server.listen(port, function () 
{
    console.log('app running on port ' + port); 
});
