var mssql = require('mssql');

// параметры соединения с бд
var config = {
	server: 'Elin-TUF\\ELI',  // Имя сервера, как показано на скриншоте
	database: 'testdb',       // Имя базы данных
	user: 'admin',            // Пользователь
	password: 'admin',        // Пароль
	options: {
		  encrypt: true,               // Использование SSL/TLS
		  trustServerCertificate: true // Отключение проверки сертификата
	  },
	port: 1433,
					   // Порт, на котором работает SQL Server
  }
var connection = new mssql.Connection(config); 
var pool = connection.connect(function(err) {
	if (err) console.log(err)
}); 

module.exports = pool; 