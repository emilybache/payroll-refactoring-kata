from payroll_application import Employee, PayCheck, pay_amount

IRRELEVANT = 53


def test_without_bonus():
    employee = Employee(100, False, False)
    pay_check = pay_amount(employee, 30)
    assert pay_check == PayCheck(3000, "EMP")


def test_with_bonus():
    employee = Employee(10, False, False)
    pay_check = pay_amount(employee, 41)
    assert pay_check == PayCheck(1410, "EMP")


def test_retired():
    employee = Employee(IRRELEVANT, False, True)
    pay_check = pay_amount(employee, IRRELEVANT)
    assert pay_check == PayCheck(0, "RET")


def test_separated():
    employee = Employee(IRRELEVANT, True, False)
    pay_check = pay_amount(employee, IRRELEVANT)
    assert pay_check == PayCheck(0, "SEP")


def test_separated_and_retired():
    employee = Employee(IRRELEVANT, True, True)
    pay_check = pay_amount(employee, IRRELEVANT)
    assert pay_check == PayCheck(0, "SEP")
