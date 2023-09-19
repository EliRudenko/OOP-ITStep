#include<iostream>
using namespace std;

class Student
{
private:

	char* name;
	char* email;
	int age;

public:
	Student()
	{
		name = nullptr;
		email = nullptr;
		age = 0;
		std::cout << "Constructor by def" << std::endl;
	}
	Student(const char* n, const char* e, int a)
	{
		name = new char[strlen(n) + 1]; 
		strcpy_s(name, strlen(n) + 1, n);
		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);
		age = a;
		std::cout << "Constructor 3 params" << std::endl;

	}
	~Student()
	{
		delete[] name;
		delete[] email;
		std::cout << "Destructor" << std::endl;
	}

	void Print()
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "email: " << email << std::endl;
		std::cout << "Age: " << age << std::endl;
	}

	// Перенесла и Инита
	void Set_name()
	{
		char buff_n[20];

		std::cout << "Enter name (max 20 symbols): ";
		std::cin >> buff_n;
		if (name != nullptr)
		{
			std::cout << "Delete: " << name << std::endl;
			delete[]name;
		}
		name = new char[strlen(buff_n) + 1];
		strcpy_s(name, strlen(buff_n) + 1, buff_n);
	}
	void Set_email()
	{
		char buff_e[50];
		std::cout << "Enter email (max 50 symbols): ";
		std::cin >> buff_e;
		if (email != nullptr)
		{
			std::cout << "Delete: " << email << std::endl;
			delete[]email;
		}
		email = new char[strlen(buff_e) + 1];
		strcpy_s(email, strlen(buff_e) + 1, buff_e);

	}
	void Set_age()
	{
		int a;
		std::cout << "Enter age: ";
		std::cin >> age;
	}

	char* Get_name() { return name; }
	char* Get_email() { return email; }
	int Get_age() { return age; }


	void Input()
	{
		//NAME
		char buff_n[20];
		std::cout << "Enter name: ";
		std::cin >> buff_n;
		if (name != nullptr)
		{
			std::cout << "Delete: " << name << std::endl;
			delete[]name;
		}
		name = new char[strlen(buff_n) + 1];
		strcpy_s(name, strlen(buff_n) + 1, buff_n);

		//EMAIL
		char buff_e[20];
		std::cout << "Enter email (max 50 symbols): ";
		std::cin >> buff_e;
		if (email != nullptr)
		{
			std::cout << "Delete: " << email << std::endl;
			delete[]email;
		}
		email = new char[strlen(buff_e) + 1];
		strcpy_s(email, strlen(buff_e) + 1, buff_e);

		//AGE
		std::cout << "Enter age: ";
		std::cin >> age;
	}

};

int main()
{
	Student* students[10]; // Массив указателей на объекты Student
	int num_students = 0;

	int choice;
	int choice_1_print = 0;


	do
	{
		std::cout << "Select menu item:" << std::endl;
		std::cout << "1. Add contact" << std::endl;
		std::cout << "2. Show all contacts" << std::endl;
		std::cout << "3. Display specific information" << std::endl;
		std::cout << "4. Exit" << std::endl;

		std::cout << "Your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:

			do
			{
				students[num_students] = new Student();
				// -> это вызываем Метод через указатель
				students[num_students]->Set_name();
				students[num_students]->Set_email();
				students[num_students]->Set_age();

				int choice_add;
				cout << "Want to add another student? (1 - yea/0 - no):";
				cin >> choice_add;
				std::cout << std::endl;
				num_students++;
				if (choice_add == 0)
				{
					break;
				}

				std::cout << std::endl;

			} while (num_students < 10);
			break;

		case 2:
			if (num_students == 0)
			{
				std::cout << "The contact list is empty!" << std::endl;
				std::cout << std::endl;
			}
			else
			{
				for (int i = 0; i < num_students; i++)
				{
					students[i]->Print();
					std::cout << std::endl;
				}
			}
			break;
		case 3:
			if (num_students == 0)
			{
				std::cout << "The contact list is empty!" << std::endl;
				std::cout << std::endl;
				break;
			}


			std::cout << "	Select what you want to display" << std::endl;
			std::cout << "	1. All names" << std::endl;
			std::cout << "	2. All emails" << std::endl;
			std::cout << "	3. All ages" << std::endl;
			std::cout << "	4. Exit" << std::endl;

			while(choice_1_print != 4)
			{
				std::cout << "Your choice: ";
				std::cin >> choice_1_print;

				switch (choice_1_print)
				{
				case 1:
					for (int i = 0; i < num_students; i++)
					{
						std::cout << students[i]->Get_name();
						std::cout << std::endl;
					}
					break;
				case 2:
					for (int i = 0; i < num_students; i++)
					{
						std::cout << students[i]->Get_email();
						std::cout << std::endl;
					}
					break;
				case 3:
					for (int i = 0; i < num_students; i++)
					{
						std::cout << students[i]->Get_age();
						std::cout << std::endl;
					}
					break;
				case 4:
					break;
				default:
					std::cout << "Incorrect choice!" << std::endl;
					std::cout << std::endl;
					break;
				}
			} 
			break;

		case 4:
			return 0;
			break;
		default:
			std::cout << "Incorrect choice!" << std::endl;
			std::cout << std::endl;
			break;
		}
		std::cout << std::endl;
	}while (true);


	//из за того что мы создали обьекты students с помошью new, то есть динамю память задействована

	for (int i = 0; i < num_students; i++)
	{
		if (students[i] != nullptr) { delete students[i]; }
	}

	return 0;
}
