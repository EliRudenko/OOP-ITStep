#include <iostream>
#include <time.h>
using namespace std;

class QueuePriority
{
    int* Wait;
    int* Pri;
    int MaxQueueLength;
    int QueueLength;

public:
    QueuePriority(int m);
    ~QueuePriority();
    void Add(int c, int p);
    int Extract();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();
    void Show();
};

class PrintStatistics
{
    int* Users;
    time_t* PrintTimes;
    int MaxQueueLength;
    int QueueLength;

public:
    PrintStatistics(int m);
    ~PrintStatistics();
    void Add(int user, time_t printTime);
    void Show();
};

QueuePriority::QueuePriority(int m)
{
    MaxQueueLength = m;
    Wait = new int[MaxQueueLength];
    Pri = new int[MaxQueueLength];
    QueueLength = 0;
}

QueuePriority::~QueuePriority()
{
    delete[] Wait;
    delete[] Pri;
}

void QueuePriority::Clear()
{
    QueueLength = 0;
}

bool QueuePriority::IsEmpty()
{
    return QueueLength == 0;
}

bool QueuePriority::IsFull()
{
    return QueueLength == MaxQueueLength;
}

int QueuePriority::GetCount()
{
    return QueueLength;
}

void QueuePriority::Add(int c, int p)
{
    if (!IsFull())
    {
        Wait[QueueLength] = c;
        Pri[QueueLength] = p;
        QueueLength++;
    }
}

int QueuePriority::Extract()
{
    if (!IsEmpty())
    {
        int max_pri = Pri[0];
        int pos_max_pri = 0;

        for (int i = 1; i < QueueLength; i++)
            if (max_pri < Pri[i])
            {
                max_pri = Pri[i];
                pos_max_pri = i;
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
    else
    {
        return -1;
    }
}

void QueuePriority::Show()
{
    cout << "\n-------------------------------------\n";
    for (int i = 0; i < QueueLength; i++)
    {
        cout << Wait[i] << " - " << Pri[i] << "\n\n";
    }
    cout << "\n-------------------------------------\n";
}

PrintStatistics::PrintStatistics(int m)
{
    MaxQueueLength = m;
    Users = new int[MaxQueueLength];
    PrintTimes = new time_t[MaxQueueLength];
    QueueLength = 0;
}

PrintStatistics::~PrintStatistics()
{
    delete[] Users;
    delete[] PrintTimes;
}

void PrintStatistics::Add(int user, time_t printTime)
{
    if (QueueLength < MaxQueueLength)
    {
        Users[QueueLength] = user;
        PrintTimes[QueueLength] = printTime;
        QueueLength++;
    }
}

void PrintStatistics::Show()
{
    cout << "\n-------------------------------------\n";
    for (int i = 0; i < QueueLength; i++)
    {
        cout << "User: " << Users[i] << ", Print Time: " << asctime(localtime(&PrintTimes[i])) << "\n\n";
    }
    cout << "\n-------------------------------------\n";
}

int main()
{
    srand(time(0));

    QueuePriority QUP(25);
    PrintStatistics stats(25);

    for (int i = 0; i < 5; i++)
    {
        int user = rand() % 100;
        int priority = rand() % 12;

        QUP.Add(user, priority);
        stats.Add(user, time(0)); // Добавляем текущее время как время печати
    }

    QUP.Show();
    stats.Show();

    QUP.Extract();

    QUP.Show();
    stats.Show();

    return 0;
}
