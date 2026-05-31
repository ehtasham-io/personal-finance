#include "SIP.h"
#include <iostream>

SIP::SIP(double amt, const std::string& d, const std::string& desc, double m)
    : Investment(amt, d, desc), monthly(m) {}

void SIP::display() const {
    std::cout << "[SIP] ";
    Investment::display();
    std::cout << "Monthly: " << monthly << std::endl;
}

double SIP::maturityAmount() const {
    // Simple calculation for demo
    return amount + (monthly * 12 * 0.08);
}