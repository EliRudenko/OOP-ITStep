#include "Keyboard.h"

Keyboard::Keyboard() {}

Keyboard::Keyboard(const std::string& inputType) : keyboard_type(inputType) {}

void Keyboard::set_keyboard_type(const std::string& inputType) { keyboard_type = inputType; }

const std::string& Keyboard::get_keyboard_type() const { return keyboard_type; }

Keyboard::~Keyboard() {}
