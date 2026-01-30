#include "Payroll.h"

PayCheck Payroll::payAmount(const Employee& employee, int workHours) {
    if (!employee.isSeparated()) {
        if (employee.isRetired()) {
            return PayCheck(0, "RET");
        } else {
            // Logic to compute amount
            auto bonus = computeBonus(workHours);
            auto regularAmount = computeRegularPayAmount(employee, workHours);
            auto amount = bonus + regularAmount;
            return PayCheck(amount, "EMP");
        }
    } else {
        return PayCheck(0, "SEP");
    }
}

double Payroll::computeBonus(int workHours) {
    return workHours > 40 ? 1000 : 0;
}

double Payroll::computeRegularPayAmount(const Employee& employee, double workHours) {
    return employee.getRate() * workHours;
}