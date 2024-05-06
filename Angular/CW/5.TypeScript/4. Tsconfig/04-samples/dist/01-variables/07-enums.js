// enum - перечисление, тип данных, который позволяет набору целочисленных значений присвоить имена.
// по умолчанию перечисления нумеруют свои элементы начиная с 0
// Red = 0, Green = 1, Blue = 2
var Color;
// enum - перечисление, тип данных, который позволяет набору целочисленных значений присвоить имена.
// по умолчанию перечисления нумеруют свои элементы начиная с 0
// Red = 0, Green = 1, Blue = 2
(function (Color) {
    Color[Color["Red"] = 0] = "Red";
    Color[Color["Green"] = 1] = "Green";
    Color[Color["Blue"] = 2] = "Blue";
})(Color || (Color = {}));
let c1 = Color.Green;
console.log(c1);
// каждому элементу перечисления явно устанавливается значение
var Status;
// каждому элементу перечисления явно устанавливается значение
(function (Status) {
    Status[Status["Success"] = 1] = "Success";
    Status[Status["Error"] = 5] = "Error";
    Status[Status["Rejected"] = 10] = "Rejected";
})(Status || (Status = {}));
let c2 = Status.Success;
console.log(c2);
// так как первому элементу явно установлено значение 2, все последующие будут продолжать нумерацию с 2
// Circle = 2, Triangle = 3, Square = 4
var Shape;
// так как первому элементу явно установлено значение 2, все последующие будут продолжать нумерацию с 2
// Circle = 2, Triangle = 3, Square = 4
(function (Shape) {
    Shape[Shape["Circle"] = 2] = "Circle";
    Shape[Shape["Triangle"] = 3] = "Triangle";
    Shape[Shape["Square"] = 4] = "Square";
})(Shape || (Shape = {}));
let c3 = Shape.Square;
console.log(c3);
let c4 = Status[1]; // обращаясь к перечислению через индексатор и указывая целочисленное значение можно получить строковое представление этого значения
console.log(c4);
///////////////////////////////////////////////////////////////////////
// Пример использования перечислений
///////////////////////////////////////////////////////////////////////
var Fruit;
///////////////////////////////////////////////////////////////////////
// Пример использования перечислений
///////////////////////////////////////////////////////////////////////
(function (Fruit) {
    Fruit[Fruit["Apple"] = 0] = "Apple";
    Fruit[Fruit["Orange"] = 1] = "Orange";
    Fruit[Fruit["Tomato"] = 2] = "Tomato";
})(Fruit || (Fruit = {}));
function drawImage1(fruit) {
    let domElement = document.createElement("img");
    switch (fruit) {
        case 0:
            domElement.src = "/images/apple.jpg";
            break;
        case 1:
            domElement.src = "/images/orange.jpg";
            break;
        case 2:
            domElement.src = "/images/tomato.jpg";
            break;
    }
    document.body.appendChild(domElement);
}
function drawImage2(fruit) {
    let domElement = document.createElement("img");
    switch (fruit) {
        case Fruit.Apple:
            domElement.src = "/images/apple.jpg";
            break;
        case Fruit.Orange:
            domElement.src = "/images/orange.jpg";
            break;
        case Fruit.Tomato:
            domElement.src = "/images/tomato.jpg";
            break;
    }
    document.body.appendChild(domElement);
}
drawImage1(0); // создать изображение с яблоком (не очевидно)
drawImage2(Fruit.Orange); // создать изображение апельсина (код  самодокументируемый)
//# sourceMappingURL=07-enums.js.map