#include "ApprovalTests.hpp"
#include "doctest/doctest.h"
#include "Payroll.h"

TEST_CASE ("PayrollTests") {
    const int IRRELEVANT = 53;

    SUBCASE("without_bonus") {
        Employee employee(100, false, false);
        auto payCheck = Payroll::payAmount(employee, 30);
        REQUIRE(payCheck == PayCheck(3000, "EMP"));
    }

    SUBCASE("with_bonus") {
        Employee employee(10, false, false);
        auto payCheck = Payroll::payAmount(employee, 41);
        REQUIRE(payCheck == PayCheck(1410, "EMP"));
    }

    SUBCASE("retired") {
        Employee employee(IRRELEVANT, false, true);
        auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
        REQUIRE(payCheck == PayCheck(0, "RET"));
    }

    SUBCASE("separated") {
        Employee employee(IRRELEVANT, true, false);
        auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
        REQUIRE(payCheck == PayCheck(0, "SEP"));
    }

    SUBCASE("separated_and_retired") {
        Employee employee(IRRELEVANT, true, true);
        auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
        REQUIRE(payCheck == PayCheck(0, "SEP"));
    }
}


