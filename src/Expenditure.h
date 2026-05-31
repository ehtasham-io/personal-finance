#ifndef EXPENDITURE_H
#define EXPENDITURE_H
#include "Transaction.h"

class Expenditure : public Transaction {
public:
    Expenditure(double amt, const std::string& d, const std::string& desc, const Category& cat);
    void display() const override;
};

#endif