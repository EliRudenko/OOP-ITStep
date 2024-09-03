function User(name)
{//функция  КОНСТРУКТОР
    this.name = name;
    this.sayHello = () => { console.log('Hello ', this.name); };
}

var Jhon = new User('Jhon');

Jhon.sayHello();