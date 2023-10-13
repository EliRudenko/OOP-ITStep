#include<iostream>
#include "User.cpp"
#include "Admin.cpp"



int main() 
{
    User user("", "", "", "", ""); // Создаем пустого пользователя
    Admin admin("", ""); // Создаем админа с пустым логином и паролем

    bool isAdmin = false; // Переменная, показывающая, является ли текущий пользователь администратором

    while (true) 
    {
        int mode = User::getModeFromUser();

        if (mode == 1 && !isAdmin) 
        {
            user.register_user(); // Регистрация пользователя
            std::cout << std::endl;
            bool authorized = user.authorize(); // Авторизация пользователя

            if (authorized) 
            {
                std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
            } 
            else {  std::cout << "Invalid credentials!" << std::endl; }

        } 
        else if (mode == 2 && !admin.isAuthorized()) 
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
            { // Авторизация админа
                std::cout << "Welcome, Admin!" << std::endl;
                isAdmin = true;

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
                        }
                            break;
                        case 2:
                        {
                            std::string newLogin = User::getStringFromUser("Enter new login: ");
                            admin.change_admin_login(newLogin);
                            std::cout << "Login changed successfully!" << std::endl;
                        }
                            break;
                        case 0:
                            isAdmin = false;
                            break;
                        default:
                            std::cout << "Invalid action!" << std::endl;
                    }

                } while (action != 0);
            } 
            else { std::cout << "Invalid credentials!" << std::endl; }

        }

        // Добавьте здесь логику для выхода из программы
        std::cout << "Exit? (Y/N)? ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') { break; }
    }

    return 0;
}



















/*
int main() 
{
    User user("", "", "", "", ""); // Создаем пустого пользователя
    Admin admin("", ""); // Создаем админа с пустым логином и паролем

    bool isAdmin = false; // Переменная, показывающая, является ли текущий пользователь администратором

    while (true) 
    {
        int mode = User::getModeFromUser();

        if (mode == 1 && !isAdmin) 
        {
            user.register_user(); // Регистрация пользователя
            bool authorized = user.authorize(); // Авторизация пользователя

            if (authorized) 
            {
                std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
                
            } 
            else { std::cout << "Invalid credentials." << std::endl; }
        } 
        else if (mode == 2 && !admin.isAuthorized()) 
        {
            if (admin.getEncryptedPassword().empty()) 
            {
                std::string login, password;
                std::cout << "Set admin login: ";
                std::cin >> login;
                std::cout << "Set admin password: ";
                std::cin >> password;
                admin.setLogin(login);
                //admin.setEncryptedPassword(password);
                admin.setEncryptedPassword(Security::encrypt_password(password));
            }

            std::string login, password;
            std::cout << "Enter admin login: ";
            std::cin >> login;
            std::cout << "Enter admin password: ";
            std::cin >> password;

            if (admin.authorize_admin(login, password))
            { // Авторизация админа
                std::cout << "Welcome, Admin!" << std::endl;
                isAdmin = true;

                int action;
                do 
                {
                    std::cout << "Select action (1 - Change Password, 2 - Change Login, 0 - Logout): ";
                    std::cin >> action;

                    switch (action) 
                    {
                        case 1:
                        {
                            std::string newPassword = User::getStringFromUser("Enter new encrypted password: ");
                            admin.change_admin_password(newPassword);
                            std::cout << "Password changed successfully!" << std::endl;
                        }
                            break;
                        case 2:
                        {
                            std::string newLogin = User::getStringFromUser("Enter new login: ");
                            admin.change_admin_login(newLogin);
                            std::cout << "Login changed successfully!" << std::endl;
                        }
                            break;
                        case 0:
                            isAdmin = false;
                            break;
                        default:
                            std::cout << "Invalid action. Try again." << std::endl;
                    }

                } while (action != 0);
            } 
            else { std::cout << "Invalid credentials." << std::endl; }
        }

        // Добавьте здесь логику для выхода из программы
        std::cout << "Do you want to exit (y/n)? ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') { break; }
    }

    return 0;
}
*/

/*

int main() 
{
    User user("", "", "", "", ""); // Создаем пустого пользователя
    Admin admin("", ""); // Создаем админа с пустым логином и паролем

    bool isAdmin = false; // Переменная, показывающая, является ли текущий пользователь администратором

    while (true) 
    {
        int mode = User::getModeFromUser();

        if (mode == 1 && !isAdmin) 
        {
            user.register_user(); // Регистрация пользователя
            bool authorized = user.authorize(); // Авторизация пользователя

            if (authorized) 
            {
                std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
                
            } 
            else 
            { 
                std::cout << "Invalid credentials." << std::endl; 
            }
        } 
        else if (mode == 2 && !admin.isAuthorized()) 
        {
            if (admin.getEncryptedPassword().empty()) 
            {
                std::string login, password;
                std::cout << "Set admin login: ";
                std::cin >> login;
                std::cout << "Set admin password: ";
                std::cin >> password;
                admin.setLogin(login);
                admin.setEncryptedPassword(Security::encrypt_password(password));
            }

            std::string login, password;
            std::cout << "Enter admin login: ";
            std::cin >> login;
            std::cout << "Enter admin password: ";
            std::cin >> password;

            if (admin.authorize_admin(login, password))
            { // Авторизация админа
                std::cout << "Welcome, Admin!" << std::endl;
                isAdmin = true;

                int action;
                do 
                {
                    std::cout << "Select action (1 - Change Password, 2 - Change Login, 0 - Logout): ";
                    std::cin >> action;

                    switch (action) 
                    {
                        case 1:
                        {
                            std::string newPassword = User::getStringFromUser("Enter new encrypted password: ");
                            admin.change_admin_password(newPassword);
                            std::cout << "Password changed successfully!" << std::endl;
                        }
                            break;
                        case 2:
                        {
                            std::string newLogin = User::getStringFromUser("Enter new login: ");
                            admin.change_admin_login(newLogin);
                            std::cout << "Login changed successfully!" << std::endl;
                        }
                            break;
                        case 0:
                            isAdmin = false;
                            break;
                        default:
                            std::cout << "Invalid action. Try again." << std::endl;
                    }

                } while (action != 0);
            } 
            else 
            { 
                std::cout << "Invalid credentials." << std::endl; 
            }
        }

        // Добавьте здесь логику для выхода из программы
        std::cout << "Do you want to exit (y/n)? ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') { break; }
    }

    return 0;
}
*/