#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>

class Investment {
protected:
    double amount;
    std::string date;
    std::string description;
public:
    Investment(double amt, const std::string& d, const std::string& desc);
    virtual void display() const;
    virtual double maturityAmount() const;
    virtual ~Investment() {}
};

#endif