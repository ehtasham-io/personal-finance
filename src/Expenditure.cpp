#include "Expenditure.h"
#include <iostream>

Expenditure::Expenditure(double amt, const std::string& d, const std::string& desc, const Category& cat)
    : Transaction(amt, d, desc, cat) {}

void Expenditure::display() const {
    std::cout << "[EXPENSE] ";
    Transaction::display();
}