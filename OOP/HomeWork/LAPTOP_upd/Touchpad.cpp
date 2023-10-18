#include "Touchpad.h"

Touchpad::Touchpad() {}

Touchpad::Touchpad(const std::string& inputType) : touchpad_type(inputType) {}

void Touchpad::set_touchpad_type(const std::string& inputType) { touchpad_type = inputType; }

const std::string& Touchpad::get_touchpad_type() const { return touchpad_type; }

Touchpad::~Touchpad() {}
