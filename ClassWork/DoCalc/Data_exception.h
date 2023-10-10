#pragma once
#include "Exception.h"

class Data_exception : public Exception 
{
public:
    Data_exception(const std::string& m);
};
