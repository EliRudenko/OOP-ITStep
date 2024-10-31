using System;

public struct ComplexNumber
{
    public double Real { get; set; }    
    public double Imaginary { get; set; } 

    public ComplexNumber(double real, double imaginary)
    {
        Real = real;
        Imaginary = imaginary;
    }
    public ComplexNumber Add(ComplexNumber other)
    {
        return new ComplexNumber(Real + other.Real, Imaginary + other.Imaginary);
    }
    public ComplexNumber Subtract(ComplexNumber other)
    {
        return new ComplexNumber(Real - other.Real, Imaginary - other.Imaginary);
    }
    public ComplexNumber Multiply(ComplexNumber other)
    {
        double realPart = Real * other.Real - Imaginary * other.Imaginary;
        double imaginaryPart = Real * other.Imaginary + Imaginary * other.Real;
        return new ComplexNumber(realPart, imaginaryPart);
    }
    public ComplexNumber Divide(ComplexNumber other)
    {
        double denominator = other.Real * other.Real + other.Imaginary * other.Imaginary;
        double realPart = (Real * other.Real + Imaginary * other.Imaginary) / denominator;
        double imaginaryPart = (Imaginary * other.Real - Real * other.Imaginary) / denominator;
        return new ComplexNumber(realPart, imaginaryPart);
    }

    public override string ToString()
    {
        return $"{Real} + {Imaginary}i";
    }
}

class Program
{
    static void Main()
    {
        ComplexNumber num1 = new ComplexNumber(3, 4); 
        ComplexNumber num2 = new ComplexNumber(1, 2);

        Console.WriteLine("Первое число: " + num1);
        Console.WriteLine("Второе число: " + num2);

        Console.WriteLine("\nСложение: " + num1.Add(num2));
        Console.WriteLine("Вычитание: " + num1.Subtract(num2));
        Console.WriteLine("Умножение: " + num1.Multiply(num2));
        Console.WriteLine("Деление: " + num1.Divide(num2));
    }
}
