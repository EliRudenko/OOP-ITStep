#include "Security.h"
#include <iostream>

std::string Security::encrypt_password(const std::string& password) {
    // Пример простого шифрования (замена каждого символа на следующий в ASCII таблице)
    std::string encryptedPassword = password;
    for (char& c : encryptedPassword) {
        c++;
    }
    return encryptedPassword;
}

std::string Security::decrypt_password(const std::string& encryptedPassword) {
    // Обратная операция - дешифрование
    std::string password = encryptedPassword;
    for (char& c : password) {
        c--;
    }
    return password;
}
