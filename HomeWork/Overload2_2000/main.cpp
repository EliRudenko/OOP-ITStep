#include <iostream>
#include "Foo.h"


Foo operator+(const Foo obj1, const Foo obj2)
{
	return Foo(obj1.GetData() + obj2.GetData());
}
Foo operator+(const Foo obj1, const int obj2)
{
	Foo rez(obj1.GetData() + obj2);
	//rez.SetData();
	return rez;
}
Foo operator+(const int obj2, const Foo obj1)
{
	Foo rez(obj1.GetData() + obj2);
	return rez;
}


Foo& operator+=(Foo& obj, int a)
{
	obj.SetData(obj.GetData() + a);
	return obj;
}


Foo& operator++(Foo& obj)
{
	obj.SetData(obj.GetData() + 10);
	return obj;
}
Foo operator++(Foo& obj, int)
{
	Foo temp(obj);
	obj.SetData(obj.GetData() + 10);
	return temp;
}




int main()
{

	Foo obj1(5);
	Foo obj2(5);
	Foo obj3 = obj1 + obj2;
	std::cout << "5+5: ";
	obj3.Show();

	obj3 = 20 + obj1;
	std::cout << "20 + 5: ";
	obj3.Show();

	obj3 += 10;
	std::cout << "+10: ";
	obj3.Show();


	Foo rez = ++obj1;
	std::cout << "1. ++: ";
	rez.Show();


	Foo rez2 = obj1++;
	std::cout << "2. ++: ";
	rez2.Show();

	return 0;

}