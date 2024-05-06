class Person {
    // Если при определении параметров в конструкторе указать для них модификаторы доступа
    // Эти параметры автоматически станут полями класса с соответствующим уровнем доступа
    // и значениями, которые будут установлены при вызове конструктора.
    constructor(public name: string, private age: number) {

    }

    print() {
        console.log(this.name + " " + this.age);
    }
}

let person: Person = new Person("Jhon", 25);
person.print();

person.name = "111"; // поле public
person.print();
