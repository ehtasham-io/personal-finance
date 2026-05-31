#ifndef FD_H
#define FD_H
#include "Investment.h"

class FD : public Investment {
public:
    FD(double amt, const std::string& d, const std::string& desc);
    void display() const override;
    double maturityAmount() const override;
};

#endif