#ifndef SIP_H
#define SIP_H
#include "Investment.h"

class SIP : public Investment {
    double monthly;
public:
    SIP(double amt, const std::string& d, const std::string& desc, double monthly);
    void display() const override;
    double maturityAmount() const override;
};

#endif