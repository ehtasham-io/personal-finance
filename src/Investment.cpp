#include "Investment.h"
#include <iostream>

Investment::Investment(double amt, const std::string& d, const std::string& desc)
    : amount(amt), date(d), description(desc) {}

void Investment::display() const {
    std::cout << "Investment: " << description << " | Amount: " << amount << " | Date: " << date << std::endl;
}

double Investment::maturityAmount() const {
    // Simple interest for demo
    return amount * 1.05;
}