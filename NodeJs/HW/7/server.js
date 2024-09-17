var express = require('express');
var app = express();
var port = 8080;
var mssql = require('mssql');

var config = 
{
    user: 'admin',               
    password: 'admin',         
    server: 'Elin',              
    database: 'Library',          
    port: 1433,                 
    options:
    {
        encrypt: true,  
        trustServerCertificate: true 
    },
};



// 1. Все книги
app.get('/books', (req, res) => 
{
    var connection = new mssql.ConnectionPool(config);

    connection.connect(err => 
    {
        if (err) console.log(err);

        var ps = new mssql.PreparedStatement(connection);

        ps.prepare('SELECT * FROM dbo.Books', function (err) 
        {
            if (err) console.log(err);

            ps.execute({}, function (err, data) 
            {
                if (err) console.log(err);

                res.send(data.recordset);
                console.log('Books retrieved');
            });
        });
    });
});



// 2. Книги конкретного автора (через url)
app.get('/books/author/:authorId', (req, res) => 
{
    var authorId = req.params.authorId;
    var connection = new mssql.ConnectionPool(config);

    connection.connect(err => 
    {
        if (err) console.log(err);

        var ps = new mssql.PreparedStatement(connection);
        ps.input('authorId', mssql.Int);

        ps.prepare('SELECT * FROM dbo.Books WHERE authorId = @authorId', function (err) 
        {
            if (err) console.log(err);

            ps.execute({ authorId: authorId }, function (err, data) 
            {
                if (err) console.log(err);

                res.send(data.recordset);
                console.log('Books by author retrieved');
            });
        });
    });
});



// 3. Книги конкретного издательства (через url)
app.get('/books/publisher/:publisherName', (req, res) => 
{
    var publisherName = req.params.publisherName;
    var connection = new mssql.ConnectionPool(config);

    connection.connect(err => 
    {
        if (err) console.log(err);

        var ps = new mssql.PreparedStatement(connection);
        ps.input('publisherName', mssql.NVarChar);

        ps.prepare('SELECT * FROM dbo.Books WHERE publisherName = @publisherName', function (err) 
        {
            if (err) console.log(err);

            ps.execute({ publisherName: publisherName }, function (err, data) 
            {
                if (err) console.log(err);

                res.send(data.recordset);
                console.log('Books by publisher retrieved');
            });
        });
    });
});



// 4. Все студенты
app.get('/students', (req, res) => 
{
    var connection = new mssql.ConnectionPool(config);

    connection.connect(err => 
    {
        if (err) console.log(err);

        var ps = new mssql.PreparedStatement(connection);

        ps.prepare('SELECT * FROM dbo.Students', function (err) 
        {
            if (err) console.log(err);

            ps.execute({}, function (err, data) 
            {
                if (err) console.log(err);

                res.send(data.recordset);
                console.log('Students retrieved');
            });
        });
    });
});



// 5. Студенты конкретной группы ( через url)
app.get('/students/group/:groupName', (req, res) => 
{
    var groupName = req.params.groupName;
    var connection = new mssql.ConnectionPool(config);

    connection.connect(err => 
    {
        if (err) console.log(err);

        var ps = new mssql.PreparedStatement(connection);
        ps.input('groupName', mssql.NVarChar);

        ps.prepare('SELECT * FROM dbo.Students WHERE groupName = @groupName', function (err) 
        {
            if (err) console.log(err);

            ps.execute({ groupName: groupName }, function (err, data) 
            {
                if (err) console.log(err);

                res.send(data.recordset);
                console.log('Students by group retrieved');
            });
        });
    });
});



// 6. Все преподаватели
app.get('/teachers', (req, res) => 
{
    var connection = new mssql.ConnectionPool(config);

    connection.connect(err => 
    {
        if (err) console.log(err);

        var ps = new mssql.PreparedStatement(connection);

        ps.prepare('SELECT * FROM dbo.Teachers', function (err) 
        {
            if (err) console.log(err);

            ps.execute({}, function (err, data)
            {
                if (err) console.log(err);

                res.send(data.recordset);
                console.log('Teachers retrieved');
            });
        });
    });
});



// 7. Все факультеты
app.get('/faculties', (req, res) => 
{
    var connection = new mssql.ConnectionPool(config);

    connection.connect(err => 
    {
        if (err) console.log(err);

        var ps = new mssql.PreparedStatement(connection);

        ps.prepare('SELECT * FROM dbo.Faculties', function (err) 
        {
            if (err) console.log(err);

            ps.execute({}, function (err, data) 
            {
                if (err) console.log(err);

                res.send(data.recordset);
                console.log('Faculties retrieved');
            });
        });
    });
});




app.listen(port, function () { console.log('App listening on port ' + port); });
