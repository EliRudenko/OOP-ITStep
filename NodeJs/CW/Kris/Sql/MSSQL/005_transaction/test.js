var express = require('express');
var mssql = require('mssql');

var app = express();
var port = 8080;
// параметры соединения с бд

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

app.get('/', function (req, res) 
{
	connection.connect(function (err) 
	{
		// транзакция - безопасная операция над бд с возможностью отката изменений в случае ошибки при выполнении запроса  
		var transaction = new mssql.Transaction(connection);

		transaction.begin(function (err) 
		{
			var request = new mssql.Request(transaction);
			//request.query("INSERT INTO logins (login, password) VALUES ('admin', 'admin')");
			request.query("INSERT INTO Groups (Name, Id_Faculty, Counts) VALUES ('КНП-221', '2', '13')", function (err, 
			data) 
			{

				if (err) 
				{
					console.log(err);
					transaction.rollback(function (err) 
					{
						console.log('rollback successful');
					});
				} 
				else 
				{
					transaction.commit(function (err, data) 
					{
							console.log('data commit success');
							res.send('transaction successful');
					});
				};
			});
		});
	});
});

// демонстрация отката изменений в случае ошибки при выполнении запроса к бд 

app.get('/error', function (req, res) 
{
	var transaction = new mssql.Transaction(connection);

	transaction.begin(function (err) 
	{
		var request = new mssql.Request(transaction);
		request.query("bad sql", function (err, data) 
		{
			if (err) 
			{
				console.log(err);
				transaction.rollback(function (err) {

					if (err) 
					{
						console.log('rollback error');
					}
					else 
					{
						console.log('rollback successful');
						res.send('transaction rollback successful');
					}
				});
			} 
			else 
			{
				transaction.commit(function (err, data) 
				{
					if (err) 
					{
						console.log('could not commit data');
					}
					else 
					{
						console.log('data commit success');
						res.send('transaction successful');
					};
				});
			};
		});
	});
});

app.listen(port, function () 
{
	console.log('app listening on port ' + port);

}); 
