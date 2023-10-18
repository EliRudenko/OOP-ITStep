#include "Mouse.h"

Mouse::Mouse() {}

Mouse::Mouse(const std::string& inputN) : mouse_n(inputN) {}

void Mouse::set_mouse_n(const std::string& inputN) { mouse_n = inputN; }

const std::string& Mouse::get_mouse_n() const { return mouse_n; }

Mouse::~Mouse() {}
