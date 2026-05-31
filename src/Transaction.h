#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "Category.h"

class Transaction {
protected:
    double amount;
    std::string date;
    std::string description;
    Category category;
public:
    Transaction(double amt, const std::string& d, const std::string& desc, const Category& cat);
    virtual void display() const;
    double getAmount() const;
    std::string getDate() const;
    std::string getDescription() const;
    Category getCategory() const;
    virtual ~Transaction() {}
};

#endif