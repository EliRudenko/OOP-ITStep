class Student 
{
    constructor(name, id) 
    {
        this.name = name;
        this.id = id;
    }

    printInfo() { console.log(`Студент: ${this.name}, ID: ${this.id}`); }
}

module.exports = Student;
