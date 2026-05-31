#include "Income.h"
#include <iostream>

Income::Income(double amt, const std::string& d, const std::string& desc, const Category& cat)
    : Transaction(amt, d, desc, cat) {}

void Income::display() const {
    std::cout << "[INCOME] ";
    Transaction::display();
}