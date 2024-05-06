// при создании переменной можно указать тип данных определяющий сигнатуру функции.
// параметры => возвращаемый тип
let myAdd: (x: number, y: number) => number; // принимает два параметра типа number возвращает значение number
let myProc: () => void; // переменной может быть присвоена функция, которая ничего не принимает и не возвращает значений

function myAddDeclaration(x: number, y: number) : number {
    return x + y;
}

myAdd = myAddDeclaration;
console.log(myAdd(10, 20)); // вызов функции

myProc = function() {
    console.log("Hello world");
}
myProc(); // вызов функции