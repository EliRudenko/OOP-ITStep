let dataArray1: number[] = [1, 2, 3];
let dataArray2: number[] = [100, 200, ...dataArray1]; // spread operator - добавляем элементы массива dataArray1 в конец массива dataArray2

console.log(dataArray2);

let point2D = { x: 10, y: 20 };
let point3D = { ...point2D, z: 30 }; // object spread - свойства объекта point2D добавляются к свойствам объекта point3D

console.log(point3D);

