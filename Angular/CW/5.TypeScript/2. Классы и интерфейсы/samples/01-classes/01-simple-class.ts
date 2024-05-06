class User {
    firstName: string; // свойство 
    lastName: string;  // свойство

    print(): void {   // метод
        console.log(this.firstName + " " + this.lastName);
    }
}
class Person extends User {
    age: number;

    print(): void {   // метод
        super.print();
        console.log(this.firstName + " " + this.lastName);
    }
}

let user1: User = new User(); // создаем экземпляр класса User вызывая конструктор и инициализируем переменную user1
user1.firstName = "Ivan";     // присвоение значения свойству firstName на экземпляре user1
user1.lastName = "Ivanov";

let user2: User = new User(); // создаем экземпляр класса User вызывая конструктор и инициализируем переменную user2
user2.firstName = "John";     // присвоение значения свойству firstName на экземпляре user2
user2.lastName = "Doe";

user1.print(); // вызов метода print на экземпляре user1
user2.print(); // вызов метода print на экземпляре user2