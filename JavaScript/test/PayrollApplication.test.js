import Employee from '../src/Employee.mjs'
import PayCheck from '../src/PayCheck.mjs'
import PayrollApplication from '../src/PayrollApplication.mjs'

describe('PayrollApplication', () => {
  const IRRELEVANT = 53

  it('Without bonus', () => {
    const app = new PayrollApplication()
    const employee = new Employee(100, false, false)

    const payCheck = app.payAmount(employee, 30)

    expect(payCheck.equals(new PayCheck(3000, "EMP"))).toBe(true)
  })

  it('With bonus', () => {
    const app = new PayrollApplication()
    const employee = new Employee(10, false, false)

    const payCheck = app.payAmount(employee, 41)

    expect(payCheck.equals(new PayCheck(1410, "EMP"))).toBe(true)
  })

  it('Retired', () => {
    const app = new PayrollApplication()
    const employee = new Employee(IRRELEVANT, false, true)

    const payCheck = app.payAmount(employee, IRRELEVANT)

    expect(payCheck.equals(new PayCheck(0, "RET"))).toBe(true)
  })

  it('Separated', () => {
    const app = new PayrollApplication()
    const employee = new Employee(IRRELEVANT, true, false)

    const payCheck = app.payAmount(employee, IRRELEVANT)

    expect(payCheck.equals(new PayCheck(0, "SEP"))).toBe(true)
  })

  it('Separated and Retired', () => {
    const app = new PayrollApplication()
    const employee = new Employee(IRRELEVANT, true, true)

    const payCheck = app.payAmount(employee, IRRELEVANT)

    expect(payCheck.equals(new PayCheck(0, "SEP"))).toBe(true)
  })
})
