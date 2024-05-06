// тип данных void - тип данных указывающий на отсутствие какого-либо значения.
// используется для того чтобы при определении функция явно указать на отсутствие возвращаемого значения.
function myProcedure() {
    alert("hello");
}
// тип void можно использовать для определения переменных, но такой переменной можно присвоить только значение undefined или null
let someVoidVal = undefined;
let u = undefined; // переменная типа undefined
let n = null; // переменная типа null
// по умолчанию значения null и undefined могут быть присвоены любому другому типу данных
// при опции компилятора --strictNullChecks null и undefined могут быть использованы для инициализации типов void или null и undefined соответственно
let testNumber = undefined;
//# sourceMappingURL=09-void.js.map