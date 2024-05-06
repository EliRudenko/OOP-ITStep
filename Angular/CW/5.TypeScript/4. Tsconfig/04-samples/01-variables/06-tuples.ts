// Кортеж - упорядоченный набор фиксированной длины.
let x: [string, number]; // определение кортежа
x = ["Hello", 10]; // инициализация кортежа

console.log(x); // (2) ["Hello", 10]
console.log(x[0]); // Hello
console.log(x[1]); // 10

let y: [number, string, string] = [1, "hello", "world"]; // кортеж на три значения.
console.log(y[2]);

//y[0].substr(1); // [ts] Propery substr does not exist on type 'number'