#ifndef BUDGET_H
#define BUDGET_H
#include <string>

class Budget {
    std::string category;
    double limit;
    double spent;
public:
    Budget(const std::string& cat = "", double lim = 0);
    void addExpenditure(double amt);
    void displayStatus() const;
    bool isOverrun() const;
    std::string getCategory() const;
    double getLimit() const;
    double getSpent() const;
};

#endif