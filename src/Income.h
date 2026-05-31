#ifndef INCOME_H
#define INCOME_H
#include "Transaction.h"

class Income : public Transaction {
public:
    Income(double amt, const std::string& d, const std::string& desc, const Category& cat);
    void display() const override;
};

#endif