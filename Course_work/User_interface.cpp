#include <iostream>
#include <vector>

#include "User_interface.h"
#include "Test_interface.h"
#include "User.h"
#include "Admin.h"


std::vector<User> UserInterface::registeredUsers; 
Admin UserInterface::admin;
bool UserInterface::isAdmin = false;

void UserInterface::for_main() 
{
    while (true) 
    {
        std::cout << std::endl;
        int mode = User::getModeFromUser();

        if (mode == 1 && !isAdmin) 
        {
            handleUserMode();
        } 
        else if (mode == 2) { handleAdminMode(); }

        if (askToExit()) { break; }
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
            User newUser; // Создаем новый объект User
            newUser.register_user();
            registeredUsers.push_back(newUser); // Добавляем в вектор
            std::cout << std::endl;
        } 
        else if (choice == "2") 
        {
            std::cout << std::endl;
            bool authorized = false;
            std::string login, password;

            // Авторизация
            /*
            std::cout << "Enter login: ";
            std::cin >> login;
            std::cout << "Enter password: ";
            std::cin >> password;
            */

            for (User& user : registeredUsers) 
            {
                if (user.authorize()) 
                {
                    authorized = true;
                    std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
                    chooseActionAfterAuthorization();
                    break;
                }
            }

            if (!authorized) { std::cout << "Invalid credentials!" << std::endl; }
        } 
        else if (choice == "3") 
        {
            TestInterface testInterface;
            testInterface.startTesting();
            break;
        } 
        else if (choice == "0")
        {
             break;
        } 
        else { std::cout << "Invalid choice. Please try again." << std::endl; }

    } while (true);
}

void UserInterface::handleAdminMode() 
{
    if (admin.getPassword().empty()) 
    {
        std::string login = User::getStringFromUser("Set admin login: ");
        std::string password = User::getStringFromUser("Set admin password: ");
        admin.setLogin(login);
        admin.setPassword(password);
    }
    std::cout << std::endl;

    std::string login = User::getStringFromUser("Enter admin login: ");
    std::string password = User::getStringFromUser("Enter admin password: ");

    if (admin.authorize_admin(login, password)) 
    {
        isAdmin = true;
        std::cout << "Welcome, Admin!" << std::endl;
        chooseActionAfterAuthorization();
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


void UserInterface::chooseActionAfterAuthorization() 
{
    if (isAdmin) 
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
                performAdminActions();
            } 
            else if (choice == "2") 
            {
                isAdmin = false;
                break;
            } 
            else if (choice == "0") 
            {
                break;
            } 
            else { std::cout << "Invalid choice. Please try again." << std::endl; }

        } while (true);
    } 
    else 
    {
        std::string choice;
        do 
        {
            std::cout << "--------------------" << std::endl;
            std::cout << "1. Take a test" << std::endl; 
            std::cout << "2. Login out" << std::endl;
            std::cout << "0. Back to main menu" << std::endl;
            std::cout << "--------------------" << std::endl;
        
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            std::cout << std::endl;
            
            if (choice == "1") 
            {
                TestInterface testInterface;
                testInterface.startTesting();
                break;
            } 
            else if (choice == "2") 
            {
                break;
            } 
            else if (choice == "0") 
            {
                break;
            } 
            else { std::cout << "Invalid choice. Please try again." << std::endl; }

        } while (true);
    }
}

void UserInterface::performAdminActions() 
{
    int action;
    do 
    {
        std::cout << "Select action (1 - Create User, 2 - Change Password, 3 - Change Login, 4 - Add Category, 5 - Add Test to Category, 6 - Add Question to Test, 0 - Logout): ";
        std::cin >> action;

        switch (action) 
        {
            case 1: 
            {
                std::cout << std::endl;
                User newUser;
                newUser.register_user();
                registeredUsers.push_back(newUser);
                std::cout << std::endl;
                break;
            }
            case 2: 
            {
                std::string loginToDelete = User::getStringFromUser("Enter login of the user to delete: ");
                
                auto it = std::remove_if(registeredUsers.begin(), registeredUsers.end(), [loginToDelete](const User& user) {
                    return user.getLogin() == loginToDelete;
                });
                registeredUsers.erase(it, registeredUsers.end());
                std::cout << std::endl;
                break;
            }
            case 3: 
            {
                std::string newPassword = User::getStringFromUser("Enter new password: ");
                admin.change_admin_password(newPassword);
                std::cout << "Password changed successfully!" << std::endl;
                break;
            }
            case 4: 
            {
                std::string categoryName = User::getStringFromUser("Enter category name: ");
                admin.addCategory(categoryName);
                break;
            }
            case 5:
            {
                std::string categoryName = User::getStringFromUser("Enter category name: ");
                std::string testName = User::getStringFromUser("Enter test name: ");
                admin.addTestToCategory(categoryName, testName);
                break;
            }
            case 6:
            {
                std::string categoryName = User::getStringFromUser("Enter category name: ");
                std::string testName = User::getStringFromUser("Enter test name: ");
                std::string questionText = User::getStringFromUser("Enter question text: ");
                std::vector<std::string> options;
                int numOptions;
                std::cout << "Enter the number of options: ";
                std::cin >> numOptions;
                std::cin.ignore(); 
                for (int i = 0; i < numOptions; ++i) 
                {
                    std::string option = User::getStringFromUser("Enter option " + std::to_string(i+1) + ": ");
                    options.push_back(option);
                }
                char correctOption;
                std::cout << "Enter correct option (A, B, C, etc.): ";
                std::cin >> correctOption;
                admin.addQuestionToTest(categoryName, testName, questionText, options, correctOption);
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