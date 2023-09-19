#include <iostream>

const int max_contacts = 100;      
const int max_name_length = 50;    
const int max_phone_length = 15;   
const int max_info_length = 100;   

class Contact
{
private:
    char* surname;              
    char* name;                
    char* patronymic;          
    int home_phone;             
    int work_phone;             
    int mobile_phone;            
    char* additional_info;     

public:

    Contact()// Без параметров = по умолчанию
    {// Конструктор, который при обьявлении присваивает nullptr
        surname = nullptr;
        name = nullptr;
        patronymic = nullptr;
        home_phone = 0;
        work_phone = 0;
        mobile_phone = 0;
        additional_info = nullptr;
    }
    Contact(const char* last, const char* first, const char* middle, int home, int work, int mobile, const char* info)
    {// Конструктор, но только уже для инфы о контакте = с параметрами
 
        surname = new char[strlen(last) + 1]; // Выделение динам памяти
        strcpy_s(surname, strlen(last) + 1, last);

        name = new char[strlen(first) + 1];
        strcpy_s(name, strlen(first) + 1, first);

        patronymic = new char[strlen(middle) + 1];
        strcpy_s(patronymic, strlen(middle) + 1, middle);

        home_phone = home; // присваиваются значение из переденных параметров   
        work_phone = work;
        mobile_phone = mobile;

        additional_info = new char[strlen(info) + 1];
        strcpy_s(additional_info, strlen(info) + 1, info);
    }
    ~Contact()
    {// Диструктор
        delete[] surname;
        delete[] name;
        delete[] patronymic;
        delete[] additional_info;
    }


    //МЕТОДЫ
    
    //установка значчений
    void set_surname(const char* last)
    {
        delete[] surname; // Удаляется предыдущее значение
        surname = new char[strlen(last) + 1]; // Выделяется новая память 
        strcpy_s(surname, strlen(last) + 1, last); // Копируется новое значение
    }
    void set_name(const char* first)
    {
        delete[] name;
        name = new char[strlen(first) + 1];
        strcpy_s(name, strlen(first) + 1, first);
    }
    void set_patronymic(const char* middle)
    {
        delete[] patronymic;
        patronymic = new char[strlen(middle) + 1];
        strcpy_s(patronymic, strlen(middle) + 1, middle);
    }
    void set_home_phone(int phone)
    {
        home_phone = phone;
    }
    void set_work_phone(int phone)
    {
        work_phone = phone;
    }
    void set_mobile_phone(int phone)
    {
        mobile_phone = phone;
    }
    void set_additional_info(const char* info)
    {
        delete[] additional_info;
        additional_info = new char[strlen(info) + 1];
        strcpy_s(additional_info, strlen(info) + 1, info);
    }



    // Полчусение значений
    char* get_surname(){ return surname; }

    char* get_name(){ return name; }

    char* get_patronymic(){ return patronymic; }

    int get_home_phone() { return home_phone; }

    int get_work_phone(){ return work_phone; }

    int get_mobile_phone(){ return mobile_phone;  }

    char* get_additional_info() { return additional_info; }
};



void print_contact(Contact& contact)
{// Вывод инфы
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Surname: " << contact.get_surname() << std::endl;
    std::cout << "Name: " << contact.get_name() << std::endl;
    std::cout << "Patronymic: " << contact.get_patronymic() << std::endl;



    //Проверки, выбрал ли пользователь заполнять НЕ оъязательное поле
    if (contact.get_home_phone() != 0)
    {
        std::cout << "Home Phone: " << contact.get_home_phone() << std::endl;
    }
    else
    {
        std::cout << "Home Phone: -" << std::endl;
    }
    if (contact.get_work_phone() != 0)
    {
        std::cout << "Work Phone: " << contact.get_work_phone() << std::endl;
    }
    else
    {
        std::cout << "Work Phone: -" << std::endl;
    }

    if (contact.get_mobile_phone() != 0)
    {
        std::cout << "Mobile Phone: " << contact.get_mobile_phone() << std::endl;
    }
    else
    {
        std::cout << "Mobile Phone: -" << std::endl;
    }

    std::cout << "Additional Info: " << contact.get_additional_info() << std::endl;

    std::cout << "-----------------------------------" << std::endl;
}

int main() 
{
    Contact* contacts[max_contacts]; // Массив указателей на контакты
    int num_contacts = 0; // Текущее количество контактов

    while (true) 
    {
        int choice; 
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add Contact" << std::endl;
        std::cout << "2. Delete Contact" << std::endl;
        std::cout << "3. Search by Surname" << std::endl;
        std::cout << "4. Print All Contacts" << std::endl;
        std::cout << "5. Read from File" << std::endl;
        std::cout << "6. Save to File" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice; // Считываем выбор пользователя

        if (choice == 7) {  break; }

        switch (choice) 
        {
        case 1: 
        { // Добавление контакта
            char last_name[max_name_length]; // Массив фамилий
            char first_name[max_name_length]; // Массив имен
            char middle_name[max_name_length]; // Массив отчеств
            int home_phone = 0; // домашний телефон, не обязательное поле
            int work_phone = 0; //робочий, тоже не объязательное
            int mobile_phone = 0; 
            char additional_info[max_info_length]; // Массив дополнительной инфы

            std::cout << std::endl;
            std::cout << "Enter surname: ";
            std::cin.ignore(); // очистка буфера
            std::cin.getline(last_name, max_name_length); // Считываем фамилию

            std::cout << "Enter name: ";
            std::cin.getline(first_name, max_name_length); 

            std::cout << "Enter patronymic: ";
            std::cin.getline(middle_name, max_name_length); 

            std::cout << "Do you want to enter home phone? (1 - yea/0 - no): ";
            int option; // Переменная для хранения ответа пользователя
            std::cin >> option; // Считываем ответ

            if (option == 1) 
            { // если 1, то запрашиваем номер 
                std::cout << "Enter home phone: ";
                std::cin >> home_phone;
            }

            std::cout << "Do you want to enter work phone? (1 - yea/0 - no): ";
            std::cin >> option; // Спрашиваем, хочет ли пользователь ввести рабочий номер

            if (option == 1) 
            { 
                std::cout << "Enter work phone: ";
                std::cin >> work_phone;
            }

            std::cout << "Enter mobile phone: ";
            std::cin >> mobile_phone; 
            std::cin.ignore(); // Очищаем буфер от лишних символов

            std::cout << "Enter additional inform.: ";
            std::cin.getline(additional_info, max_info_length); 
            std::cout << std::endl;

            // новый контакт и добавляем его в массив !!!
            contacts[num_contacts++] = new Contact(last_name, first_name, middle_name, home_phone, work_phone, mobile_phone, additional_info); // Создаем новый контакт и добавляем его в массив
            break;
        }

        case 2: 
        { // Удаление контакта
            if (num_contacts == 0) 
            { //Список пуст
                std::cout << "The contact list is empty!" << std::endl;
            }
            else 
            {
                int index;
                std::cout << std::endl;
                std::cout << "Enter the index of the contact you want to delete (1 to " << num_contacts + 1 << "): ";
                std::cin >> index; // Считываем индекс контакта, который нужно удалить

                if (index >= 1 && index < num_contacts) 
                { // Проверка byltrcf
                    delete contacts[index]; // Освобождаем память
                    // Смещаем остальные контакты
                    for (int i = index; i < num_contacts - 1; ++i) { contacts[i] = contacts[i + 1]; }
                   
                    num_contacts--; // Уменьшаем количество контактов
                }
                else { std::cout << "Invalid index!" << std::endl; }
            }
            break;
        }

        case 3: 
        { // Поиск по фамилии
            if (num_contacts == 0) 
            {
                std::cout << "The contact list is empty!" << std::endl;
            }
            else 
            {
                std::cout << std::endl;
                char search_surname[max_name_length]; // Массив для хранения фамилии которую надо найти
                std::cout << "Enter surname to search: ";
                std::cin >> search_surname; 
                bool found = false; //  что бы проверять найден ли контакт

                for (int i = 0; i < num_contacts; ++i) 
                {
                    char* surname = contacts[i]->get_surname(); //фамилию контакта который ПРОВЕРЯЕТСЯ
                    if (strcmp(surname, search_surname) == 0) 
                    {
                        // СРАВНЕНИЕ
                        print_contact(*contacts[i]); // если СОВПАДАЮТ
                        found = true; 
                    }
                }
                if (!found) 
                { 
                    std::cout << "contacts not to found with the given surname" << std::endl;
                }
            }
            break;
        }

        case 4: 
        { //ВЫВОД
            if (num_contacts == 0) 
            { 
                std::cout << "The contact list is empty!" << std::endl;
            }
            else 
            {
                std::cout << std::endl;

                for (int i = 0; i < num_contacts; ++i) 
                {

                    std::cout << "Contact " << i + 1 << ":" << std::endl; 
                    print_contact(*contacts[i]); // вывод инфы
                }
            }
            break;
        }


        //КАк в 1 дз
        case 5: 
        { // ЧТЕНИЕ
            FILE* file; // Указатель на файл
            if (fopen_s(&file, "contacts_list.txt", "r") == 0 && file) 
            { 
                char last_name[max_name_length];
                char first_name[max_name_length];
                char middle_name[max_name_length];
                int home_phone;
                int work_phone;
                int mobile_phone;
                char additional_info[max_info_length];

                while (fscanf_s(file, "%s %s %s %d %d %d %s", last_name, max_name_length, first_name, max_name_length, middle_name, max_name_length, &home_phone, &work_phone, &mobile_phone, additional_info, max_info_length) != EOF) 
                { // Считываем информацию о контакте из файла

                    //новый контакт добавляем в массив
                    contacts[num_contacts++] = new Contact(last_name, first_name, middle_name, home_phone, work_phone, mobile_phone, additional_info); 
                }

                fclose(file);
            }
            else { std::cout << "Error opening file!" << std::endl; }
            break;
        }

        case 6: 
        { // ЗАПИСЬ
            FILE* file; // Указатель на файл
            if (fopen_s(&file, "contacts.txt", "w") == 0 && file) 
            { 
                for (int i = 0; i < num_contacts; ++i) 
                {
                    // Запись инфы о контакте в файл
                    fprintf_s(file, "%s %s %s %d %d %d %s\n",
                        contacts[i]->get_surname(),
                        contacts[i]->get_name(),
                        contacts[i]->get_patronymic(),
                        contacts[i]->get_home_phone(),
                        contacts[i]->get_work_phone(),
                        contacts[i]->get_mobile_phone(),
                        contacts[i]->get_additional_info()); 
                }
                fclose(file); 
            }
            else { std::cout << "Error opening file!" << std::endl; }
            break;
        }

        default: 
        {
            std::cout << "Invalid choice!" << std::endl;
            break;
        }
        }
    }

    // Освобождение память, которая выделялась под контакты!!
    for (int i = 0; i < num_contacts; ++i) { delete contacts[i]; }

    return 0;
}

