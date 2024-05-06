// abstract - ключевое слово, которое позволяет создавать абстрактные методы и абстрактные классы.
// абстрактный класс - это класс, который может выступать только в роли базового класса. Создать экземпляр абстрактного класса не получится.
// абстрактный метод - это метод, который не имеет реализации в текущем классе но обязательно должен быть реализован в производном классе.
// абстрактные методы могут создаваться только в абстрактных классах.

abstract class Animal { // абстрактный класс
    constructor(public name: string) { }

    abstract makeSound(); // абстрактный метод

    public move(): void {

        console.log(this.name + " передвигается")
    }
}

class Cat extends Animal {
    constructor() {
        super("Кот");
    }

    makeSound() { // обязательная реализация абстрактного метода из базового класса. Попробуйте удалить этот метод из класса Cat
        console.log("Мяу-Мяу");
    }
}

class Cow extends Animal {
    constructor() {
        super("Корова");
    }
    makeSound() {
        console.log("Му-у-у-у");
    }
}

let murzik: Cat = new Cat();
murzik.makeSound();
murzik.move();

let burenka: Cow = new Cow();
burenka.makeSound();
burenka.move();

let Base: Animal = new Cat();



