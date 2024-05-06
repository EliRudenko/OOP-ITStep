// параметр функции в начале имени которого используется ... является rest параметром.
// rest параметр - это набор опциональных параметров. При вызове такого метода, количество параметров не ограничивается.
// тип данной функции - (message:string, ...names: string[]) => void
function printValue(message: string, ...names: string[]) : void {
    console.log(message);
    for(let i = 0; i < names.length; i++) {
        console.log(names[i]);
    }
}

// вызов функции с rest параметрами
printValue("sample 1");
printValue("sample 2", "1", "2");
printValue("sample 3", "1", "2", "abc");