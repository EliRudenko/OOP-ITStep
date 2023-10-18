#include <iostream>


class Fraction
{
private:
	//по умолчанию приват
	//РЕАЛИЗАЦИЯ => инкапсулированная часть класса
	//ПОЛЯ КЛАССА, то из чего состоит
	int numeratorand;
	int denominator;

public:
	//Интерфейсная часть, система управления
	// МЕТОДЫ класса

	void Print()
	{
		std::cout << numeratorand << "/" << denominator;

	}

	void Init_rand(int min_r, int max_r)
	{
		numeratorand = min_r + rand() % (max_r - min_r + 1);
		denominator = min_r + rand() % (max_r - min_r + 1);
		//std::cout << numeratorand << " / " << denominator << std::endl;
		//std::cout << "Simplified fraction: ";
		simplify(); // утрощение дроби для того что бы потом был "красивый" ответ
	}

	void Init_manual(int numer_manua, int denom_manua)
	{
		numeratorand = numer_manua;
		denominator = denom_manua;
		//std::cout << numeratorand << " / " << denominator << std::endl;
		//std::cout << "Simplified fraction: ";
		simplify(); // утрощение дроби для того что бы потом был "красивый" ответ
	}


	int gcd(int x, int y) 
	{ // НОД, для правильного подсчета
		while (y != 0) 
		{
			int temp = y;
			y = x % y;
			x = temp;
		}
		return x;
	}

	int lcm(int x, int y) { return (x * y) / gcd(x, y); } // НОК, для правильного подсчета

	void simplify() 
	{// упращение, для "красивого" ответа
		int matches = gcd(numeratorand, denominator);
		numeratorand /= matches;
		denominator /= matches;
	}


	// СЛОЖЕНИЕ
	Fraction summa(Fraction sum) 
	{
		int matches_denominator = lcm(denominator, sum.denominator);
		int new_numerator1 = numeratorand * (matches_denominator / denominator);
		int new_numerator2 = sum.numeratorand * (matches_denominator / sum.denominator);
		Fraction result;
		result.numeratorand = new_numerator1 + new_numerator2;
		result.denominator = matches_denominator;
		return result;
	}

	// ВЫЧИТАНИЕ
	Fraction subtract(Fraction subtr) 
	{
		int matches_denominator = lcm(denominator, subtr.denominator);
		int new_numerator1 = numeratorand * (matches_denominator / denominator);
		int new_numerator2 = subtr.numeratorand * (matches_denominator / subtr.denominator);
		Fraction result;
		result.numeratorand = new_numerator1 - new_numerator2;
		result.denominator = matches_denominator;
		return result;
	}

	// УМНОЖЕНИЕ
	Fraction multiply(Fraction mult)
	{
		Fraction result;
		result.numeratorand = numeratorand * mult.numeratorand;
		result.denominator = denominator * mult.denominator;
		return result;
	}

	// ДЕЛЕНИЕ
	Fraction divide(Fraction div) 
	{
		Fraction result;
		if (div.numeratorand == 0) 
		{// НА 0 НЕ ДЕЛИТСЯ
			std::cout << "Error entering denominator! " << std::endl;
			result.numeratorand = 0;
			result.denominator = 0;
		}
		else
		{
			result.numeratorand = numeratorand * div.denominator;
			result.denominator = denominator * div.numeratorand;
		}
		return result;
	}

	
	/*
	void Set_numeratorand(int numer){ numer = numeratorand; }
	void Set_denominator(int denom) { denom = denominator;  }

	int Get_numeratorand() { return numeratorand; }
	int Get_denominator() { return denominator; }
	*/
	
};



int main()
{

	srand(time(NULL));
	int min_r = 1;
	int max_r = 15;
	int choice_entry;
	int choice_operate;

	Fraction num1;
	Fraction num2;
	Fraction result;

	std::cout << "Select data entry:" << std::endl;
	std::cout << "1. Random generation of fractions"<< std::endl;
	std::cout << "2. Manual keyboard entry" << std::endl;
	std::cout << std::endl;
	std::cout << "Your choice: ";
	std::cin >> choice_entry;
	std::cin.ignore();  // Очистка буфера
	std::cout << std::endl;


	switch (choice_entry)
	{
	case 1:
		std::cout << "Fraction 1: ";
		num1.Init_rand(min_r, max_r);
		num1.Print();
		std::cout << std::endl;
		std::cout << "Fraction 2: ";
		num2.Init_rand(min_r, max_r);
		num2.Print();
		std::cout << std::endl;
		break;
	case 2:

		int numer_manua, denom_manua;
		for (int i = 0; i < 2; i++)
		{
			std::cout << "Enter the fraction " << i + 1 << std::endl;
			std::cout << "Enter the numerator: ";
			std::cin >> numer_manua;

			do
			{
				std::cout << "Enter denominator: ";
				std::cin >> denom_manua;
				std::cin.ignore();

				if (std::cin.fail() || denom_manua == 0) { std::cout << "Error entering denominator! Enter again" << std::endl; }
				std::cout << std::endl;
			} while (denom_manua == 0);

			if (i == 0)
			{
				num1.Init_manual(numer_manua, denom_manua);
			}
			else
			{
				num2.Init_manual(numer_manua, denom_manua);
			}

		}
		std::cout << "Fraction 1: ";
		num1.Print();
		std::cout << std::endl;

		std::cout << "Fraction 2: ";
		num2.Print();
		std::cout << std::endl;
		break;

	default:
		std::cout << "Incorrect option selection!" << std::endl;
		break;
	}



	while (true)
	{
		std::cout << std::endl;
		std::cout << "Select an option to operate on fractions:" << std::endl;
		std::cout << "1. Sum " << std::endl;
		std::cout << "2. Subtract" << std::endl;
		std::cout << "3. Multiply" << std::endl;
		std::cout << "4. Divide" << std::endl;
		std::cout << "5. Exit" << std::endl;
		std::cout << std::endl;
		std::cout << "Your choice: ";
		std::cin >> choice_operate;

		switch (choice_operate)
		{
		case 1:
			num1.Print();
			std::cout << " + ";
			num2.Print();
			std::cout << std::endl;

			result = num1.summa(num2);
			std::cout << "Sum: ";
			result.Print();
			std::cout << std::endl;
			break;
		case 2:
			num1.Print();
			std::cout << " - ";
			num2.Print();
			std::cout << std::endl;

			result = num1.subtract(num2);
			std::cout << "Subtract: ";
			result.Print();
			std::cout << std::endl;
			break;
		case 3:
			num1.Print();
			std::cout << " * ";
			num2.Print();
			std::cout << std::endl;

			result = num1.multiply(num2);
			std::cout << "Multiply: ";
			result.Print();
			std::cout << std::endl;
			break;
		case 4:
			num1.Print();
			std::cout << " : ";
			num2.Print();
			std::cout << std::endl;

			result = num1.divide(num2);
			std::cout << "Divide: ";
			result.Print();
			std::cout << std::endl;
			break;
		case 5:
			return 0;
			break;
		default:
			std::cout << "Incorrect option selection!" << std::endl;
			break;
		}
	}

	/*
	// Не по условию, но просто проработка темы

	int numer = num1.Get_numeratorand();
	std::cout << numer << std::endl;
	int denom = num1.Get_denominator();
	std::cout << denom << std::endl;

	num2.Set_numeratorand(99);
	num2.Set_denominator(99);

	num1.Print();
	num2.Print();
	*/

}


