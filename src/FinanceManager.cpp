#include "FinanceManager.h"
#include <iostream>

void FinanceManager::addTransaction(Transaction* t) {
    transactions.push_back(t);
}

void FinanceManager::addInvestment(Investment* i) {
    investments.push_back(i);
}

void FinanceManager::addSavingGoal(const std::string& name, double target, const std::string& deadline) {
    goals.emplace_back(name, target, deadline);
}

void FinanceManager::allocateToGoal(const std::string& goalName, double amount) {
    for (auto& goal : goals) {
        if (goal.getGoalName() == goalName) {
            goal.addToGoal(amount);
            std::cout << "Allocated " << amount << " to goal: " << goalName << std::endl;
            return;
        }
    }
    std::cout << "Goal not found.\n";
}

void FinanceManager::displayAllGoals() const {
    for (const auto& goal : goals) {
        goal.displayProgress();
    }
}

void FinanceManager::checkAllMilestones() const {
    for (const auto& goal : goals) {
        std::string reward = goal.checkMilestones();
        if (!reward.empty()) {
            std::cout << "Goal: " << goal.getGoalName() << " - " << reward << std::endl;
        }
    }
}

void FinanceManager::displayRecord(double balance) const {
    std::cout << "Current Balance: " << balance << std::endl;
    std::cout << "Transactions:\n";
    for (const auto& t : transactions) t->display();
    std::cout << "Investments:\n";
    for (const auto& i : investments) i->display();
}

const std::vector<Transaction*>& FinanceManager::getTransactions() const { return transactions; }
const std::vector<Investment*>& FinanceManager::getInvestments() const { return investments; }
std::vector<SavingsGoal>& FinanceManager::getGoals() { return goals; }