class Point {
    public x: number;
    public y: number;

    constructor(x: number, y: number) {
        this.x = x;
        this.y = y;
    }
}

class Grid {
    public points: Point[] = [];
    public static origin: Point = { x: 0, y: 0 }; // Статическое свойство. Общее для всех экземпляров

    add(point: Point) {
        this.points.push(point);
    }

    buildGrid() {
        for (let i = 0; i < this.points.length; i++) {
            console.log(this.points[i]);
        }
    }
}

let grid1: Grid = new Grid();

grid1.add(Grid.origin);

grid1.add(new Point(1, 2));
grid1.add(new Point(10, 20));
grid1.add(new Point(12, 24));

grid1.buildGrid();

let grid2: Grid = new Grid();

grid2.add(Grid.origin);

grid2.add(new Point(6, 2));
grid2.add(new Point(7, 2));
grid2.add(new Point(1, 24));

grid2.buildGrid();
