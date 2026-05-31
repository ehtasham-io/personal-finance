#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "User.h"
#include "Income.h"
#include "Expenditure.h"
#include "RecurringTransaction.h"
#include "SIP.h"
#include "FD.h"
#include "Utils.h"
#include "Credential.h"

// Helper to load transactions from file
void loadUserTransactions(User& user, const std::string& username) {
    std::string txFile = username + "_transactions.csv";
    user.importTransactions(txFile);
}

// Helper to save transactions to file
void saveUserTransactions(const User& user, const std::string& username) {
    std::string txFile = username + "_transactions.csv";
    user.exportTransactions(txFile);
}

// Helper to load budgets from file
void loadUserBudgets(User& user, const std::string& username) {
    std::string budgetFile = username + "_budgets.csv";
    std::ifstream file(budgetFile);
    if (!file) return;
    std::string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string cat, limStr, spentStr;
        double lim, spent;
        getline(ss, cat, ',');
        getline(ss, limStr, ',');
        getline(ss, spentStr, ',');
        lim = std::stod(limStr);
        spent = std::stod(spentStr);
        Budget b(cat, lim);
        b.addExpenditure(spent); // restore spent
        user.addBudget(b);
    }
    file.close();
}

// Helper to save budgets to file
void saveUserBudgets(const User& user, const std::string& username) {
    std::string budgetFile = username + "_budgets.csv";
    std::ofstream file(budgetFile);
    file << "Category,Limit,Spent\n";
    for (const auto& b : user.getBudgets()) {
        file << b.getCategory() << "," << b.getLimit() << "," << b.getSpent() << "\n";
    }
    file.close();
}

int main() {
    std::string username, password;
    int choice;
    std::cout << "1. Register\n2. Login\nChoice: ";
    std::cin >> choice;
    std::cin.ignore();

    bool authenticated = false;
    User user;
    while (!authenticated) {
        if (choice == 1) {
            std::cout << "Register\nUsername: ";
            std::getline(std::cin, username);
            std::cout << "Password: ";
            std::getline(std::cin, password);
            Credential cred(username);
            cred.setPassword(password);
            if (cred.saveToFile()) {
                std::cout << "Registration successful! Please login.\n";
                choice = 2;
            } else {
                std::cout << "Registration failed! Try again.\n";
                continue;
            }
        }
        if (choice == 2) {
            std::cout << "Login\nUsername: ";
            std::getline(std::cin, username);
            std::cout << "Password: ";
            std::getline(std::cin, password);
            if (Credential::authenticateFromFile(username, password)) {
                std::cout << "Login successful!\n";
                user = User(username);
                authenticated = true;
                // Load user data
                loadUserTransactions(user, username);
                loadUserBudgets(user, username);
            } else {
                std::cout << "Login failed! Try again.\n";
                std::cout << "1. Register\n2. Login\nChoice: ";
                std::cin >> choice;
                std::cin.ignore();
            }
        }
    }

    // Main menu loop
    do {
        std::cout << "\n==== Personal Finance Manager ====\n";
        std::cout << "1. Add Income\n";
        std::cout << "2. Add Expense\n";
        std::cout << "3. Add Recurring Transaction\n";
        std::cout << "4. Show Transactions\n";
        std::cout << "5. Add Budget\n";
        std::cout << "6. Show Budgets\n";
        std::cout << "7. Add Savings Goal\n";
        std::cout << "8. Allocate to Goal\n";
        std::cout << "9. Show Goals\n";
        std::cout << "10. Make Investment\n";
        std::cout << "11. Show Investments\n";
        std::cout << "12. Export Transactions (CSV)\n";
        std::cout << "13. Import Transactions (CSV)\n";
        std::cout << "14. Backup Data\n";
        std::cout << "15. Restore Data\n";
        std::cout << "16. Show Pie Chart\n";
        std::cout << "17. Show Trend Graph\n";
        std::cout << "18. Show Budget Graph\n";
        std::cout << "19. Financial Tips\n";
        std::cout << "20. AI Chatbot\n";
        std::cout << "21. Voice Command\n";
        std::cout << "22. Subscription Manager\n";
        std::cout << "23. Insurance Planner\n";
        std::cout << "24. Coming Soon\n";
        std::cout << "0. Exit\n";
        std::cout << "==================================\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            double amt;
            std::string date, desc, cat;
            std::cout << "Amount: "; std::cin >> amt; std::cin.ignore();
            std::cout << "Date (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "Description: "; std::getline(std::cin, desc);
            std::cout << "Category: "; std::getline(std::cin, cat);
            user.addTransaction(new Income(amt, date, desc, Category(cat, "Income")));
            saveUserTransactions(user, username);
        } else if (choice == 2) {
            double amt;
            std::string date, desc, cat;
            std::cout << "Amount: "; std::cin >> amt; std::cin.ignore();
            std::cout << "Date (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "Description: "; std::getline(std::cin, desc);
            std::cout << "Category: "; std::getline(std::cin, cat);
            user.addTransaction(new Expenditure(amt, date, desc, Category(cat, "Expense")));
            saveUserTransactions(user, username);
        } else if (choice == 3) {
            double amt;
            std::string date, desc, cat, freq;
            std::cout << "Amount: "; std::cin >> amt; std::cin.ignore();
            std::cout << "Date (YYYY-MM-DD): "; std::getline(std::cin, date);
            std::cout << "Description: "; std::getline(std::cin, desc);
            std::cout << "Category: "; std::getline(std::cin, cat);
            std::cout << "Frequency: "; std::getline(std::cin, freq);
            user.addTransaction(new RecurringTransaction(amt, date, desc, Category(cat, "Expense"), freq));
            saveUserTransactions(user, username);
        } else if (choice == 4) {
            user.showTransactions();
        } else if (choice == 5) {
            std::string cat;
            double lim;
            std::cout << "Category: "; std::getline(std::cin, cat);
            std::cout << "Limit: "; std::cin >> lim; std::cin.ignore();
            user.addBudget(Budget(cat, lim));
            saveUserBudgets(user, username);
        } else if (choice == 6) {
            user.showBudgets();
        } else if (choice == 7) {
            std::string name, deadline;
            double target;
            std::cout << "Goal Name: "; std::getline(std::cin, name);
            std::cout << "Target Amount: "; std::cin >> target; std::cin.ignore();
            std::cout << "Deadline: "; std::getline(std::cin, deadline);
            user.addGoal(name, target, deadline);
        } else if (choice == 8) {
            std::string name;
            double amt;
            std::cout << "Goal Name: "; std::getline(std::cin, name);
            std::cout << "Amount to allocate: "; std::cin >> amt; std::cin.ignore();
            user.allocateToGoal(name, amt);
        } else if (choice == 9) {
            user.showGoals();
        } else if (choice == 10) {
            double amt;
            std::string date, desc, type;
            std::cout << "Amount: "; std::cin >> amt; std::cin.ignore();
            std::cout << "Date: "; std::getline(std::cin, date);
            std::cout << "Description: "; std::getline(std::cin, desc);
            std::cout << "Type (SIP/FD): "; std::getline(std::cin, type);
            if (type == "SIP") {
                double monthly;
                std::cout << "Monthly: "; std::cin >> monthly; std::cin.ignore();
                user.makeInvestment();
            } else if (type == "FD") {
                user.makeInvestment();
            }
        } else if (choice == 11) {
            user.showInvestments();
        } else if (choice == 12) {
            std::string filename = username + "_transactions.csv";
            user.exportTransactions(filename);
        } else if (choice == 13) {
            std::string filename = username + "_transactions.csv";
            user.importTransactions(filename);
        } else if (choice == 14) {
            std::string filename = username + "_backup.dat";
            user.backupData(filename);
        } else if (choice == 15) {
            std::string filename = username + "_backup.dat";
            user.restoreData(filename);
        } else if (choice == 16) {
            Utils::drawPieChart(user.getManager().getTransactions());
        } else if (choice == 17) {
            Utils::drawTrendGraph(user.getManager().getTransactions());
        } else if (choice == 18) {
            Utils::drawBudgetGraph(user.getBudgets());
        } else if (choice == 19) {
            Utils::financialTips();
        } else if (choice == 20) {
            Utils::chatbot();
        } else if (choice == 21) {
            Utils::voiceCommand();
        } else if (choice == 22) {
            Utils::subscriptionManager();
        } else if (choice == 23) {
            Utils::insurancePlanner();
        } else if (choice == 24) {
            Utils::comingSoon();
        }
    } while (choice != 0);

    // Save user data on exit
    saveUserTransactions(user, username);
    saveUserBudgets(user, username);

    std::cout << "Thank you for using Personal Finance Manager!\n";
    return 0;
}