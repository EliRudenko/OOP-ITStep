
#include <iostream>

const int MAX_EMPLOYEES = 100;
const char* FILE_NAME = "employee_book.txt";

struct Employee
{
    char name[50];
    char surname[50];
    char phone[15];
    double salary;
};

void print_menu()
{// ������� ��� ������ ����, ��� ������ �����
    std::cout << "Action selection menu:" << std::endl;
    std::cout << "1. Add a new employee" << std::endl;
    std::cout << "2. Delete employee" << std::endl;
    std::cout << "3. Search by surname" << std::endl;
    std::cout << "4. Search by salary range" << std::endl;
    std::cout << "5. Sort by surname" << std::endl;
    std::cout << "6. Show information about all employees" << std::endl;
    std::cout << "7. Load information from file" << std::endl;
    std::cout << "8. Save information to file" << std::endl;
    std::cout << "9. Exit" << std::endl;
}


bool is_valid_phone(const char* phone)
{//�������� ������
    int length = 0;
    while (phone[length] != '\0')
    {
        if (!isdigit(phone[length]))
        {// ���� ������ �� �����
            return false;
        }
        length++;
    }

    if (length != 10)
    {//�������� �����
        return false;
    }

    return true;
}

void add_employee(Employee* employee_book, int* num_employees)
{// ������� ��� ���������� ������ ����������
    if (*num_employees < MAX_EMPLOYEES)
    {//������ � ������������ 
        Employee new_employee;
        std::cout << "Enter name: ";
        std::cin.getline(new_employee.name, sizeof(new_employee.name));
        std::cout << "Enter surname: ";
        std::cin.getline(new_employee.surname, sizeof(new_employee.surname));
        char phone_input[15];
        do
        {
            std::cout << "Enter phone number (���������� 10) : ";
            std::cin.getline(phone_input, sizeof(phone_input));
        } while (!is_valid_phone(phone_input)); //���� ����� �� ����� ��������

        strcpy_s(new_employee.phone, phone_input);
        std::cout << "Enter salary: ";
        std::cin >> new_employee.salary;
        std::cin.ignore(); // ������� ������

        // ���������� ������ �������� � ������
        employee_book[*num_employees] = new_employee;
        (*num_employees)++;
        std::cout << "Employee added" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "The maximum employee limit has been reached!" << std::endl;
        std::cout << std::endl;
    }
}

void remove_employee(Employee* employee_book, int* num_employees)
{// ������� ��� �������� ���������� �� �������
    if (*num_employees == 0)
    {//��������, ���� �� �����-�� ��������
        std::cout << "Employee book is empty. Nothing to delete!" << std::endl;
        std::cout << std::endl;
        return;
    }

    //������ ������� ��� ���� ��� �� �������
    char search_surname[50];
    std::cout << "Enter surname to delete: ";
    std::cin.getline(search_surname, sizeof(search_surname));

    int found_index = -1;
    for (int i = 0; i < *num_employees; i++)
    {// ����� �� �������
        if (strcmp(employee_book[i].surname, search_surname) == 0)
        {
            found_index = i;
            break;
        }
    }

    if (found_index != -1)
    {
        for (int i = found_index; i < (*num_employees - 1); i++)
        {//���������� ��� ��������� ��������, ��� ���� ��� �� ������� ������
            employee_book[i] = employee_book[i + 1];
        }
        (*num_employees)--;
        std::cout << "Employee has been removed" << std::endl;
        std::cout << std::endl;
    }
    else
    {// �� �������
        std::cout << "An employee with the specified surname was not found!" << std::endl;
        std::cout << std::endl;
    }
}


void search_by_surname(const Employee* employee_book, int num_employees)
{// ������� ��� ������ ���������� �� ������� � ������ ���������� � ���
    if (num_employees == 0)
    {// ��������, ���� �� ����� - �� ��������
        std::cout << "Employee book is empty. Nothing to search!" << std::endl;
        std::cout << std::endl;
        return;
    }

    //������ ������� ��� ������
    char search_surname[50];
    std::cout << "Enter surname to search: ";
    std::cin.getline(search_surname, sizeof(search_surname));

    bool found = false;
    for (int i = 0; i < num_employees; i++)
    {//����� ��������, �����
        if (strcmp(employee_book[i].surname, search_surname) == 0)
        {
            std::cout << "Employee found:" << std::endl;
            std::cout << "Name: " << employee_book[i].name << std::endl;
            std::cout << "Surname: " << employee_book[i].surname << std::endl;
            std::cout << "Phone number: " << employee_book[i].phone << std::endl;
            std::cout << "Salary: " << employee_book[i].salary << std::endl;
            found = true;
        }
    }

    if (!found)
    {//�� �������
        std::cout << "Employee with the specified surname not found!" << std::endl;
        std::cout << std::endl;
    }
}

void search_by_salary_range(const Employee* employee_book, int num_employees)
{// ������� ��� ������ ����������� � ��������� ��, �����
    if (num_employees == 0)
    {// ��������, ���� �� ����� - �� ��������
        std::cout << "Employee book is empty. Nothing to search!" << std::endl;
        std::cout << std::endl;
        return;
    }
    // ������ ���������
    double min_salary, max_salary;
    std::cout << "Enter the minimum and maximum salary: ";
    std::cout << "minimum: ";
    std::cin >> min_salary;
    std::cout << "maximum: ";
    std::cin >> max_salary;
    std::cin.ignore(); // ������� ������

    bool found = false;
    std::cout << "Employees with salaries in the range " << min_salary << " - " << max_salary << ":" << std::endl;
    for (int i = 0; i < num_employees; i++)
    {// ����� �������� ������� ������ � ��������
        if (employee_book[i].salary >= min_salary && employee_book[i].salary <= max_salary)
        {
            std::cout << "---------------------------" << std::endl;
            std::cout << "Name: " << employee_book[i].name << std::endl;
            std::cout << "Surname: " << employee_book[i].surname << std::endl;
            std::cout << "Phone number: " << employee_book[i].phone << std::endl;
            std::cout << "Salary: " << employee_book[i].salary << std::endl;
            std::cout << "---------------------------" << std::endl;
            found = true;
        }
    }

    if (!found)
    {// �� �������
        std::cout << "No employees found in the specified salary range!" << std::endl;
        std::cout << std::endl;
    }
}


void sort_by_surname(Employee* employee_book, int num_employees)
{// ������� ��� ���������� �� �������, ���������
    if (num_employees == 0)
    {// ��������, ���� �� ����� - �� ��������
        std::cout << "Employee book is empty. Nothing to sort!" << std::endl;
        std::cout << std::endl;
        return;
    }

    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < num_employees - 1; i++)
        {
            if (strcmp(employee_book[i].surname, employee_book[i + 1].surname) > 0)
            { // ���� ������� i ������ ������� (i+1) - �������� �������
                std::swap(employee_book[i], employee_book[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);

    std::cout << "Employees sorted by surname" << std::endl;
    std::cout << std::endl;
}


void display_all(const Employee* employee_book, int num_employees)
{// ����� ����
    if (num_employees == 0)
    {// ��������, ���� �� ����� - �� ��������
        std::cout << "Employee book is empty." << std::endl;
        std::cout << std::endl;
        return;
    }

    std::cout << "List of employees:" << std::endl;
    for (int i = 0; i < num_employees; i++)
    {
        std::cout << "---------------------------" << std::endl;
        std::cout << "Name: " << employee_book[i].name << std::endl;
        std::cout << "Surname: " << employee_book[i].surname << std::endl;
        std::cout << "Phone number: " << employee_book[i].phone << std::endl;
        std::cout << "Salary: " << employee_book[i].salary << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << std::endl;
    }
}


bool load_from_file(Employee* employee_book, int* num_employees)
{// ������� ��� �������� ������ �� �����
    FILE* file;
    if (fopen_s(&file, FILE_NAME, "r") != 0)
    {
        std::cout << "Failed to open file!" << std::endl;
        std::cout << std::endl;
        return false;
    }

    //��������� ������ �� �����, ����������� ������ ���������
    //file - ��������� �� ���� ����������
    //%49s - ���������� ������ �� �����, 49 �����������
    //%lf - �����, ��������� ����� 
    // �� ����, ���� ������ ������ ������ �����, � �� �����
    *num_employees = 0;
    while (*num_employees < MAX_EMPLOYEES &&
        fscanf_s(file, "%49s %49s %14s %lf\n",
            employee_book[*num_employees].name, (unsigned int)sizeof(employee_book[*num_employees].name),
            employee_book[*num_employees].surname, (unsigned int)sizeof(employee_book[*num_employees].surname),
            employee_book[*num_employees].phone, (unsigned int)sizeof(employee_book[*num_employees].phone),
            &employee_book[*num_employees].salary) == 4) // 4 ������ ��� 4 ����
    {
        (*num_employees)++;
    }

    fclose(file);
    std::cout << "Information loaded from the file" << std::endl;
    std::cout << std::endl;
    return true;
}


bool save_to_file(const Employee* employee_book, int num_employees)
{// ������� ��� ���������� ������ � ����
    FILE* file;
    if (fopen_s(&file, FILE_NAME, "w") != 0)
    {
        std::cout << "Failed to open file!" << std::endl;
        std::cout << std::endl;
        return false;
    }

    //%s - ���������/���������� ������ ��������
    //%.2lf -  ���������/���������� ����� � ����� ������� ����� �����
    //�� ����, ������ ������ ������ ����� ����� ������, � �� �����
    for (int i = 0; i < num_employees; i++)
    {//������ ������ � ����
        fprintf_s(file, "%s %s %s %.2lf\n", employee_book[i].name, employee_book[i].surname, employee_book[i].phone, employee_book[i].salary);
    }

    fclose(file);
    std::cout << "Information saved to the file" << std::endl;
    std::cout << std::endl;
    return true;
}


int main()
{
    system("chcp 1251");
    Employee employee_book[MAX_EMPLOYEES];
    int num_employees = 0;

    while (true)
    {
        print_menu();

        //����� ������ ����
        std::cout << "Your choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore();  // ������� ������
        std::cout << std::endl;

        switch (choice)
        {
        case 1:
            add_employee(employee_book, &num_employees);
            break;
        case 2:
            remove_employee(employee_book, &num_employees);
            break;
        case 3:
            search_by_surname(employee_book, num_employees);
            break;
        case 4:
            search_by_salary_range(employee_book, num_employees);
            break;
        case 5:
            sort_by_surname(employee_book, num_employees);
            break;
        case 6:
            display_all(employee_book, num_employees);
            break;
        case 7:
            if (!load_from_file(employee_book, &num_employees))
            {
                std::cout << "Failed to load data from file!" << std::endl;
            }
            break;
        case 8:
            if (!save_to_file(employee_book, num_employees))
            {
                std::cout << "Failed to save data to file!" << std::endl;
            }
            break;
        case 9:
            return 0;
        default:
            std::cout << "Wrong choice. Try again!" << std::endl;
            break;
        }
    }
    return 0;
}


