#ifndef SAMPLE_PAYCHECK_H
#define SAMPLE_PAYCHECK_H


#include <string>

class PayCheck {
private:
    double amount;
    std::string reasonCode;

public:
    PayCheck(double amount, std::string reasonCode);

    bool operator==(const PayCheck& other) const {
        return amount == other.amount && reasonCode == other.reasonCode;
    }
};


#endif //SAMPLE_PAYCHECK_H