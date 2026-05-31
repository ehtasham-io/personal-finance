#include "Budget.h"
#include <iostream>

Budget::Budget(const std::string& cat, double lim) : category(cat), limit(lim), spent(0) {}

void Budget::addExpenditure(double amt) {
    spent += amt;
}

void Budget::displayStatus() const {
    std::cout << "Budget for " << category << ": " << spent << "/" << limit;
    if (isOverrun()) std::cout << " [OVERRUN!]";
    std::cout << std::endl;
}

bool Budget::isOverrun() const {
    return spent > limit;
}

std::string Budget::getCategory() const { return category; }
double Budget::getLimit() const { return limit; }
double Budget::getSpent() const { return spent; }