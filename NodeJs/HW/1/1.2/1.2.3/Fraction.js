class Fraction 
{
    constructor(numerator, denominator) 
    {
        this.numerator = numerator;
        this.denominator = denominator;
    }

    add(fraction) 
    {
        const numerator = this.numerator * fraction.denominator + fraction.numerator * this.denominator;
        const denominator = this.denominator * fraction.denominator;
        return new Fraction(numerator, denominator);
    }
    subtract(fraction) 
    {
        const numerator = this.numerator * fraction.denominator - fraction.numerator * this.denominator;
        const denominator = this.denominator * fraction.denominator;
        return new Fraction(numerator, denominator);
    }

    multiply(fraction) 
    {
        const numerator = this.numerator * fraction.numerator;
        const denominator = this.denominator * fraction.denominator;
        return new Fraction(numerator, denominator);
    }
    divide(fraction) 
    {
        const numerator = this.numerator * fraction.denominator;
        const denominator = this.denominator * fraction.numerator;
        return new Fraction(numerator, denominator);
    }

    print() { console.log(`${this.numerator}/${this.denominator}`); }
    
}

module.exports = Fraction;
