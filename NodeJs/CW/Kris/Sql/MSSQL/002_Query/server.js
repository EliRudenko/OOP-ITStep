var express  = require('express'); 
var app = express(); 

var port = 8080; 
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

mssql.connect(config, err => 
{
  if (err) {
    console.error('Error connecting to the database:', err);
  } else {
    console.log('Connected to the database');

    const request = new mssql.Request();

    request.query('SELECT * FROM items', (err, result) => {
      if (err) {
        console.error('Error executing query:', err);
      } else {
        console.log(result.recordset);
      }
    });
  }
});

app.listen(port, function() { 
  console.log('App listening on port ' + port); 
});
