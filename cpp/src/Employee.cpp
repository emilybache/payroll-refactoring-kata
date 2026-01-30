#include "Employee.h"

Employee::Employee(int rate, bool separated, bool retired)
    : rate(rate), separated(separated), retired(retired) {}

int Employee::getRate() const {
    return rate;
}

bool Employee::isSeparated() const {
    return separated;
}

bool Employee::isRetired() const {
    return retired;
}