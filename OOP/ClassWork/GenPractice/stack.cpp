#include "d:\IT-STEP\IT-Step-Repo\Framework.h"
#include <iostream>

class Stack
{
    enum { EMPTY = -1, FULL = 4 }; //для быстрой проверки
    char st[FULL + 1];
    int top;

public:
    Stack();
    void Push(char c);
    char Pop();

    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();

    void Print();
    bool IsValid(char* input);
	void Init_keyboard(); 
	char Top(); 
};

Stack::Stack() { top = EMPTY; }

void Stack::Clear() { top = EMPTY; }

bool Stack::IsEmpty() {  return top == EMPTY; }

bool Stack::IsFull() { return top == FULL; }

int Stack::GetCount() { return top + 1; }

void Stack::Push(char c)
{
    if (!IsFull()) { st[++top] = c;}
}

char Stack::Pop()
{
    if (!IsEmpty())
	{ 
		return st[top--];
	}
    else {return 0;}
}

char Stack::Top()
{
    if (!IsEmpty())
    {    
		return st[top];
	}
    else {return 0;}
}

void Stack::Init_keyboard()
{
    char c;
    std::cout << "Enter characters (up to " << FULL + 1 << " characters, press Enter):";
    while (!IsFull())
    {
        std::cin >> c;
        Push(c);
    }
}

void Stack::Print()
{
    for (int i = 0; i <= top; ++i) { std::cout << st[i] << std::endl; }
}

bool Stack::IsValid(char* input)
{
    char brackets[3][2] = { {'{', '}'}, {'[', ']'}, {'(', ')'} };
    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (input[i] == brackets[j][0])
            {
                Push(input[i]);
            }
            else if (input[i] == brackets[j][1])
            {
                if (IsEmpty() || Pop() != brackets[j][0]) { return false; }
            }
        }
    }

    return IsEmpty();
}

int main()
{
    srand(time(0));
    Stack ST;
/*
    ST.Init_keyboard();
*/

//для быстрой проверки
    char inp[5];
    std::cout << "Enter a string with a maximum length of 20 characters:" << std::endl;
    std::cin >> inp;

    if (ST.IsValid(inp))
    {
        std::cout << "Correct!" << std::endl;
    }
    else { std::cout << "Eror!" << std::endl; }

    return 0;
}

