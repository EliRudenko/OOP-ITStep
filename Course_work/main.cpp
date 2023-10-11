#include<iostream>

#include "User.cpp"
#include "Admin.cpp"

int main() 
{
    int mode = User::getModeFromUser();

    if (mode == 1) {
        User user("", "", "", "", ""); // Создаем пустого пользователя
        user.register_user(); // Регистрация пользователя

        bool authorized = user.authorize(); // Авторизация пользователя

        if (authorized) {
            std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
        } else {
            std::cout << "Invalid credentials." << std::endl;
        }
    } else if (mode == 2) {
        Admin admin("admin", "admin123"); // Создаем админа с логином и паролем по умолчанию

        bool authorized = admin.authorize_admin("admin", "admin123"); // Авторизация администратора

        if (authorized) {
            std::cout << "Welcome, Admin!" << std::endl;

            int action;
            do {
                std::cout << "Select action (1 - Change Password, 2 - Change Login, 0 - Quit): ";
                std::cin >> action;

                switch (action) {
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
                        break;
                    default:
                        std::cout << "Invalid action. Try again." << std::endl;
                }
            } while (action != 0);
        } else {
            std::cout << "Invalid credentials." << std::endl;
        }
    }

    return 0;
}




/*
int main() 
{
    int mode = User::getModeFromUser();

    if (mode == 1) 
    {
        // Режим пользователя
        User user("johndoe", "password123", "John Doe", "123 Main St", "555-1234");
        user.register_user(); // Регистрация пользователя
        bool authorized = user.authorize(); // Авторизация пользователя

        if (authorized) {
            std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
        } else { std::cout << "Invalid credentials." << std::endl; }

    } 
    else if (mode == 2) 
    {
        // Режим администратора
        Admin admin("admin", "admin123");
        bool authorized = admin.authorize(); // Авторизация администратора

        if (authorized) 
        {
            std::cout << "Welcome, Admin!" << std::endl;
            int action;

            do 
            {
                std::cout << "Select action (1 - Change Password, 2 - Change Login, 3 - Manage Users, 4 - View Statistics, 5 - Manage Testing, 6 - Import/Export, 0 - Quit): ";
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

                    case 3:
                        admin.manage_users();
                        break;
                    case 4:
                        admin.view_statistics();
                        break;
                    case 5:
                        admin.manage_testing();
                        break;
                    case 6:
                        admin.import_export_categories_tests();
                        break;
                    case 0:
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

    return 0;
}
*/