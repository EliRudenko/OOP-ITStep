
class MyString 
{
private:
    char* str; // указатель на строку
    int length; // длина 

public:
    static int objectCount; //Стат поле кол во созданных объектов

    // Конструкторы и деструктор
    MyString(); // по умолчанию
    MyString(int size); // с размером
    MyString(const char* input); // с инициализацией от юзера
    MyString(const MyString& other); // копи
    MyString& operator=(const MyString& right); //присваивание
    ~MyString(); // деструктор

    // Методы для ввода и вывода
    void Input();
    void Print() const;


    char* GetStr() const { return str; }
    int GetLength() const { return length; }

    void SetStr(const char* s) 
    {
        delete[] str;
        int inputLength = 0;

        while (s[inputLength] != '\0') { ++inputLength; }

        str = new char[inputLength + 1];
        length = inputLength;

        for (int i = 0; i <= length; ++i) { str[i] = s[i]; }
    }
    void SetLength(int size) 
    {
        delete[] str;
        str = new char[size + 1];
        length = size;
        str[0] = '\0';
    }


    // Методы работы со строками
    void MyStrcpy(const MyString& obj);
    bool MyStrStr(const char* str) const;
    int MyChr(char c) const;
    int MyStrLen() const;
    void MyStrCat(const MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(const MyString& b) const;

    // Перегрузка операторов
    MyString operator+(const MyString& other) const; // оператор сложения
    MyString& operator+=(const MyString& other); // оператор +=
    
    //Новое дз
    char& operator[](int index); // оператор []
    const char& operator[](int index) const; // оператор [] const

    // Стат метод кол во объектов
    static int getObjectCount();


    // Новое дз
    void Add_Chars(); //+10 в уонец
    MyString operator+(char c) const; // конкатенация стр символов, перегрузка опер +
    MyString operator+(int n) const; // конкатенация стрп int, перегрузка опер +
    MyString& operator+=(char c); // добавление символа в конец строки, перегрузка +=
    MyString& operator+=(int n); // добавления int в конец строки, перегрузка +=
    MyString operator++(int); //добавления А в коец, перегрузка ++
    MyString& operator++(); 

    char& operator()(int index); // доступ к символу по индексу
    const char& operator()(int index) const; // конст и тоже самое
};

MyString operator+(char c, const MyString& obj); // конкатенация символа строка, перегрузка +
