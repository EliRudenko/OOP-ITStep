class Employee {
    public name: string; // модификатор доступа public - указывает что поле, видимое за пределами данного класса 
    position: string; // по умолчанию public
    private company: string; // модификатор доступа private - указывает что данное поле закрытое и не доступно за пределами класса

    constructor(name: string, position: string) {
        this.name = name;
        this.position = position;
        this.company = "Step";
    }

    printToConsole() {
        console.log(`Employee ${this.name}, position - ${this.position}, company - ${this.company}`);
    }
}

let emp1: Employee = new Employee("Ivan", "Developer");
emp1.name = "John";
emp1.position = "Team Lead";
//emp1.company = "..."; // [ts] Property 'company' is private and only accessible within class 'Employee'

emp1.printToConsole();