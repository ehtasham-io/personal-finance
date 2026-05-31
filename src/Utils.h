#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include "Transaction.h"
#include "Budget.h"
#include "SavingsGoal.h"
#include "Investment.h"

namespace Utils {
    void exportCSV(const std::vector<Transaction*>& transactions, const std::string& filename);
    void importCSV(std::vector<Transaction*>& transactions, const std::string& filename);
    void drawPieChart(const std::vector<Transaction*>& transactions);
    void drawTrendGraph(const std::vector<Transaction*>& transactions);
    void drawBudgetGraph(const std::vector<Budget>& budgets);
    void alertOverspending(const std::vector<Budget>& budgets);
    void analyzeSpending(const std::vector<Transaction*>& transactions);
    void loanCalculator();
    void taxEstimator();
    void currencyConverter();
    void backup(const std::string& filename);
    void restore(const std::string& filename);
    void encryptData(const std::string& filename, char key = 0xAA);
    void decryptData(const std::string& filename, char key = 0xAA);
    void financialTips();
    void chatbot();
    void voiceCommand();
    void subscriptionManager();
    void insurancePlanner();
    void comingSoon();
}

#endif