#include <iostream>



class Point
{
private:
	//по умолчанию приват
	//РЕАЛИЗАЦИЯ => инкапсулированная часть класса
	//ПОЛЯ КЛАССА, то из чего состоит
	int x;
	int y;
public: //Интерфейсная часть, система управления
	// МЕТОДЫ класса

	Point()
	{
		x = y = 0; 
	}

	Point(int a, int b)
	{
		x = a; 
		y = b;
	}

	void Print()
	{
		std::cout << x << " " << y << std::endl;

	}
	void Init()
	{
		x = rand() % 10;
		y = rand() % 10;
	}
	void Init(int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	void SetX(int X)
	{
		if (X > 0) { X = x; }
	}
	void SetY(int Y)
	{
		if (Y > 0) { Y = y; }
	}

	int GetX() { return x; }

	int GetY() { return y; }

	//Обьекст + чисто
	void Add(int a)
	{

		x += a;
		y += a;
	}

	Point Sum(Point b)
	{
		Point rez;
		//rez.x = x + x.b;
	}

};




int main()
{
	//экземпляр класса - обьект - переменная типа класс
	Point a; // только сейчас выделяется память

	//a.Init();
	//a.Print();

	a.Init(10, 20);
	a.Print();

	a.Add(5);
	a.Print();

	//Предоставить доступ к закрытым частям
	//только к определенному компоненту

	int x = a.GetX();
	std::cout << x << std::endl;
	a.SetX(100);
	a.Print();
}
