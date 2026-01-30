#include <gtest/gtest.h>
#include "Payroll.h"

using namespace std;

namespace {
    const int IRRELEVANT = 53;
}

TEST(PayrollTests, without_bonus) {
    Employee employee(100, false, false);
    auto payCheck = Payroll::payAmount(employee, 30);
    EXPECT_EQ(payCheck, PayCheck(3000, "EMP"));
}

TEST(PayrollTests, with_bonus) {
    Employee employee(10, false, false);
    auto payCheck = Payroll::payAmount(employee, 41);
    EXPECT_EQ(payCheck, PayCheck(1410, "EMP"));
}

TEST(PayrollTests, retired) {
    Employee employee(IRRELEVANT, false, true);
    auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
    EXPECT_EQ(payCheck, PayCheck(0, "RET"));
}

TEST(PayrollTests, separated) {
    Employee employee(IRRELEVANT, true, false);
    auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
    EXPECT_EQ(payCheck, PayCheck(0, "SEP"));
}

TEST(PayrollTests, separated_and_retired) {
    Employee employee(IRRELEVANT, true, true);
    auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
    EXPECT_EQ(payCheck, PayCheck(0, "SEP"));
}