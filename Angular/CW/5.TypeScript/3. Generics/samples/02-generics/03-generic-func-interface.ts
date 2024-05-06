// интерфейс описывает generic функцию, которая принимает один параметр и возвращает значение такого же как параметр типа
interface GenericFunc {
    <T>(arg: T): T
}

function testFunc<T>(arg: T) : T {
    return arg;
}

let myGenericFunc : GenericFunc = testFunc;

myGenericFunc(10)