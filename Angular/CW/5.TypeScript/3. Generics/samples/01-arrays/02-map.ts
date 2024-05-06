// map - обходит все элементы массива и возвращает новый массив со значениями, которые вернула указанная функция.

let array2: number[] = [1, 2, 3, 4, 5];

let array3: number[] = array2.map(function (value) {
    return value * value;
})

console.log(array2);
console.log(array3);