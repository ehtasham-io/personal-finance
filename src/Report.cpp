#include "Report.h"
#include <iostream>

Report::Report(const std::string& t, const std::string& date)
    : type(t), generatedOn(date) {}

void Report::generate(const FinanceManager& manager) {
    // For demo, just print summary
    std::cout << "Generating " << type << " report on " << generatedOn << std::endl;
    manager.displayRecord(0); // 0 for demo
}

void Report::display() const {
    std::cout << "Report Type: " << type << " | Generated On: " << generatedOn << std::endl;
}