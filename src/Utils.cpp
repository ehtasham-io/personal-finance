#include "Utils.h"
#include "Expenditure.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>
#include <cmath>
#include <algorithm>

// Helper: Get current date as string
std::string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[20];
    sprintf(buf, "%04d-%02d-%02d", 1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
    return std::string(buf);
}

// CSV Export
void Utils::exportCSV(const std::vector<Transaction*>& transactions, const std::string& filename) {
    std::ofstream file(filename);
    file << "Date,Description,Category,Amount\n";
    for (const auto& t : transactions) {
        file << t->getDate() << ","
             << t->getDescription() << ","
             << t->getCategory().getName() << ","
             << t->getAmount() << "\n";
    }
    file.close();
    std::cout << "Exported to " << filename << std::endl;
}

// CSV Import (creates Expenditure by default, can be improved)
void Utils::importCSV(std::vector<Transaction*>& transactions, const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    getline(file, line); // skip header
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string date, desc, cat, amtStr;
        double amt;
        getline(ss, date, ',');
        getline(ss, desc, ',');
        getline(ss, cat, ',');
        getline(ss, amtStr, ',');
        amt = std::stod(amtStr);
        transactions.push_back(new Expenditure(amt, date, desc, Category(cat, "Expense")));
    }
    file.close();
    std::cout << "Imported from " << filename << std::endl;
}

// Pie Chart by Category
void Utils::drawPieChart(const std::vector<Transaction*>& transactions) {
    if (transactions.empty()) {
        std::cout << "No transactions to display.\n";
        return;
    }
    std::map<std::string, double> categoryTotals;
    double total = 0;
    for (const auto& t : transactions) {
        if (t->getCategory().getType() == "Expense") {
            categoryTotals[t->getCategory().getName()] += t->getAmount();
            total += t->getAmount();
        }
    }
    if (categoryTotals.empty()) {
        std::cout << "No expense transactions to display.\n";
        return;
    }
    std::cout << "Spending Pie Chart (ASCII):\n";
    for (const auto& pair : categoryTotals) {
        int bars = static_cast<int>((pair.second / total) * 40);
        std::cout << std::setw(12) << pair.first << " | ";
        for (int i = 0; i < bars; ++i) std::cout << "#";
        std::cout << " (" << pair.second << ")\n";
    }
}

// Monthly Trend Graph
void Utils::drawTrendGraph(const std::vector<Transaction*>& transactions) {
    if (transactions.empty()) {
        std::cout << "No transactions to display.\n";
        return;
    }
    std::map<std::string, double> monthTotals;
    for (const auto& t : transactions) {
        if (t->getCategory().getType() == "Expense") {
            std::string month = t->getDate().substr(0, 7); // YYYY-MM
            monthTotals[month] += t->getAmount();
        }
    }
    if (monthTotals.empty()) {
        std::cout << "No expense transactions to display.\n";
        return;
    }
    std::cout << "Monthly Trend Graph (ASCII):\n";
    for (const auto& pair : monthTotals) {
        int bars = static_cast<int>(pair.second / 10);
        std::cout << pair.first << " | ";
        for (int i = 0; i < bars; ++i) std::cout << "*";
        std::cout << " (" << pair.second << ")\n";
    }
}

// Budget vs. Actual Graph
void Utils::drawBudgetGraph(const std::vector<Budget>& budgets) {
    if (budgets.empty()) {
        std::cout << "No budgets to display.\n";
        return;
    }
    std::cout << "Budget vs. Actual Graph (ASCII):\n";
    for (const auto& b : budgets) {
        int spentBars = static_cast<int>(b.getSpent() / 10);
        int limitBars = static_cast<int>(b.getLimit() / 10);
        std::cout << std::setw(12) << b.getCategory() << " | ";
        for (int i = 0; i < spentBars; ++i) std::cout << "+";
        std::cout << " / ";
        for (int i = 0; i < limitBars; ++i) std::cout << "-";
        std::cout << " (" << b.getSpent() << "/" << b.getLimit() << ")";
        if (b.isOverrun()) std::cout << " [OVERRUN!]";
        std::cout << "\n";
    }
}

// Alerts on Overspending
void Utils::alertOverspending(const std::vector<Budget>& budgets) {
    for (const auto& b : budgets) {
        if (b.isOverrun()) {
            std::cout << "ALERT: Over budget in " << b.getCategory() << "!\n";
        }
    }
}

// AI-Based Spending Insights (simple logic)
void Utils::analyzeSpending(const std::vector<Transaction*>& transactions) {
    double total = 0, maxAmt = 0;
    std::string maxCat;
    std::map<std::string, double> catTotals;
    for (const auto& t : transactions) {
        if (t->getCategory().getType() == "Expense") {
            catTotals[t->getCategory().getName()] += t->getAmount();
            total += t->getAmount();
        }
    }
    for (const auto& pair : catTotals) {
        if (pair.second > maxAmt) {
            maxAmt = pair.second;
            maxCat = pair.first;
        }
    }
    if (catTotals.empty()) {
        std::cout << "No expense transactions for analysis.\n";
        return;
    }
    std::cout << "AI Insight: Your highest spending is in '" << maxCat << "' (" << maxAmt << ").\n";
    if (maxAmt > total * 0.5) {
        std::cout << "Consider reducing spending in this category.\n";
    }
}

// Loan Calculator
void Utils::loanCalculator() {
    double principal, rate, years;
    std::cout << "Enter principal: "; std::cin >> principal;
    std::cout << "Enter annual interest rate (%): "; std::cin >> rate;
    std::cout << "Enter years: "; std::cin >> years;
    double monthlyRate = rate / 12 / 100;
    int n = static_cast<int>(years * 12);
    double emi = (principal * monthlyRate * pow(1 + monthlyRate, n)) / (pow(1 + monthlyRate, n) - 1);
    std::cout << "Monthly EMI: " << emi << "\n";
}

// Tax Estimator
void Utils::taxEstimator() {
    double income, deductions;
    std::cout << "Enter annual income: "; std::cin >> income;
    std::cout << "Enter deductions: "; std::cin >> deductions;
    double taxable = income - deductions;
    double tax = 0;
    if (taxable <= 250000) tax = 0;
    else if (taxable <= 500000) tax = (taxable - 250000) * 0.05;
    else if (taxable <= 1000000) tax = 12500 + (taxable - 500000) * 0.2;
    else tax = 112500 + (taxable - 1000000) * 0.3;
    std::cout << "Estimated tax: " << tax << "\n";
}

// Currency Converter (fixed rates for demo)
void Utils::currencyConverter() {
    double amt;
    std::string from, to;
    std::cout << "Amount: "; std::cin >> amt;
    std::cout << "From (USD/EUR/INR): "; std::cin >> from;
    std::cout << "To (USD/EUR/INR): "; std::cin >> to;
    double rate = 1.0;
    if (from == "USD" && to == "INR") rate = 83.0;
    else if (from == "INR" && to == "USD") rate = 1.0 / 83.0;
    else if (from == "USD" && to == "EUR") rate = 0.92;
    else if (from == "EUR" && to == "USD") rate = 1.09;
    else if (from == "INR" && to == "EUR") rate = 0.011;
    else if (from == "EUR" && to == "INR") rate = 90.0;
    std::cout << amt << " " << from << " = " << amt * rate << " " << to << "\n";
}

// Data Backup (copy file)
void Utils::backup(const std::string& filename) {
    std::ifstream src(filename, std::ios::binary);
    std::ofstream dst(filename + ".bak", std::ios::binary);
    dst << src.rdbuf();
    std::cout << "Data backed up to " << filename << ".bak\n";
}

// Data Restore (copy file)
void Utils::restore(const std::string& filename) {
    std::ifstream src(filename + ".bak", std::ios::binary);
    std::ofstream dst(filename, std::ios::binary);
    dst << src.rdbuf();
    std::cout << "Data restored from " << filename << ".bak\n";
}

// Simulated Encryption (XOR)
void Utils::encryptData(const std::string& filename, char key) {
    std::ifstream in(filename, std::ios::binary);
    std::ofstream out(filename + ".enc", std::ios::binary);
    char c;
    while (in.get(c)) out.put(c ^ key);
    std::cout << "File encrypted to " << filename << ".enc\n";
}

void Utils::decryptData(const std::string& filename, char key) {
    std::ifstream in(filename, std::ios::binary);
    std::ofstream out(filename + ".dec", std::ios::binary);
    char c;
    while (in.get(c)) out.put(c ^ key);
    std::cout << "File decrypted to " << filename << ".dec\n";
}

// Financial Tips (rotates tips)
void Utils::financialTips() {
    static std::vector<std::string> tips = {
        "Track your expenses daily for better control.",
        "Set a monthly budget and stick to it.",
        "Review your subscriptions regularly.",
        "Save at least 10% of your income.",
        "Invest early to benefit from compounding."
    };
    static int idx = 0;
    std::cout << "Tip: " << tips[idx] << "\n";
    idx = (idx + 1) % tips.size();
}

// AI Chatbot (simple Q&A)
void Utils::chatbot() {
    std::string q;
    std::cout << "Ask a finance question (type 'exit' to quit): ";
    while (true) {
        std::getline(std::cin, q);
        if (q == "exit") break;
        if (q.find("save") != std::string::npos)
            std::cout << "AI: Try to save at least 10% of your income.\n";
        else if (q.find("invest") != std::string::npos)
            std::cout << "AI: Diversify your investments for safety.\n";
        else
            std::cout << "AI: Sorry, I don't know. Try asking about saving or investing.\n";
        std::cout << "Ask another question (or 'exit'): ";
    }
}

// Voice Command (simulated)
void Utils::voiceCommand() {
    std::cout << "Voice Command: (simulated) Type your command: ";
    std::string cmd;
    std::getline(std::cin, cmd);
    if (cmd == "add expense") std::cout << "Voice: Adding expense...\n";
    else if (cmd == "show budget") std::cout << "Voice: Displaying budget...\n";
    else std::cout << "Voice: Command not recognized.\n";
}

// Subscription Manager (basic)
void Utils::subscriptionManager() {
    static std::vector<std::string> subs;
    int choice;
    std::cout << "1. Add Subscription\n2. List Subscriptions\n3. Remove Subscription\nChoice: ";
    std::cin >> choice; std::cin.ignore();
    if (choice == 1) {
        std::string s;
        std::cout << "Enter subscription name: ";
        std::getline(std::cin, s);
        subs.push_back(s);
        std::cout << "Added.\n";
    } else if (choice == 2) {
        std::cout << "Subscriptions:\n";
        for (const auto& s : subs) std::cout << "- " << s << "\n";
    } else if (choice == 3) {
        std::string s;
        std::cout << "Enter subscription name to remove: ";
        std::getline(std::cin, s);
        subs.erase(std::remove(subs.begin(), subs.end(), s), subs.end());
        std::cout << "Removed if existed.\n";
    }
}

// Insurance Planner (basic)
void Utils::insurancePlanner() {
    std::cout << "Insurance Planner:\n";
    std::cout << "1. Health Insurance\n2. Life Insurance\n3. Vehicle Insurance\n";
    std::cout << "Choose type: ";
    int t; std::cin >> t; std::cin.ignore();
    if (t == 1) std::cout << "Tip: Ensure your health insurance covers major illnesses.\n";
    else if (t == 2) std::cout << "Tip: Term insurance is cost-effective for life cover.\n";
    else if (t == 3) std::cout << "Tip: Comprehensive vehicle insurance is safer.\n";
    else std::cout << "Unknown type.\n";
}

// Coming Soon
void Utils::comingSoon() {
    std::cout << "Feature coming soon! Stay tuned for updates.\n";
}