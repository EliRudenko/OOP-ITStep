#include <iostream>

#include <algorithm>
//Использовала для:
//auto it = std::remove_if(registeredUsers.begin(), registeredUsers.end(),)
//std::remove_if УДАЛЯЕТ элементы соответствующие предикату по диапозону. УДАЛЕНИЕ ПОЛЬЗОВАТЕЛЯ ИЗ registeredUsers
//std::find_if НАХОДИТ первый элемент по диапозону, соответственно предикату. ПОИСК ПОЛЬЗОВАТЕЛЯ ПО ЛОГИНУ

#include "User.h"


// нициализация стат. переменной 
std::vector<User> User::registeredUsers; 
const int User::maxUsers; 

User::User() {}

User::User(const std::string& login, const std::string& password, const std::string& fullName, const std::string& address, const std::string& phone) 
    : login(login), password(password), full_name(fullName), address(address), phone(phone) {}

std::string User::getStringFromUser(const std::string& message) 
{//для ввода строк (пользователь)
    std::string input;
    std::cout << message;
    std::cin >> input;
    return input;
}

int User::getModeFromUser() 
{// "режим" (Пользователь Ажмин)
    int mode;
    std::cout << "Select mode (1 - User, 2 - Admin): ";
    std::cin >> mode;
    return mode;
}

//!!!_____________________

void User::register_user() 
{//РЕГИСТРАЦИЯ
    bool isUniqueLogin = false;

    while (!isUniqueLogin)  // пока логин НЕ уникальный
    {
        std::string newLogin = getStringFromUser("Enter login: ");

        if (isLoginTaken(newLogin)) // логин уже ссуществует
        {
            std::cout << "This login is already taken. Please choose another one." << std::endl;
        } 
        else
        {
            isUniqueLogin = true; // уникальный?  ДА
            login = newLogin; // логин
            
            password = getStringFromUser("Enter password: ");

            std::cout << "Enter full name: ";
            std::cin.ignore();
            std::getline(std::cin, full_name);

            while (true) //ПРОВЕРКА АДРЕСА
            {
                std::string address = User::getStringFromUser("Enter your email address: ");
                if (validateEmail(address)) // если все ок
                {
                    this->address = address; //адрес
                    break;
                } 
                else { std::cout << "Invalid email address format! " << std::endl; }
            }

            while (true)  // ПРОВЕРКА ТЕЛЕФОНА
            {
                std::string phone = User::getStringFromUser("Enter your phone number (+380 00 000 00 00): ");
                if (validatePhoneNumber(phone)) //если все ок
                {
                    this->phone = phone;
                    break;
                } 
                else { std::cout << "Invalid phone number format!" << std::endl; }
            }

            registeredUsers.push_back(*this); //ДОБАВЛЯЕМ ПОЛЬЗОВАТЕЛЯ (зарегистрирован)
        }
    }  
            
}

bool User::validateEmail(const std::string& email) 
{
    // найи символ для проверки того что ввел пользователь
    auto atIndex = std::find(email.begin(), email.end(), '@');
    auto dotIndex = std::find(email.rbegin(), email.rend(), '.');

    //ПРОВЕРКИ есть ли в адресе от пользователя нужные символы
    bool hasAt = (atIndex != email.end());
    bool hasDot = (dotIndex != email.rend());
    
    // ПОСЛЕДОВАТЕЛЬНОСТЬ (@ а потом .)
    bool dotAfterAt = (hasAt && hasDot && std::distance(atIndex, email.end()) > std::distance(dotIndex, email.rend())); 
    return dotAfterAt; // результат 
}



bool User::validatePhoneNumber(const std::string& phoneNumber) 
{//ПРОВЕРКА НОМЕРА
    return phoneNumber.find("+380") == 0 && phoneNumber.size() == 13; // начинается +380, сумма 13 цыфер, (0 это начало для сравление)
}




//!!!_________________

bool User::authorize()
{//ВХОД
    std::string inputLogin = getStringFromUser("Enter login: ");
    std::string inputPassword = getStringFromUser("Enter password: ");

    return (inputLogin == login && inputPassword == password); // если СОВПАДАЮТ (то что только что ввел и то что при регистрации) то true
}

bool User::isAuthorized() const { return !login.empty() && !password.empty(); } // если логин и пароль НЕ пустые - все ок

void User::setLogin(const std::string& newLogin) { login = newLogin; }

bool User::isLoginTaken(const std::string& login) 
{//ПОИСК В ВЕКТОРЕ
//const User& user - переменная в цикле, User тип элемента registeredUsers, user - тоже переменная, для текущего эелемента цикла
//константа потому что не надо изменять user
// двоеточия это диапазон, то есть диапазон для перебора тут registeredUsers
    for(const User& user : registeredUsers) 
    {
        if(user.login == login) { return true; }
    }
    return false;
}

std::string User::getFullName() const { return full_name; } // возврат имени пользователя

void User::setPassword(const std::string& newPassword) { password = newPassword; }

const std::string& User::getPassword() const { return password; } // вызврат, ТЕКУЩИЙ пароль

int User::getFinalScore() const { return finalScore; } // итоговый бал

std::string User::getLogin() const { return login; } 



//!!!_________________

void User::delete_user(const std::string& login) 
{
    auto it = registeredUsers.begin(); //ИТЕРАТОР начало вектора registeredUsers
    bool userFound = false; // найден ли пользователь с таким логином

    while (it != registeredUsers.end()) //ПЕРЕБОР всех Пользователей в ВЕКТОРЕ
    {
        if (it->login == login) //логин СОВПАДАЕТ
        {
            it = registeredUsers.erase(it); // УДАЛЯЕТСЯ пользователь, ИНТЕРАТОР НА СЛЕДУЮЩИЙ ЭЛЕМЕНТ
            userFound = true; //пользователь НАЙДЕН
        } else { ++it; }// логин не совпал идем дальше искать, следующий пользователь
    }

    if (userFound) //проверка найден ли, сообщение
    {
        std::cout << "User deleted successfully!" << std::endl;
    } 
    else { std::cout << "User not found!" << std::endl; }
}






