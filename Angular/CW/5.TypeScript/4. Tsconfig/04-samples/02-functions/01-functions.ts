// обычная функция
function add1(x, y) {
    return x + y;
}

let result1 = add1(1, 2);
console.log(result1);

// типизированная функция. Принимает два аргумента типа number и возвращает значение типа number
function add2(x: number, y: number) :number {
    return x + y;
}

let result2: number = add2(10, 20);
//let result2: number = add2(10); // ожидается два параметра
//let result2: number = add2(10, "text"); // второй аргумент должен быть числовым
//let result2: string = add2(10, 20); // результат работы функции не может быть присвоен строковой переменной
console.log(result2);

