#include <iostream>
#include <vector>

#include "User_interface.h"
#include "Test_interface.h"
#include "User.h"
#include "Admin.h"


UserInterface::UserInterface() { isAdmin = false; }

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
            user.register_user();
            std::cout << std::endl;
        } 
        else if (choice == "2") 
        {
            std::cout << std::endl;
            bool authorized = user.authorize();

            if (authorized) 
            {
                std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
                std::cout << std::endl;
                chooseActionAfterAuthorization();
                break;
            } 
            else { std::cout << "Invalid credentials!" << std::endl; }

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
        std::cout << "Welcome, Admin!" << std::endl;
        chooseActionAfterAuthorization();
    } 
    else { std::cout << "Invalid credentials!" << std::endl; }

    std::cout << std::endl;
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
        std::cout << "Select action (1 - Change Password, 2 - Change Login, 0 - Logout): ";
        std::cin >> action;

        switch (action) 
        {
            case 1: 
            {
                std::string newPassword = User::getStringFromUser("Enter new password: ");
                admin.change_admin_password(newPassword);
                std::cout << "Password changed successfully!" << std::endl;
                break;
            }
            case 2: 
            {
                std::string newLogin = User::getStringFromUser("Enter new login: ");
                admin.change_admin_login(newLogin);
                std::cout << "Login changed successfully!" << std::endl;
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

bool UserInterface::askToExit() 
{
    std::string choice;
    std::cout << "Exit? (Y/N): ";
    std::cin >> choice;

    return (choice == "Y" || choice == "y");
}
