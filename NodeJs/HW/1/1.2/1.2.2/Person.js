class Person 
{
    constructor(name, age, job) 
    {
        this.name = name;
        this.age = age;
        this.job = job;
    }

    static createPerson(name, age, job) { return new Person(name, age, job); }

    printInfo() 
    {
        console.log(`Имя: ${this.name}, Возраст: ${this.age}, Работа: ${this.job}`);
    }
}

module.exports = Person;
