// базовый тип данных
class Shape {
    public name: string;

    constructor(name) {
        this.name = name;
    }

    public getInfo(): string {
        return `This is ${this.name}.`;
    }
}

// производный тип данных
class Rect extends Shape {
    public width: number;
    public height: number;

    constructor(width: number, height: number) {
        super("Rectangle"); // запуск конструктора родительского класса
        this.width = width;
        this.height = height;
    }

    public getInfo(): string {
        let baseInfo: string = super.getInfo(); // вызов метода родительского класса
        return `${baseInfo} Height = ${this.height}, Width = ${this.width}`;
    }
}

// производный тип данных
class Circle extends Shape {
    public radius: number;

    constructor(radius: number) {
        super("Circle");
        this.radius = radius;
    }

    public getInfo(): string {
        let baseInfo: string = super.getInfo();
        return `${baseInfo} Radius = ${this.radius}`;
    }
}

let shapes: Shape[] = []; // создание массива базового типа
shapes.push(new Rect(100, 200)); // заполнение массива экземплярами производного класса
shapes.push(new Circle(10));
shapes.push(new Circle(43));
shapes.push(new Rect(10, 30));

// в массив shapes можно добавлять только объекты имеющие идентичную с классом Shape структуру
shapes.push({
    name: "foo",
    getInfo: () => { return "bar"}
});

for(let i = 0; i < shapes.length; ++i) {
    let info: string = shapes[i].getInfo();
    console.log(info);
}