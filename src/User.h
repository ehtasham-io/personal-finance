#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "FinanceManager.h"
#include "Budget.h"
#include "Report.h"
#include "Credential.h"

class User {
    FinanceManager manager;
    std::vector<Budget> budgets;
    std::vector<Report> reports;
    std::vector<std::string> rewards;
    std::string username;
    int rewardCount;
    Credential credential;
    double balance;
public:
    User(const std::string& user = "");
    bool authenticate(const std::string& password);
    void setPassword(const std::string& password);
    void addTransaction(Transaction* t);
    void addBudget(const Budget& b);
    void saveBalance();
    void receiveReward(const std::string& reward);
    void displayRewards() const;
    void checkBudgetStatus() const;
    void generateBudget(const std::string& type);
    void operations();
    void makeInvestment();
    void showBudgets() const;
    void showGoals() const;
    void showInvestments() const;
    void showTransactions() const;
    void showReports() const;
    void addGoal(const std::string& name, double target, const std::string& deadline);
    void allocateToGoal(const std::string& name, double amount);
    void exportTransactions(const std::string& filename) const;
    void importTransactions(const std::string& filename);
    void backupData(const std::string& filename) const;
    void restoreData(const std::string& filename);
    double getBalance() const;
    std::string getUsername() const;

    // --- Add these public getters ---
    const FinanceManager& getManager() const;
    const std::vector<Budget>& getBudgets() const;
};

#endif