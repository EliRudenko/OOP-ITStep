// данный интерфейс будет реализован классом, который содержит данные, которые можно извлечь.
// коллекция данных
interface MyIterable<T> {
    values(): MyIterator<T>
}

// данный интерфейс описывает объект, контролирующий обход данных в коллекции
interface MyIterator<T> {
    next(): MyIteratorResult<T>;
}

// данный интерфейс описывает объект, определяющий результаты работы итератора
interface MyIteratorResult<T> {
    done: boolean;
    value: T;
}

class Point {
    constructor(public x: number, public y: number) { }
}

// коллекция
class Vector implements MyIterable<Point> {

    private points: Point[] = [];

    public add(item: Point) {
        this.points.push(item);
    }

    values() {
        return new VectorIterator(this.points);
    }
}

// итератор для коллекции Vector
class VectorIterator implements MyIterator<Point> {

    private current: number = 0;

    constructor(private points: Point[]) { }

    public next(): MyIteratorResult<Point> {
        if (this.current < this.points.length) {
            return {
                done: false,
                value: this.points[this.current++]
            };
        }
        else {
            return {
                done: true,
                value: null
            };
        }
    }
}

let vector: Vector = new Vector();
vector.add(new Point(10, 20));
vector.add(new Point(1, 30));
vector.add(new Point(0, 2));
vector.add(new Point(15, 12));

// использование итератора
let iterator = vector.values();
let next = iterator.next();

while (!next.done) {
    console.log(next.value);
    next = iterator.next();
}