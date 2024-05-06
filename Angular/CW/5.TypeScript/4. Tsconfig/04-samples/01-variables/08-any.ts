// При создании переменой тип которой не известен во время написания приложения можно использовать
// тип данных any. Такой тип удобно применять в ситуациях, когда значение вводиться пользователем или 
// получается в результате работы другой библиотеки. Такой тип данных не проходит проверку во время компиляции.

let someValue: any = "Hello world"; // string
someValue = false; // boolean
someValue = 100; // number
console.log(someValue); // 100

someValue.toFixed(); // ok
someValue = "test";
someValue.toFixed(); // Ошибка на этапе выполнения - TypeError: someValue.toFixed is not a Function