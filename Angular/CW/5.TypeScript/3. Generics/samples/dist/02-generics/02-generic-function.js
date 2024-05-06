function writeLog(value) {
    //console.log(value.length); // свойство length не существует на типе Т
    // так как в качестве значения для типа Т может быть любой тип данных, компилятор проверяет
    // чтобы обращения к такому типу не привели к исключениям.
    // например у типа string свойствао length существует, а в типе number его нет
    return value;
}
// функция принимает массив типа Т
function writeLogArray1(value) {
    console.log(value.length); // массивы имеют свойство length
    return value;
}
function writeLogArray2(value) {
    console.log(value.length); // массивы имеют свойство length
    return value;
}
//# sourceMappingURL=02-generic-function.js.map