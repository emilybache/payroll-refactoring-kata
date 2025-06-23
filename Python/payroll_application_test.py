import unittest

from payroll_application import Employee, PayrollApplication, PayCheck


class PayrollApplicationTestCase(unittest.TestCase):
    IRRELEVANT = 666

    def test_without_bonus(self):
        employee = Employee(100, False, False)
        payCheck = PayrollApplication.pay_amount(employee, 30)
        assert payCheck == PayCheck(3000, "EMP")

    def test_with_bonus(self):
        employee = Employee(10, False, False)
        payCheck = PayrollApplication.pay_amount(employee, 41)
        assert payCheck == PayCheck(1410, "EMP")

    def test_retired(self):
        employee = Employee(self.IRRELEVANT, False, True)
        payCheck = PayrollApplication.pay_amount(employee, self.IRRELEVANT)
        assert payCheck == PayCheck(0, "RET")

    def test_separated(self):
        employee = Employee(self.IRRELEVANT, True, False)
        payCheck = PayrollApplication.pay_amount(employee, self.IRRELEVANT)
        assert payCheck == PayCheck(0, "SEP")


if __name__ == '__main__':
    unittest.main()