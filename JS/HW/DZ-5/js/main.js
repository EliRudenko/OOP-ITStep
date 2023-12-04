var Car = window.Car; // Импортируем Car из глобалки((( Это ужас

var Car_model = new Car('Volkswagen', 'Beetle', 2018, 90);

Car_model.displayInfo();

var distance = 500;
var travelTime = Car_model.calculateTravelTime(distance);
console.log('To overcome the distance ' + distance + ' km required ' + travelTime + ' hours.');
