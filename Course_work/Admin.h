#pragma once

#include <string>
#include "User.h"

class Admin : public User 
{
public:

    Admin();
    Admin(const std::string& login, const std::string& encryptedPassword);

    bool authorize();

    bool authorize_admin(const std::string& inputLogin, const std::string& inputPassword);
    
    void change_admin_password(const std::string& newAdminPassword);
    void change_admin_login(const std::string& newAdminLogin);

    bool isAuthorized() const;


/*
    void manage_users(); 
    void view_statistics(); 
    void manage_testing();
    void import_export_categories_tests();
*/
   
    //const std::string& getEncryptedPassword() const;
    //void setEncryptedPassword(const std::string& newPassword);

};