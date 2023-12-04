//1
function Car(manufacturer, model, year, averageSpeed) 
{
    this.manufacturer = manufacturer;
    this.model = model;
    this.year = year;
    this.averageSpeed = averageSpeed;
}

Car.prototype.displayInfo = function() 
{
    console.log('Automobile: ' + this.manufacturer + ' ' + this.model + ', ' + this.year + ' year of release. Average speed: ' + this.averageSpeed + ' km/h');
};

Car.prototype.calculateTravelTime = function(distance) 
{
    var timeWithoutBreaks = distance / this.averageSpeed;
    var numberOfBreaks = Math.floor(timeWithoutBreaks / 4);
    var timeWithBreaks = timeWithoutBreaks + numberOfBreaks;
    return timeWithBreaks;
};

window.Car = Car; // Экспортируем Car в глобалку(((



//2
function Calculation(numerator, denominator) 
{
    this.numerator = numerator;
    this.denominator = denominator;
}

Calculation.prototype.add = function(otherFraction) 
{
    const resultNumerator = this.numerator * otherFraction.denominator + otherFraction.numerator * this.denominator;
    const resultDenominator = this.denominator * otherFraction.denominator;
    return new Calculation(resultNumerator, resultDenominator);
};

Calculation.prototype.subtract = function(otherFraction) 
{
    const resultNumerator = this.numerator * otherFraction.denominator - otherFraction.numerator * this.denominator;
    const resultDenominator = this.denominator * otherFraction.denominator;
    return new Calculation(resultNumerator, resultDenominator);
};

Calculation.prototype.multiply = function(otherFraction) 
{
    const resultNumerator = this.numerator * otherFraction.numerator;
    const resultDenominator = this.denominator * otherFraction.denominator;
    return new Calculation(resultNumerator, resultDenominator);
};

Calculation.prototype.divide = function(otherFraction) 
{
    const resultNumerator = this.numerator * otherFraction.denominator;
    const resultDenominator = this.denominator * otherFraction.numerator;
    return new Calculation(resultNumerator, resultDenominator);
};

Calculation.prototype.reduce = function() 
{
    const gcd = (a, b) => 
    {
        if (b === 0) { return a; }
        return gcd(b, a % b);
    };

    const commonDivisor = gcd(this.numerator, this.denominator);
    const reducedNumerator = this.numerator / commonDivisor;
    const reducedDenominator = this.denominator / commonDivisor;

    return new Calculation(reducedNumerator, reducedDenominator);
};

const Calculation1 = new Calculation(1, 2);
const Calculation2 = new Calculation(1, 3);

const sum = Calculation1.add(Calculation2);
console.log('Sum:', sum.numerator + '/' + sum.denominator);

const difference = Calculation1.subtract(Calculation2);
console.log('Difference:', difference.numerator + '/' + difference.denominator);

const product = Calculation1.multiply(Calculation2);
console.log('Product:', product.numerator + '/' + product.denominator);

const quotient = Calculation1.divide(Calculation2);
console.log('Quotient:', quotient.numerator + '/' + quotient.denominator);

const reducedFraction = Calculation1.reduce();
console.log('Reduced Fraction:', reducedFraction.numerator + '/' + reducedFraction.denominator);


//3
function Time(hours, minutes, seconds) 
{
    this.hours = hours;
    this.minutes = minutes;
    this.seconds = seconds;
}

Time.prototype.displayTime = function() 
{
    const formatDigit = (digit) => (digit < 10 ? '0' + digit : digit);  //добавить 0
    console.log(`${formatDigit(this.hours)}:${formatDigit(this.minutes)}:${formatDigit(this.seconds)}`);
};

Time.prototype.changeSeconds = function(seconds) 
{
    this.seconds += seconds;
    this.minutes += Math.floor(this.seconds / 60);
    this.seconds %= 60;
    this.hours += Math.floor(this.minutes / 60);
    this.minutes %= 60;
    this.hours %= 24;
};

Time.prototype.changeMinutes = function(minutes) 
{
    this.minutes += minutes;
    this.hours += Math.floor(this.minutes / 60);
    this.minutes %= 60;
    this.hours %= 24;
};

Time.prototype.changeHours = function(hours) 
{
    this.hours += hours;
    this.hours %= 24;
};

const Time_calcul = new Time(18, 20, 35);
Time_calcul.displayTime();

Time_calcul.changeSeconds(30); 
Time_calcul.displayTime(); 

Time_calcul.changeMinutes(5);
Time_calcul.displayTime();

Time_calcul.changeHours(2);
Time_calcul.displayTime(); 
