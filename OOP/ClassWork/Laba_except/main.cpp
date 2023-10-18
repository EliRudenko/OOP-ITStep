#include <iostream>
#include <string.h>



class Exception
{
protected:
    char m_message[100];

public:
    Exception(const char* message);
    const char* GetMessage() const;
};
Exception::Exception(const char* message) { std::strcpy(m_message, message); }

const char* Exception::GetMessage() const {  return m_message; }




class Divide_by_zero : public Exception
{
public:
    Divide_by_zero(const char* zero);
};
Divide_by_zero::Divide_by_zero(const char* mes) : Exception(mes) {}




class IndexException : public Exception
{
public:
    IndexException(const char* message);
};
IndexException::IndexException(const char* message) : Exception(message) {}




using namespace std;

int main()
{
    double numerator = 0.0;
    double denominator = 0.0;

    try
    {
        cout << "Enter a numerator: ";
        cin >> numerator;

        cout << "Enter a denominator: ";
        cin >> denominator;

        if (denominator == 0.0)
        {
            throw Divide_by_zero("Divide by zero");
        }
        else
        {
            cout << "Result = " << numerator / denominator << endl;
        }



//LABA
        int mas[3] {1,2,3};
        for (int i = 0; i < 5; ++i)
        {
            if(i >=3)
            {
                throw IndexException("No index"); 
            }
            std::cout << mas[i] << "    ";
        }
        std::cout << std::endl;
    }

    
    catch (Exception& exception) 
    {
        cout << exception.GetMessage() << endl;
    }

    return 0;
}
