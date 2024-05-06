class Base {
    private value1: string;
    public value2: string;
    protected value3: string;

    constructor() {
        this.value1 = "private value 1";
        this.value2 = "public value 2";
        this.value3 = "protected value 3";
    }

    private method1() {
        console.log("private method 1 call.");
    }

    public method2() {
        console.log("public method 2 call.");
    }

    protected method3() {
        console.log("protected method 3 call.");
    }
}

class Derived extends Base { // класс Derived наследует класс Base, класс Derived расширяет класс Base

    constructor() {
        
        super(); // Вызов конструктора базового класса. Обязательная операция при наследовании. 

        console.log("public property = " + this.value2);
        console.log("protected property = " + this.value3);

        // this.method1(); // метод private, скрыт  
        this.method2();    // public - открыт для всех  
        this.method3();    // protected - доступен, так как данный класс является наследником
    }
}

let derived1: Derived = new Derived();

// доступен только метод method2, так как он public. Остальные методы не доступны так как данный код находится за пределами класса
derived1.method2(); 
console.log(derived1.value2);