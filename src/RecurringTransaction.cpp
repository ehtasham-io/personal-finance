#include "RecurringTransaction.h"
#include <iostream>

RecurringTransaction::RecurringTransaction(double amt, const std::string& d, const std::string& desc, const Category& cat, const std::string& freq)
    : Transaction(amt, d, desc, cat), frequency(freq) {}

void RecurringTransaction::scheduleNext() {
    std::cout << "Next transaction scheduled with frequency: " << frequency << std::endl;
}

void RecurringTransaction::display() const {
    std::cout << "[RECURRING] ";
    Transaction::display();
    std::cout << "Frequency: " << frequency << std::endl;
}