class Rectangle {
    private _width: number;
    private _height: number;

    // метод для получения значения закрытого свойства
    public getWidth(): number {
        return this._width;
    }

    // метод для установки значения закрытому свойству
    public setWidth(value: number): void {
        if (value <= 0) {
            this._width = 1;
        }
        else {
            this._width = value;
        }
    }

    // accessors - механизм, который позволяет перехватить обращение к члену объекта на запись или чтение.

    // getter 
    get height(): number {
        return this._height;
    }

    // setter
    set height(value: number) {
        if (value <= 0) {
            this._height = 1;
        }
        else {
            this._height = value;
        }
    }

    public calculateArea(): number {
        return this._width * this._height;
    }
}

let rect1: Rectangle = new Rectangle();
rect1.setWidth(100); // установка ширины с помощью метода
rect1.height = (-20); // установка высоты с помощью setter. Запускается метод set на строке 28, значение 20 передается в качестве параметра

console.log(rect1.getWidth()); // чтение значение закрытого свойства с помощью метода
console.log(rect1.height); // чтение значение закрытого свойства с помощью аксесора. Тут вызывается метод get со строки 23

let rectArea: number = rect1.calculateArea();
console.log(rectArea);


