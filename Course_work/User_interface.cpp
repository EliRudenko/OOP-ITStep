#include <iostream>
#include <vector>

#include "User_interface.h"
#include "Test_interface.h"
#include "User.h"
#include "Admin.h"


std::vector<User> UserInterface::registeredUsers; //ВЕКТОР ЗАРЕГАНЫХ ПОЛЬЗОВАТЕЛЕЙ
Admin UserInterface::admin; //обьект админ
bool UserInterface::isAdmin = false; // контроль входа админа

void UserInterface::for_main() 
{
    while (true) 
    {
        std::cout << std::endl;
        int mode = User::getModeFromUser(); // РЕЖИМ (Пользователь, Админ)

        if (mode == 1 && !isAdmin) //вошел НЕ как админ 
        {
            handleUserMode(); // для ПОЛЬЗОВАТЕЛЯ
        } 
        else if (mode == 2) { handleAdminMode(); } // ВДМИН

        if (askToExit()) { break; } // выход
    }
}

void UserInterface::handleUserMode() 
{
    std::string choice;
    do 
    {
        std::cout << "--------------------" << std::endl;
        std::cout << "1. Register" << std::endl; 
        std::cout << "2. Login" << std::endl;
        std::cout << "3. Take a test" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "--------------------" << std::endl;
        
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == "1") 
        {
            std::cout << std::endl;
            User newUser; // новый объект User
            newUser.register_user(); //РЕШИСТРАЦИЯ НОВОГО ПОЛЬЗОВАТЕЛЯ
            registeredUsers.push_back(newUser); // добавляется в вектор зареганных пользователей
            std::cout << std::endl;
        } 
        else if (choice == "2") 
        {
            std::cout << std::endl;
            bool authorized = false; // покажет прошел ли авторизацию
            std::string login, password; // хранение данных

            for (User& user : registeredUsers)  //!!! ПЕРЕБОР ВСЕХ ЗАРЕГАННХ ПОЛЬЗОВАТЕЛЕЙ
            {
                if (user.authorize()) //для каждого пользователя вызывается
                {
                    authorized = true;  // если попал в условие значит все ок
                    std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
                    chooseActionAfterAuthorization(); //ДЕЙСТВИЯ
                    break;
                }
            }

            if (!authorized) { std::cout << "Invalid credentials!" << std::endl; } //анлаки
        } 
        else if (choice == "3") 
        {
            TestInterface testInterface;
            testInterface.startTesting(); //!!! ТЕСТИРОВАНИЕ
            break;
        } 
        else if (choice == "0")
        {
             break;
        } 
        else { std::cout << "Invalid choice!" << std::endl; }

    } while (true);
}

void UserInterface::handleAdminMode() //АДМИН
{
    if (admin.getPassword().empty()) //Админ входит первый раз
    {
        //установка данных для входа
        std::string login = User::getStringFromUser("Set admin login: ");
        std::string password = User::getStringFromUser("Set admin password: ");
        admin.setLogin(login);
        admin.setPassword(password);
    }

    std::cout << std::endl;
    std::cout << "Authorize admin: " << std::endl; //ВХОД
    std::string login = User::getStringFromUser("Enter admin login: ");
    std::string password = User::getStringFromUser("Enter admin password: ");

    if (admin.authorize_admin(login, password)) //совпадают ли данные (введенные с сохраненными для админа)
    {
        isAdmin = true; //АДМИН ЗАШЕЛ
        std::cout << "Welcome, Admin!" << std::endl;
        chooseActionAfterAuthorization(); //ДЕЙСТВИЯ
    } 
    else { std::cout << "Invalid credentials!" << std::endl; }

    std::cout << std::endl;
}

bool UserInterface::askToExit() 
{
    std::string choice;
    std::cout << "Exit? (Y/N): ";
    std::cin >> choice;

    return (choice == "Y" || choice == "y");
}


void UserInterface::chooseActionAfterAuthorization() //ЖЕЙСТЫИЯ
{
    if (isAdmin) //ДЛЯ АДМИНА
    {
        std::string choice;
        do 
        {
            std::cout << "------------------------" << std::endl;
            std::cout << "1. Perform admin actions" << std::endl; 
            std::cout << "2. Login out" << std::endl;
            std::cout << "0. Back to main menu" << std::endl;
            std::cout << "------------------------" << std::endl;
        
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            if (choice == "1") 
            {
                performAdminActions(); // опции только для него
            } 
            else if (choice == "2") 
            {
                isAdmin = false; // мадмин вышел
                break;
            } 
            else if (choice == "0") 
            {
                break;
            } 
            else { std::cout << "Invalid choice" << std::endl; }

        } while (true);
    } 
    else //ПОЛЬЗОВАТЕЛЬ
    {
        std::string choice;
        do 
        {
            std::cout << "--------------------" << std::endl;
            std::cout << "1. Take a test" << std::endl; 
            std::cout << "0. Back to main menu" << std::endl;
            std::cout << "--------------------" << std::endl;
        
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cout << std::endl;
            
            if (choice == "1") 
            {
                TestInterface testInterface;
                testInterface.startTesting(); //ТЕСТИРОВАНИЕ
                break;
            } 
            else if (choice == "0") 
            {
                break;
            } 
            else { std::cout << "Invalid choice!" << std::endl; }

        } while (true);
    }
}

void UserInterface::performAdminActions()  //ОПЙИИ ДЛЯ АДМИНА
{
    int action;
    do 
    {
        std::cout << "Select action: " << std::endl;
        std::cout << "1 - Create User, 2 - Remove User" << std::endl;
        std::cout << "3- Change Password, 3 - Change Login" << std::endl;
        std::cout << "4 - Add Category, 5 - Add Test to Category, 6 - Add Question to Test" << std::endl;
        std::cout << "0 - Logout" << std::endl;
        std::cout << "Enter: ";
        std::cin >> action;

        switch (action) 
        {
            case 1:  //НОВЫЙ ПОЛЬЗОВАТЕЛЬ
            {
                std::cout << std::endl;
                User newUser; //новый обьект пользователя
                newUser.register_user(); //регистрация
                registeredUsers.push_back(newUser); //ДОБАВЛЯЕТСЯ ПОЛЬЗОВАТЕЛЬ В ВЕКТОР ЗАРЕГАНЫХ ПОЛЬЗОВАТЕЛЕЙ
                std::cout << std::endl;
                break;
            }
            case 2: //У Д А Л Е Н И Е
            {
                std::string loginToDelete = User::getStringFromUser("Enter login of the user to delete: ");

                auto it = registeredUsers.begin();  //ИТЕРАТОР начало вектора registeredUsers
                bool userFound = false;  // найден ли пользователь с таким логином

                while (it != registeredUsers.end()) 
                {
                    if (it->getLogin() == loginToDelete) 
                    {
                        it = registeredUsers.erase(it); // УДАЛЯЕТСЯ пользователь, ИНТЕРАТОР НА СЛЕДУЮЩИЙ ЭЛЕМЕНТ
                        userFound = true; //пользователь НАЙДЕН
                    }
                    else{ ++it; }// логин не совпал идем дальше искать, следующий пользователь
                }

                if (userFound) //проверка найден ли, сообщение
                {
                    std::cout << "User successfully deleted!" << std::endl;
                }
                else{ std::cout << "User not found!" << std::endl; }

                break;

            }
            case 3:  //поменять пароль Админа
            {
                std::string newPassword = User::getStringFromUser("Enter new password: ");
                admin.change_admin_password(newPassword);
                std::cout << "Password changed successfully!" << std::endl;
                break;
            }
            case 4:  // поменять лониг Админа
            {
                std::string newLohin = User::getStringFromUser("Enter new login: ");
                admin.change_admin_login(newLohin);
                std::cout << "Login changed successfully!" << std::endl;
                break;
            }
            case 5:  //ДОБАВИТЬ КАТЕГОРИЮ ТЕСТА
            {
                std::string categoryName = User::getStringFromUser("Enter category name: ");
                admin.addCategory(categoryName);
                break;
            }
            case 6:  // ДОБАВИТЬ ТЕСТ  В КАТЕГОРИЮ ТЕСТА
            {
                std::string categoryName = User::getStringFromUser("Enter category name: ");
                std::string testName = User::getStringFromUser("Enter test name: ");
                admin.addTestToCategory(categoryName, testName); //добавляется тест в категорию
                break;
            }
            case 7: // ДОБАВИТЬ ВОПРОСЫ В ТЕСТА КАТЕГОРИИ
            {
                std::string categoryName = User::getStringFromUser("Enter category name: ");
                std::string testName = User::getStringFromUser("Enter test name: ");
                std::string questionText = User::getStringFromUser("Enter question text: ");
                
                std::vector<std::string> options;  // СОЗДАЕТСЯ ВЕКТОР ДЛЯ ВАРИКОВ ОТВЕТА
                int numOptions;
                std::cout << "Enter the number of options: ";
                std::cin >> numOptions;
                std::cin.ignore(); 
                for (int i = 0; i < numOptions; ++i) 
                {
                    std::string option = User::getStringFromUser("Enter option " + std::to_string(i+1) + ": ");
                    options.push_back(option); //ДОБАВЛЯЮТСЯ ВАРИКИ ОТВЕТОВ
                }
                char correctOption; // УКАЗЫВАЕТ ПРАВИЛЬНЫЙ ВАРИАНТ
                std::cout << "Enter correct option (A, B, C, etc.): ";
                std::cin >> correctOption;
                admin.addQuestionToTest(categoryName, testName, questionText, options, correctOption); // ВОПРОС ДОБАВЛЯЕТСЯ В ТЕСТ
                break;
            }
            case 0:
                isAdmin = false;
                break;
            default:
                std::cout << "Invalid action!" << std::endl;
        }

    } while (action != 0);
}