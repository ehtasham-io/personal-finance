#include "Category.h"

Category::Category(const std::string& n, const std::string& t) : name(n), type(t) {}

std::string Category::getName() const { return name; }
std::string Category::getType() const { return type; }
void Category::setName(const std::string& n) { name = n; }
void Category::setType(const std::string& t) { type = t; }