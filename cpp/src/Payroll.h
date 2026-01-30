#ifndef SAMPLE_PAYROLL_H
#define SAMPLE_PAYROLL_H


#include "Employee.h"
#include "PayCheck.h"

class Payroll {
public:
    static PayCheck payAmount(const Employee& employee, int workHours);

private:
    static double computeBonus(int workHours);
    static double computeRegularPayAmount(const Employee& employee, double workHours);
};


#endif //SAMPLE_PAYROLL_H