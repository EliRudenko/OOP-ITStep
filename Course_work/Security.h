#pragma once

#include <string>

struct Security 
{
    static std::string encrypt_password(const std::string& password); //шифрование пароля
    static std::string decrypt_password(const std::string& encryptedPassword); //дешифрование пароля
};


