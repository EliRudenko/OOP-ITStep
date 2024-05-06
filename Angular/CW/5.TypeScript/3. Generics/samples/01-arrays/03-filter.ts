// filter - возвращает новый массив состоящий из элементов отобраных функцией.

let array4: number[] = [1, 2, 3, 4, 5, 6];

var array5 = array4.filter(value => value % 2 == 0); // получить все четные элементы

console.log(array4);
console.log(array5);