#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>

#include"Mylibrary.h"
/*дз:
* 1.Создать класс Попугай на основе Animal, реализовать нужные интерфейсы
* 2. Создать класс Самолет, и реализовать нужный интерфейс.
* 3. Создать функцию, который может работать и с объектом класса самолет, и с объектом класса попугай!!

*/
/*
class Ship:public ISwim
{
public:
	virtual void Swim()
	{
		cout << "Корабль- водный транспорт\n";
	}
};
*/

//3
void MyFunc(IFly * ptr)
{
	ptr->Fly();
}
int main()
{
	setlocale(0, "ru");
    //Pinguin obj("Королевский пингвин", 100, "Арктика");
    //Animal* ptr = &obj;
    //ptr->Eat();
    //ptr->Print();
    //ptr->Continent();


//1
    Parrot obj("Parrot", 100, "Арктика");
    MyFunc(&obj);

//2
   Plane pl;
   MyFunc(&pl);

}


/*
int main()
{
    Animal* ptr = new Pinguin("Ping", 100, "A");
    ptr->Eat();
    
    delete ptr;

    ISwim* pt =  new Pinguin("Ping", 100, "A");
    pt->Swim();

    //delete pt;


}
*/

//папугай, самолет
