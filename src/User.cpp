#include "User.h"
#include "Utils.h"
#include <iostream>

User::User(const std::string& user)
    : username(user), rewardCount(0), credential(user), balance(0) {}

bool User::authenticate(const std::string& password) {
    return credential.authenticate(password);
}

void User::setPassword(const std::string& password) {
    credential.setPassword(password);
}

void User::addTransaction(Transaction* t) {
    manager.addTransaction(t);
    if (t->getCategory().getType() == "Income") balance += t->getAmount();
    else balance -= t->getAmount();
}

void User::addBudget(const Budget& b) {
    budgets.push_back(b);
}

void User::saveBalance() {
    std::cout << "Balance saved: " << balance << std::endl;
}

void User::receiveReward(const std::string& reward) {
    rewards.push_back(reward);
    rewardCount++;
    std::cout << "Received reward: " << reward << std::endl;
}

void User::displayRewards() const {
    std::cout << "Rewards:\n";
    for (const auto& r : rewards) std::cout << "- " << r << std::endl;
}

void User::checkBudgetStatus() const {
    for (const auto& b : budgets) b.displayStatus();
    Utils::alertOverspending(budgets);
}

void User::generateBudget(const std::string& type) {
    std::cout << "Generated budget of type: " << type << std::endl;
}

void User::operations() {
    std::cout << "Operations: Add, View, Export, Import, etc.\n";
}

void User::makeInvestment() {
    std::cout << "Making investment (demo)...\n";
}

void User::showBudgets() const {
    for (const auto& b : budgets) b.displayStatus();
}

void User::showGoals() const {
    manager.displayAllGoals();
}

void User::showInvestments() const {
    for (const auto& i : manager.getInvestments()) i->display();
}

void User::showTransactions() const {
    for (const auto& t : manager.getTransactions()) t->display();
}

void User::showReports() const {
    for (const auto& r : reports) r.display();
}

void User::addGoal(const std::string& name, double target, const std::string& deadline) {
    manager.addSavingGoal(name, target, deadline);
}

void User::allocateToGoal(const std::string& name, double amount) {
    manager.allocateToGoal(name, amount);
}

void User::exportTransactions(const std::string& filename) const {
    Utils::exportCSV(manager.getTransactions(), filename);
}

void User::importTransactions(const std::string& filename) {
    // Note: This will only add to the manager's transactions, not update balance or budgets.
    std::vector<Transaction*>& txs = const_cast<std::vector<Transaction*>&>(manager.getTransactions());
    Utils::importCSV(txs, filename);
}

void User::backupData(const std::string& filename) const {
    Utils::backup(filename);
}

void User::restoreData(const std::string& filename) {
    Utils::restore(filename);
}

double User::getBalance() const { return balance; }
std::string User::getUsername() const { return username; }

// --- Implement the public getters here ---
const FinanceManager& User::getManager() const {
    return manager;
}

const std::vector<Budget>& User::getBudgets() const {
    return budgets;
}