interface PointInterface {
    readonly x: number; // readonly свойство может быть установленно только в момент создания объекта
    readonly y: number;
}

let point: PointInterface = {x: 10, y: 20};
//point.x = 100; // ошибка