#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

/*
 * Proxy является суррогатом другого объекта и контролирует доступ к нему.
 * Разумно управлять доступом к объекту, поскольку тогда можно отложить расходы на создание и инициализацию до момента,
 * когда объект действительно понадобится.
 */

 // Subject (IMath) определяет общий для RealSubject и Proxy интерфейс, 
// так что класс Proxy можно использовать везде, где ожидается RealSubject.

class IMath
{
public:
    virtual double Add(double x, double y) = 0;
    virtual double Sub(double x, double y) = 0;
    virtual double Mult(double x, double y) = 0;
    virtual double Div(double x, double y) = 0;
};

// RealSubject (Math) - определяет реальный объект, представленный заместителем.
class Math : public IMath
{
public:
    Math()
    {
        cout << "Create object Math. Wait...\n";
        Sleep(3000);
    }
    double Add(double x, double y) override
    {
        return x + y;
    }
    double Sub(double x, double y) override
    {
        return x - y;
    }
    double Mult(double x, double y) override
    {
        return x * y;
    }
    double Div(double x, double y) override
    {
        return x / y;
    }
};

/*
 * Proxy (MathProxy) - заместитель:
- хранит ссылку, которая позволяет заместителю обратиться к реальному субъекту.
  Объект класса Proxy может обращаться к объекту класса Subject, если интерфейсы классов RealSubject и Subject одинаковы;
- предоставляет интерфейс, идентичный интерфейсу Subject, так что заместитель всегда может быть подставлен вместо реального субъекта;
- контролирует доступ к реальному субъекту и может отвечать за его создание и удаление;
 */

class MathProxy : public IMath
{
    Math *math;
public:
    MathProxy()
    {
        math = nullptr;
    }
    ~MathProxy()
    {
        delete math;
    }
    // Быстрая операция - не требует реального субъекта
    double Add(double x, double y) override
    {
        return x + y;
    }
    // Быстрая операция - не требует реального субъекта
    double Sub(double x, double y) override
    {
        return x - y;
    }
    // Медленная операция - требует создания реального субъекта
    double Mult(double x, double y) override
    {
        if (math == nullptr)
            math = new Math();
        return math->Mult(x, y);
    }
    // Медленная операция - требует создания реального субъекта
    double Div(double x, double y) override
    {
        if (math == nullptr)
            math = new Math();
        return math->Div(x, y);
    }
};

void client(IMath *p)
{
    char s[20];
    sprintf_s(s, "4 + 2 = %f\n", p->Add(4, 2));
    cout << s;
    sprintf_s(s, "4 - 2 = %f\n", p->Sub(4, 2));
    cout << s;
    sprintf_s(s, "4 * 2 = %f\n", p->Mult(4, 2));
    cout << s;
    sprintf_s(s, "4 / 2 = %f\n", p->Div(4, 2));
    cout << s;
}
int main()
{
    IMath *p = new MathProxy();
    client(p);
    system("pause");
    return 0;
}
