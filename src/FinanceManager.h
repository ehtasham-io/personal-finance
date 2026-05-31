#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <vector>
#include <string>
#include "Transaction.h"
#include "Investment.h"
#include "SavingsGoal.h"

class FinanceManager {
    std::vector<Transaction*> transactions;
    std::vector<Investment*> investments;
    std::vector<SavingsGoal> goals;
public:
    void addTransaction(Transaction* t);
    void addInvestment(Investment* i);
    void addSavingGoal(const std::string& name, double target, const std::string& deadline);
    void allocateToGoal(const std::string& goalName, double amount);
    void displayAllGoals() const;
    void checkAllMilestones() const;
    void displayRecord(double balance) const;
    const std::vector<Transaction*>& getTransactions() const;
    const std::vector<Investment*>& getInvestments() const;
    std::vector<SavingsGoal>& getGoals();
};

#endif