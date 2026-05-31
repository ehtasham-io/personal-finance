#include "Transaction.h"
#include <iostream>

Transaction::Transaction(double amt, const std::string& d, const std::string& desc, const Category& cat)
    : amount(amt), date(d), description(desc), category(cat) {}

void Transaction::display() const {
    std::cout << date << " | " << description << " | " << category.getName() << " | " << amount << std::endl;
}

double Transaction::getAmount() const { return amount; }
std::string Transaction::getDate() const { return date; }
std::string Transaction::getDescription() const { return description; }
Category Transaction::getCategory() const { return category; }