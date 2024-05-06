let year: string[]; // массив строковых значений
year = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

// [ts] type ('string | number)[] is not assignable to type string[]
//year = [1, "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

let list: number[] = [1, 2, 3]; // определение числового массива и его инициализация
for(let i = 0; i < list.length; i++) {
    console.log(list[i]);
}

let values: Array<number> = [-1, -2, -3]; // создание массива используя generic тип данных Array
for(let i = 0; i < values.length; i++) {
    console.log(values[i]);
}