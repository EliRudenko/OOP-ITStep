// every - функция вовращает true если все элементы удовлетворяют условие.
// some - функция вовращает true если хотя бы один элемент удовлетворяет условие.
let data1 = [1, 2, 3, 4, 5, 6];
let data2 = [11, 21, 31, 41];
let data3 = [1, 3, 5, 7, 9];
let data4 = [1, 3, 5, 7, 8, 9];
let res1 = data1.every(value => value > 10);
let res2 = data2.every(value => value > 10);
let res3 = data3.some(value => value % 2 == 0);
let res4 = data4.some(value => value % 2 == 0);
console.log(res1);
console.log(res2);
console.log(res3);
console.log(res4);
//# sourceMappingURL=04-every-some.js.map