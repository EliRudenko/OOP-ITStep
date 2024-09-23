var express = require('express');
var mssql = require('mssql');
var path = require('path');
var app = express();
var port = 8080;

// параметры соединения с БД
var config = 
{
    server: 'Elin-TUF\\ELI',
    database: 'Library',

    user: 'admin',
    password: 'admin',

    options: 
    {
        encrypt: true,
        trustServerCertificate: true
    },
    port: 1433
};

var connection = new mssql.ConnectionPool(config);

app.use('/styles', express.static(path.join(__dirname, 'styles')));

app.get('/', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'index.html'));
});


app.get('/faculties.html', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'faculties.html'));
});

app.get('/groups.html', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'groups.html'));
});

app.get('/students.html', (req, res) => 
{
    res.sendFile(path.join(__dirname, 'data', 'students.html'));
});


app.post('/addFaculty', (req, res) => 
{
    connection.connect(err => 
    {
        if (err) 
        {
            console.error('Error connecting to the database:', err);
            return res.status(500).send('Database connection error');
        }

        var transaction = new mssql.Transaction(connection);
        transaction.begin(err => 
        {
            if (err) 
            {
                console.error('Transaction begin error:', err);
                return res.status(500).send('Transaction error');
            }

            var request = new mssql.Request(transaction);
            request.query("INSERT INTO Faculties (Name) VALUES ('New Faculty')", (err, data) => 
            {
                if (err) 
                {
                    console.error('Query error:', err);
                    transaction.rollback(err => 
                    {
                        if (err) 
                        {
                            console.error('Rollback error:', err);
                        }
                        console.log('Transaction rolled back');
                        res.status(500).send('Error while adding faculty, rollback performed');
                    });
                } 
                else 
                {
                    transaction.commit(err => 
                    {
                        if (err) 
                        {
                            console.error('Commit error:', err);
                        }
                        console.log('Transaction committed');
                        res.send('Faculty added successfully');
                    });
                }
            });
        });
    });
});

app.listen(port, () => 
{
    console.log('Server listening on port ' + port);
});
