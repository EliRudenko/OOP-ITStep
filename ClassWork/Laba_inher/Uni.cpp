#include "Uni.h"

University::University(std::string name, std::string faculty) : name(name), faculty(faculty) {}

std::string University::getName() const { return name; }

std::string University::getFaculty() const { return faculty; }

void University::setName(const std::string& newName) { name = newName; }

void University::setFaculty(const std::string& newFaculty) { faculty = newFaculty; }
