#include "Exception.h"

Exception::Exception(const std::string& m) : message(m) {}

const std::string& Exception::m() const { return message; }
