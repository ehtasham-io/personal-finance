#ifndef REPORT_H
#define REPORT_H
#include <string>
#include "FinanceManager.h"

class Report {
    std::string type;
    std::string generatedOn;
    std::string passwordHash;
public:
    Report(const std::string& t = "", const std::string& date = "");
    void generate(const FinanceManager& manager);
    void display() const;
};

#endif