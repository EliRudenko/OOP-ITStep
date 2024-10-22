using System;
using System.Collections.Generic;


class Person
{
    protected string name;
    protected string surname;
    protected int age;
    protected string phone;


    public string Name
    {
        get { return name; }
        set { name = value; }
    }
    public string Surname
    {
        get { return surname; }
        set { surname = value; }
    }
    public int Age
    {
        get { return age; }
        set { age = value; }
    }
    public string Phone
    {
        get { return phone; }
        set { phone = value; }
    }



    public Person() : this("Неизвестно", "Неизвестно", 0, "000-000-0000") {}


    public Person(string name, string surname, int age, string phone)
    {
        this.name = name;
        this.surname = surname;
        this.age = age;
        this.phone = phone;
    }



    public virtual void Print()
    {
        Console.WriteLine($"Имя: {name}, Фамилия: {surname}, Возраст: {age}, Телефон: {phone}");
    }
}

class Student : Person
{

    protected double average;
    protected string number_of_group;


    public double Average
    {
        get { return average; }
        set { average = value; }
    }
    public string Number_Of_Group
    {
        get { return number_of_group; }
        set { number_of_group = value; }
    }


    public Student() : this("Неизвестно", "Неизвестно", 0, "000-000-0000", 0.0, "000") {}



    public Student(string name, string surname, int age, string phone, double average, string group) : base(name, surname, age, phone)
    {
        this.average = average;
        this.number_of_group = group;
    }



    public override void Print()
    {
        base.Print(); 
        Console.WriteLine($"Средний балл: {average}, Группа: {number_of_group}");
    }
}

class Academy_Group
{

    private List<Student> students;
    private int count;



    public Academy_Group()
    {
        students = new List<Student>();
        count = 0;
    }


    public void Add(Student student)
    {
        students.Add(student);
        count++;
    }



    public void Remove(string surname)
    {
        var studentToRemove = students.Find(st => st.Surname == surname);
        if (studentToRemove != null)
        {
            students.Remove(studentToRemove);
            count--;
        }
        else
        {
            Console.WriteLine("Студент с такой фамилией не найден.");
        }
    }



    public void Edit(string surname, Student newInfo)
    {
        var studentToEdit = students.Find(st => st.Surname == surname);
        if (studentToEdit != null)
        {
            studentToEdit.Name = newInfo.Name;
            studentToEdit.Age = newInfo.Age;
            studentToEdit.Phone = newInfo.Phone;
            studentToEdit.Average = newInfo.Average;
            studentToEdit.Number_Of_Group = newInfo.Number_Of_Group;
        }
        else
        {
            Console.WriteLine("Студент с такой фамилией не найден.");
        }
    }


    public void Print()
    {
        Console.WriteLine("Список студентов:");
        foreach (var student in students)
        {
            student.Print();
            Console.WriteLine();
        }
    }


    public void Save()
    {
        Console.WriteLine("Сохранение данных в файл...");
        foreach (var student in students)
        {
            Console.WriteLine($"{student.Name};{student.Surname};{student.Age};{student.Phone};{student.Average};{student.Number_Of_Group}");
        }
    }


    public void Load()
    {
        Console.WriteLine("Загрузка данных из файла...");
    }



    public void Search(string surname)
    {
        var student = students.Find(st => st.Surname == surname);
        if (student != null)
        {
            Console.WriteLine("Найден студент:");
            student.Print();
        }
        else
        {
            Console.WriteLine("Студент с такой фамилией не найден.");
        }
    }
}

class Main_Class
{
    static void Main(string[] args)
    {
        // Создаём группу
        Academy_Group group = new Academy_Group();


        group.Add(new Student("Иван", "Иванов", 20, "068-050-6080", 11.5, "221"));
        group.Add(new Student("Пётр", "Петров", 21, "067-450-7033", 9.8, "222"));


        group.Print();


        group.Search("Иванов");

        group.Edit("Иванов", new Student("Иван", "Иванов", 21, "067-450-7053", 10.8, "221"));

        group.Remove("Петров");



        group.Print();

        group.Save();
    }
}
