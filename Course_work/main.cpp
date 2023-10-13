#include<iostream>


#include "User.cpp"
#include "Admin.cpp"
#include "User_interface.cpp"

int main() 
{
    UserInterface users;
    users.for_main();
}



/*
//ПЕРЕНЕСЕНО В КЛАСС
//оставила для возссожной проверки при поломках, для уверенности

int main() 
{
    User user("", "", "", "", ""); 
    Admin admin("", ""); 

    bool isAdmin = false; 

    while (true) 
    {
        int mode = User::getModeFromUser();

        if (mode == 1 && !isAdmin) 
        {
            user.register_user(); 
            std::cout << std::endl;
            bool authorized = user.authorize(); 

            if (authorized) 
            {
                std::cout << "Welcome, " << user.getFullName() << "!" << std::endl;
            } 
            else {  std::cout << "Invalid credentials!" << std::endl; }

        } 
        else if (mode == 2 ) //&& !admin.isAuthorized()
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

        std::cout << "Exit? (Y/N)? ";
        char choice;
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') { break; }
    }

    return 0;
}
*/