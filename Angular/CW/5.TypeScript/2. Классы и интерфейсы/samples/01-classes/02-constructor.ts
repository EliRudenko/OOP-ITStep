class MyClass1 {
    value: string;

    // определение конструктора для инициализации класса
    constructor()
     {
        console.log("Работает конструктор класса MyClass1");
        this.value = "Hello world";
    }
}

console.log("Создание экземпляра класса MyClass1")
let temp = new MyClass1(); // вызов конструктора, определенного на строке 5
console.log(temp.value);