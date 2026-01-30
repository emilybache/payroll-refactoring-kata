#include "ApprovalTests.hpp"
#include "catch2/catch.hpp"
#include "Payroll.h"

TEST_CASE ("PayrollTests") {
    const int IRRELEVANT = 53;

    SECTION("without_bonus") {
        Employee employee(100, false, false);
        auto payCheck = Payroll::payAmount(employee, 30);
        REQUIRE(payCheck == PayCheck(3000, "EMP"));
    }

    SECTION("with_bonus") {
        Employee employee(10, false, false);
        auto payCheck = Payroll::payAmount(employee, 41);
        REQUIRE(payCheck == PayCheck(1410, "EMP"));
    }

    SECTION("retired") {
        Employee employee(IRRELEVANT, false, true);
        auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
        REQUIRE(payCheck == PayCheck(0, "RET"));
    }

    SECTION("separated") {
        Employee employee(IRRELEVANT, true, false);
        auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
        REQUIRE(payCheck == PayCheck(0, "SEP"));
    }

    SECTION("separated_and_retired") {
        Employee employee(IRRELEVANT, true, true);
        auto payCheck = Payroll::payAmount(employee, IRRELEVANT);
        REQUIRE(payCheck == PayCheck(0, "SEP"));
    }
}


