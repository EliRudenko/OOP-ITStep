#pragma once
#include <string>

class Exception 
{
private:
    std::string message;

public:
    Exception(const std::string& m);
    const std::string& m() const;
};
