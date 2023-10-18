#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <time.h>

class Queue_Prior
{
    int* Wait;
    int* Pri;
    int MaxQueueLength;
    int QueueLength;

public:
    Queue_Prior(int m);
    ~Queue_Prior();
    void Add(int c, int p);
    int Extract();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();
    void Show();
};

class Statistics
{
    int* Users;
    int MaxQueueLength;
    int QueueLength;

public:

    Statistics(int m);
    ~Statistics();
    void Add(int user);
    void Show();
};

Queue_Prior::Queue_Prior(int m)
{
    MaxQueueLength = m;
    Wait = new int[MaxQueueLength];
    Pri = new int[MaxQueueLength];
    QueueLength = 0;
}

Queue_Prior::~Queue_Prior()
{
    delete[] Wait;
    delete[] Pri;
}

void Queue_Prior::Clear() { QueueLength = 0; }

bool Queue_Prior::IsEmpty() { return QueueLength == 0; }

bool Queue_Prior::IsFull() { return QueueLength == MaxQueueLength; }

int Queue_Prior::GetCount() { return QueueLength; }

void Queue_Prior::Add(int c, int p)
{
    if (!IsFull())
    {
        Wait[QueueLength] = c;
        Pri[QueueLength] = p;
        QueueLength++;
    }
}

int Queue_Prior::Extract()
{
    if (!IsEmpty())
    {
        int max_pri = Pri[0];
        int pos_max_pri = 0;

        for (int i = 1; i < QueueLength; i++)
        {
            if (max_pri < Pri[i])
            {
                max_pri = Pri[i];
                pos_max_pri = i;
            }
        }

        int temp1 = Wait[pos_max_pri];
        int temp2 = Pri[pos_max_pri];

        for (int i = pos_max_pri; i < QueueLength - 1; i++)
        {
            Wait[i] = Wait[i + 1];
            Pri[i] = Pri[i + 1];
        }

        QueueLength--;
        return temp1;
    }
    else{ return -1; }
}

void Queue_Prior::Show()
{
    std::cout << "\n-------------------------------------\n";
    for (int i = 0; i < QueueLength; i++)
    {
        std::cout << Wait[i] << " - " << Pri[i] << "\n\n";
    }
    std::cout << "\n-------------------------------------\n";
}

Statistics::Statistics(int m)
{
    MaxQueueLength = m;
    Users = new int[MaxQueueLength];
    QueueLength = 0;
}

Statistics::~Statistics() { delete[] Users; }

void Statistics::Add(int user)
{
    if (QueueLength < MaxQueueLength)
    {
        Users[QueueLength] = user;
        QueueLength++;
    }
}

void Statistics::Show()
{
    std::cout << "\n-------------------------------------\n";
    for (int i = 0; i < QueueLength; i++)
    {
        std::cout << "User: " << Users[i] << "\n\n";
    }
    std::cout << "\n-------------------------------------\n";
}

int main()
{
    srand(time(0));

    Queue_Prior QUP(25);
    Statistics stats(25);

    for (int i = 0; i < 5; i++)
    {
        int user = rand() % 100;
        int priority = rand() % 12;

        QUP.Add(user, priority);
        stats.Add(user);
    }

    QUP.Show();
    stats.Show();

    QUP.Extract();

    QUP.Show();
    stats.Show();

    return 0;
}
