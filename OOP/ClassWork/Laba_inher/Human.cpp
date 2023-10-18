#include "Human.h"

Human::Human(std::string name, int age) : name(name), age(age) {}

std::string Human::getName() const { return name; }

int Human::getAge() const { return age; }

void Human::setName(const std::string& newName) { name = newName; }

void Human::setAge(int newAge) { age = newAge; }
