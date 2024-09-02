const Fraction = require('./Fraction');

const fraction1 = new Fraction(8, 11);
const fraction2 = new Fraction(5, 7);

const sum = fraction1.add(fraction2);
sum.print();

const difference = fraction1.subtract(fraction2);
difference.print();

const product = fraction1.multiply(fraction2);
product.print();

const quotient = fraction1.divide(fraction2);
quotient.print();
