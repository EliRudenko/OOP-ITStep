// с помощью ключевого слова readonly можно создать поля только на чтение.
// Такое поле может быть инициализировано в момент его создания или в конструкторе 
class Dog {
    public readonly name: string;
    public readonly numberOfLegs: number = 4;

    constructor(name: string) {
        this.name = name;
    }
}

let dog: Dog = new Dog("Sharik");
console.log(dog.name);
console.log(dog.numberOfLegs);
//dog.numberOfLegs = 5; // [ts] cannot assign to 'numberOfLags' because it is a constant or read-only property
//dog.name = "";