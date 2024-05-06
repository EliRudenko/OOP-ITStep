let array1 = [1, 2, 3, 4, 5, 6, 7, 8, 9];
let sum = 0;
// forEach - обход всех элементов массива и запуск определенной функции для значения каждого элемента.
array1.forEach(value => sum += value);
console.log("sum " + sum);
// увеличение каждого элемена массива на 1
array1.forEach((value, index, array) => {
    array[index] = value + 1;
});
console.log(array1);
//# sourceMappingURL=01-foreach.js.map