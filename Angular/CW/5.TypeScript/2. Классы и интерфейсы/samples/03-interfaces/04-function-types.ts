// интерфейс описывает сигнатуру функции, функция должна принимать одно строковое значение и возвращать boolean
interface Searchable {
    (value: string) : boolean;
}

let myArray1: Searchable = function (value: string) : boolean {
    return false;
}

// имена параметров не обязательно должны совпадать с именами в интерфейсе
let myArray2: Searchable = function (data: string) : boolean {
    return false;
}