using System;


//1
class Magazine
{
    private string magazineName;
    private int yearOfPublication;
    private string description;
    private string contactPhone;
    private string contactEmail;
    private int employees; 


    public Magazine(string name, int year, string desc, string phone, string email, int employeesCount)
    {
        magazineName = name;
        yearOfPublication = year;
        description = desc;
        contactPhone = phone;
        contactEmail = email;
        employees = employeesCount;
    }

    //  ИНДЕКСАТОР
    public object this[int index]
    {
        get
        {
            switch (index)
            {
                case 0: return magazineName;
                case 1: return yearOfPublication;
                case 2: return description;
                case 3: return contactPhone;
                case 4: return contactEmail;
                case 5: return employees;
                default: return null;
            }
        }
        set
        {
            switch (index)
            {
                case 0: magazineName = (string)value; break;
                case 1: yearOfPublication = (int)value; break;
                case 2: description = (string)value; break;
                case 3: contactPhone = (string)value; break;
                case 4: contactEmail = (string)value; break;
                case 5: employees = (int)value; break;
            }
        }
    }


    //  ПЕРЕГРУЗКИ
    public static Magazine operator +(Magazine mag, int value)
    {
        mag.employees += value;
        return mag;
    }

    public static Magazine operator -(Magazine mag, int value)
    {
        mag.employees -= value;
        return mag;
    }

    public static bool operator ==(Magazine mag1, Magazine mag2)
    {
        return mag1.employees == mag2.employees;
    }

    public static bool operator !=(Magazine mag1, Magazine mag2)
    {
        return mag1.employees != mag2.employees;
    }

    public static bool operator <(Magazine mag1, Magazine mag2)
    {
        return mag1.employees < mag2.employees;
    }

    public static bool operator >(Magazine mag1, Magazine mag2)
    {
        return mag1.employees > mag2.employees;
    }

    public void DisplayInfo()
    {
        Console.WriteLine($"Название журнала: {magazineName}, Сотрудников: {employees}");
    }
}





//2
class Store
{
    private string storeName;
    private string address;
    private string profileDescription;
    private string contactPhone;
    private string contactEmail;
    private int area;


    public Store(string name, string addr, string desc, string phone, string email, int storeArea)
    {
        storeName = name;
        address = addr;
        profileDescription = desc;
        contactPhone = phone;
        contactEmail = email;
        area = storeArea;
    }

    //  ИНДЕКСАТОР
    public object this[int index]
    {
        get
        {
            switch (index)
            {
                case 0: return storeName;
                case 1: return address;
                case 2: return profileDescription;
                case 3: return contactPhone;
                case 4: return contactEmail;
                case 5: return area;
                default: return null;
            }
        }
        set
        {
            switch (index)
            {
                case 0: storeName = (string)value; break;
                case 1: address = (string)value; break;
                case 2: profileDescription = (string)value; break;
                case 3: contactPhone = (string)value; break;
                case 4: contactEmail = (string)value; break;
                case 5: area = (int)value; break;
            }
        }
    }



    //  ПЕРЕГРУЗКИ
    public static Store operator +(Store store, int value)
    {
        store.area += value;
        return store;
    }

    public static Store operator -(Store store, int value)
    {
        store.area -= value;
        return store;
    }

    public static bool operator ==(Store store1, Store store2)
    {
        return store1.area == store2.area;
    }

    public static bool operator !=(Store store1, Store store2)
    {
        return store1.area != store2.area;
    }

    public static bool operator <(Store store1, Store store2)
    {
        return store1.area < store2.area;
    }

    public static bool operator >(Store store1, Store store2)
    {
        return store1.area > store2.area;
    }

    public void DisplayInfo()
    {
        Console.WriteLine($"Название магазина: {storeName}, Площадь: {area} кв.м.");
    }
}





class Program
{
    static void Main(string[] args)
    {
        Magazine mag1 = new Magazine("TechMag", 2023, "Технологии", "+3801111111", "techmag@mail.com", 20);
        Magazine mag2 = new Magazine("AutoMag", 2023, "Авто новости", "+3802222222", "automag@mail.com", 15);

        Store store1 = new Store("SuperShop", "Киев, ул. Примерная", "Онлайн магазин", "+3803333333", "shop@mail.com", 300);
        Store store2 = new Store("MegaStore", "Киев, ул. Вторая", "Офлайн магазин", "+3804444444", "mega@mail.com", 500);


        mag1 += 5; 
        mag2 -= 3; 
        store1 += 50; 
        store2 -= 100; 

        mag1.DisplayInfo();
        mag2.DisplayInfo();
        store1.DisplayInfo();
        store2.DisplayInfo();


        Console.WriteLine(mag1 > mag2 ? "Mag1 больше Mag2" : "Mag1 меньше или равен Mag2");
        Console.WriteLine(store1 == store2 ? "Store1 равен Store2" : "Store1 не равен Store2");
    }
}
