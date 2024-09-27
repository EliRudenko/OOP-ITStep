var mssql = require('mssql');

// параметры соединения с бд
// параметры соединения с бд
var config = 
{
    server: 'Elin-TUF\\ELI',
    database: 'testdb',

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
var pool = connection.connect(function(err) {
	if (err) console.log(err)
}); 

module.exports = pool; 