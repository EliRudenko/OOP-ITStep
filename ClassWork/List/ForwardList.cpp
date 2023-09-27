#include <iostream>
using namespace std;


struct Element
{
	// Данные
	char data;
	// Адрес следующего элемента списка, УКАЗАТЕЛЬ
	Element* Next;
};

// Односвязный список
class List
{
	// Адрес головного элемента списка, НАЧАЛО
	Element* Head;
	// Адрес головного элемента списка, КОНЕЦ
	Element* Tail;
	// Количество элементов списка, МЕЖДУ НИМИ
	int Count;

public:
	// Конструктор
	List();
	// Деструктор
	~List();

	// Добавление элемента в список
	// (Новый элемент становится последним)
	void Add(char data);

	// Удаление элемента списка
	// (Удаляется головной элемент)
	void Del();
	// Удаление всего списка
	void DelAll();

	// Распечатка содержимого списка
	// (Распечатка начинается с головного элемента)
	void Print();

	// Получение количества элементов, находящихся в списке
	int GetCount();


	void Insert(char data, int position); //вставка элемента с данными data на позицию position.

	void Del_Position(int position); //удаление элемента на позиции position.

	int Find(char data);
};

List::List()
{
	// Изначально список пуст
	//ОДНУЛИЛИ ВСЕ УКАЗАТЕЛИ
	//ИЗНАЧАЛЬНО НИЧЕГО НЕ ВЫДЕЛЯЕТСЯ
	Head = Tail = NULL;
	Count = 0;
}

List::~List()
{
	// Вызов функции удаления
	DelAll();
}

int List::GetCount()
{
	// Возвращаем количество элементов
	return Count;
}

void List::Add(char data)
{
	// создание нового элемента
	Element* temp = new Element;

	// заполнение данными
	temp->data = data;
	// следующий элемент отсутствует
	temp->Next = NULL;
	// новый элемент становится последним элементом списка
	// если он не первый добавленный
	if (Head != NULL) {
		Tail->Next = temp;
		Tail = temp;
	}
	// новый элемент становится единственным
	// если он первый добавленный
	else {
		Head = Tail = temp;
		//temp УКАЗАЕТЛЬ НА ЭТОТ ЭЛЕМЕНТ
	}
}

void List::Del()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// перебрасываем голову на следующий элемент
	Head = Head->Next;
	// удаляем бывший головной элемент
	delete temp;
}

void List::DelAll()
{
	// Пока еще есть элементы
	while (Head != 0)
		// Удаляем элементы по одному
		Del();
}

void List::Print()
{
	// запоминаем адрес головного элемента
	Element* temp = Head;
	// Пока еще есть элементы
	while (temp != 0)
	{
		// Выводим данные
		cout << temp->data << " ";
		// Переходим на следующий элемент
		temp = temp->Next;
	}

	cout << "\n\n";
}



//ДЗ_1

void List::Insert(char data, int position)
{//ВЫСТАВКА
    if (position < 0 || position > Count) // GHJDTHRF
    {
        std::cout << "Error!" << std::endl; // не правильная позиция
        return;
    }

    Element* temp = new Element; // создается новый элемент 
    temp->data = data;

    if (position == 0) // вставляется в НАЧАЛО списка
    {
        temp->Next = Head;
        Head = temp;
        if (Count == 0){ Tail = temp; } // если список был ПУСТОЙ, перенаправление указателя
    }
    else
    {// НЕ в начало
        Element* current = Head;
        for (int i = 0; i < position - 1; i++) { current = current->Next; } // переход к след элем

		//указ на след эл
        temp->Next = current->Next; 
        current->Next = temp;

        if (position == Count){ Tail = temp; }
    }

    Count++; // счетчик эл
}

void List::Del_Position(int position)
{//УДАЛЕНИЕ по позиции
    if (position < 0 || position >= Count)
    {
        std::cout << "Error!" << std::endl; // не правильная позиция
        return;
    }

    if (position == 0) // вставляется в НАЧАЛО списка
    {
        Element* temp = Head;
        Head = Head->Next;
        delete temp; //УДАЛЕНИЕ
        if (Count == 1){ Tail = nullptr; } //обнуление указателя конца, при удалении
    }
    else
    {
        Element* current = Head;
        for (int i = 0; i < position - 1; i++) { current = current->Next; }  // переход к след элем

        Element* temp = current->Next; // запоминание что надо удалить 
        current->Next = temp->Next;
        delete temp; // УДАЛЕНИЕ

        if (position == Count - 1) { Tail = current; }
    }

    Count--;
}

int List::Find(char data)
{//ПОИСК
    Element* temp = Head;
    int position = 0;

    while (temp != nullptr)
    {
        if (temp->data == data) { return position; } // нашли
        
        temp = temp->Next;
        position++; //переходим на след позицию, ищем
    }

    return -1;  // нет результата
}




// Тестовый пример
int main()
{
	// Создаем объект класса List
	List lst;

	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << "\n\n";
	// Определяем длину строки
	int len = strlen(s);
	// Загоняем строку в список
	for (int i = 0; i < len; i++)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.Print();
	// Удаляем три элемента списка
	lst.Del();
	lst.Del();
	lst.Del();
	//Распечатываем содержимое списка
	lst.Print();



//ДЗ_1
    lst.Insert('L', 2);
    lst.Print();

    int position = lst.Find('L');
    if (position != -1)
    {
		cout << "Correct" << position << std::endl;
	}
    else { cout << "Error!"; }

	lst.Del_Position(2);
    lst.Print();

}

