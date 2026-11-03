import assert from 'node:assert/strict'
import { describe, it } from 'node:test'

import Employee from '../src/Employee.mjs'
import PayCheck from '../src/PayCheck.mjs'
import PayrollApplication from '../src/PayrollApplication.mjs'

describe('PayrollApplication', () => {
  const IRRELEVANT = 53

  it('Without bonus', () => {
    const app = new PayrollApplication()
    const employee = new Employee(100, false, false)

    const payCheck = app.payAmount(employee, 30)

    assert.strictEqual(payCheck.equals(new PayCheck(3000, "EMP")), true)
  })

  it('With bonus', () => {
    const app = new PayrollApplication()
    const employee = new Employee(10, false, false)

    const payCheck = app.payAmount(employee, 41)

    assert.strictEqual(payCheck.equals(new PayCheck(1410, "EMP")), true)
  })

  it('Retired', () => {
    const app = new PayrollApplication()
    const employee = new Employee(IRRELEVANT, false, true)

    const payCheck = app.payAmount(employee, IRRELEVANT)

    assert.strictEqual(payCheck.equals(new PayCheck(0, "RET")), true)
  })

  it('Separated', () => {
    const app = new PayrollApplication()
    const employee = new Employee(IRRELEVANT, true, false)

    const payCheck = app.payAmount(employee, IRRELEVANT)

    assert.strictEqual(payCheck.equals(new PayCheck(0, "SEP")), true)
  })

  it('Separated and Retired', () => {
    const app = new PayrollApplication()
    const employee = new Employee(IRRELEVANT, true, true)

    const payCheck = app.payAmount(employee, IRRELEVANT)

    assert.strictEqual(payCheck.equals(new PayCheck(0, "SEP")), true)
  })
})
