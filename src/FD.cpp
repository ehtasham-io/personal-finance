#include "FD.h"
#include <iostream>

FD::FD(double amt, const std::string& d, const std::string& desc)
    : Investment(amt, d, desc) {}

void FD::display() const {
    std::cout << "[FD] ";
    Investment::display();
}

double FD::maturityAmount() const {
    // Fixed deposit, simple interest for demo
    return amount * 1.07;
}