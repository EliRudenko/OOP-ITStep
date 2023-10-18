#pragma once
#include "Exception.h"

class Size_exception : public Exception 
{
public:
    Size_exception(const std::string& m);
};