#include <iostream>



class Point
{
private:
	//�� ��������� ������
	//���������� => ����������������� ����� ������
	//���� ������, �� �� ���� �������
	int x;
	int y;
public: //������������ �����, ������� ����������
	// ������ ������

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

	//������� + �����
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
	//��������� ������ - ������ - ���������� ���� �����
	Point a; // ������ ������ ���������� ������

	//a.Init();
	//a.Print();

	a.Init(10, 20);
	a.Print();

	a.Add(5);
	a.Print();

	//������������ ������ � �������� ������
	//������ � ������������� ����������

	int x = a.GetX();
	std::cout << x << std::endl;
	a.SetX(100);
	a.Print();
}
