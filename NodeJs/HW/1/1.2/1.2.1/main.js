const Point = require('./Point');

const point1 = new Point(1, 2);
const point2 = new Point(1, 5);

console.log(Point.isParallelToAxis(point1, point2));
