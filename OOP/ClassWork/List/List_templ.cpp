#include <iostream>
using namespace std;


template<typename T>
class Queue
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
    Queue();
    ~Queue();

    void Enqueue(const T& data);
    void DelAll();

    bool IsEmpty() const;
    int GetCount() const;

    void Print() const;
    int ReturnTail();
};

template<typename T>
Queue<T>::Queue()
{
    Head = Tail = nullptr;
    Count = 0;
}

template<typename T>
Queue<T>::~Queue()
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
void Queue<T>::Enqueue(const T& data)
{
    Elem* temp = new Elem;
    temp->prev = nullptr;
    temp->data = data;
    temp->next = nullptr;

    if (Count == 0)
    {
        Head = Tail = temp;
    }
    else
    {
        temp->prev = Tail;
        Tail->next = temp;
        Tail = temp;
    }

    Count++;
}

template<typename T>
void Queue<T>::DelAll()
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
bool Queue<T>::IsEmpty() const { return Count == 0; }


template<typename T>
int Queue<T>::GetCount() const { return Count; }

template<typename T>
void Queue<T>::Print() const
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
int Queue<T>::ReturnTail()
{
    T temp = Tail->data;

    Elem<T>* newTail = Tail->prev;

    delete Tail;
    newTail->next = nullptr;

    Tail = newTail;
    return temp;
}


int main()
{
    Queue<int> q;

    const int n = 10;
    int a[n] = { 0,1,2,3,4,5,6,7,8,9 };

    for (int i = 0; i < n; i++) { q.Enqueue(a[i]); } 

    cout << "Queue q:\n";
    q.Print();

    q.DelAll();

    q.Print();

    std::cout << "Number of elements: " << q.GetCount() << std::endl;
    std::cout << q.ReturnTail() << std::endl;

    return 0;
}