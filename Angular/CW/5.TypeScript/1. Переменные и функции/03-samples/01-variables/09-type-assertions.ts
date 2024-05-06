// Type assertion - утверждение типов, это операция, которая напоминает приведение типов в других языках программирования.
// С помощью утверждения типов можно подсказать компилятору, конкретный тип с которым мы сейчас работаем. 

let someData: any = "Hello world";
let strLength1: number = (<string>someData).length; // утверждение, что значение someData является типом string использование синтаксиса "angle-bracket"
let strLength2: number = (someData as string).length; // // утверждение, что значение someData является типом string использование синтаксиса "as"
