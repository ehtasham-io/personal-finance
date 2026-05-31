#ifndef RECURRINGTRANSACTION_H
#define RECURRINGTRANSACTION_H
#include "Transaction.h"

class RecurringTransaction : public Transaction {
    std::string frequency;
public:
    RecurringTransaction(double amt, const std::string& d, const std::string& desc, const Category& cat, const std::string& freq);
    void scheduleNext();
    void display() const override;
};

#endif