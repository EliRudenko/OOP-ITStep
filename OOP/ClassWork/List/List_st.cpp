#include <iostream>
using namespace std;


template<typename T>
class Stack
{
private:

    struct Elem
    {
        T data;
        Elem* next, * prev;
    };

    Elem* Head, * Tail;
    int Count;

public:
    Stack();
    ~Stack();

    void AddTail(int n);
    void DelAll();

    bool IsEmpty() const;
    int GetCount() const;

    void Print() const;
    int ReturnTail();
};

template<typename T>
Stack<T>::Stack()
{
    Head = Tail = nullptr;
    Count = 0;
}

template<typename T>
Stack<T>::~Stack()
{
    while (Count != 0)
    {
        Elem* temp = Head;
        Head = Head->next;
        delete temp;
        Count--;
    }
}

template<typename T>
void Stack<T>::AddTail(int n)
{
    // Создаем новый элемент
    Elem* temp = new Elem;
    // Следующего нет
    temp->next = 0;
    // Заполняем данные
    temp->data = n;
    // Предыдущий - бывший хвост
    temp->prev = Tail;

    // Если элементы есть?
    if (Tail != 0)
        Tail->next = temp;

    // Если элемент первый, то он одновременно и голова и хвост
    if (Count == 0)
        Head = Tail = temp;
    else
        // иначе новый элемент - хвостовой
        Tail = temp;

    Count++;
}



template<typename T>
void Stack<T>::DelAll()
{
    while (Count != 0)
    {
        Elem* temp = Head;
        Head = Head->next;
        delete temp;
        Count--;
    }
    Tail = nullptr;
}


template<typename T>
bool Stack<T>::IsEmpty() const { return Count == 0; }


template<typename T>
int Stack<T>::GetCount() const { return Count; }

template<typename T>
void Stack<T>::Print() const
{
    if (Count != 0)
    {
        Elem* temp = Head;
        cout << "( ";
        while (temp->next != nullptr)
        {
            cout << temp->data << ", ";
            temp = temp->next;
        }

        cout << temp->data << " )\n";
    }
    else
    {
        cout << "Empty\n";
    }
}

template<typename T>
int Stack<T>::ReturnTail()
{
    T temp = Tail->data;

    Elem* newTail = Tail->prev;

    delete Tail;
    newTail->next = nullptr;

    --Count;

    Tail = newTail;
    return temp;
}


int main()
{
    Stack<int> s;

    const int n = 10;
    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < n; i++) { s.AddTail(a[i]); } 

    cout << "Stack s:\n";
    s.Print();

    //s.DelAll();

    //s.Print();

    std::cout << "Number of elements: " << s.GetCount() << std::endl;
    std::cout << s.ReturnTail() << std::endl;

    s.Print();

    return 0;
}