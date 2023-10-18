
#pragma once

#include <string>

class University 
{
private:
    std::string name;
    std::string faculty;
    
public:
    University(std::string name, std::string faculty);
    std::string getName() const;
    std::string getFaculty() const;
    void setName(const std::string& name);
    void setFaculty(const std::string& faculty);

};

