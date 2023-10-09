#pragma once

#include <string>

struct Security 
{
    static std::string encryptPassword(const std::string& password); // Шифрование пароля.
    static std::string decryptPassword(const std::string& encryptedPassword); // Дешифрование пароля.
};
