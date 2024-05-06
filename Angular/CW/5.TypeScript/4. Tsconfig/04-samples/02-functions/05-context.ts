// this - контекст функции. This - переменная, которая устанавливается при запуске функции.
function test1() {
    console.log(this);
}
test1(); // global object

let someObj = {
    name: 'test',
    testMeth: test1
};
someObj.testMeth(); // someObj

let someInstance = new test1(); // new instance

// Установка контекста вызываемой функции
function test2(x: number, y: number) {
    console.log(x + y);
    console.log(this)
}

let someTestObj = {
    name: "test object"
};

test2.call(someTestObj, 10, 20); // Установка контекста, вариант 1
test2.apply(someTestObj, [30, 40]); // установка контекста, вариант 2
let newFunc = test2.bind(someTestObj, 50); // установка контекста, вариант 3
newFunc(60);