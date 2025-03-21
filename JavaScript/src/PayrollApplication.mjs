import PayCheck from './PayCheck.mjs'

export default class PayrollApplication {
  /**
   * @param {import('./Employee.mjs').default} employee
   * @param {number} workHours
   * @returns {import('./PayCheck.mjs').default}
   */
  payAmount(employee, workHours) {
    let result
    if (!employee.isSeparated()) {
      if (employee.isRetired()) {
        result = new PayCheck(0, "RET")
      } else {
        // Logic to compute amount
        let bonus = this.computeBonus(workHours)
        let regularAmount = this.computeRegularPayAmount(employee, workHours)
        let amount = bonus + regularAmount
        result = new PayCheck(amount, "EMP")
      }
    } else {
      result = new PayCheck(0, "SEP")
    }
    return result
  }

  /**
   * @private
   * @param {number} workHours
   * @returns {number}
   */
  computeBonus(workHours) {
    return workHours > 40 ? 1000 : 0
  }

  /**
   * @private
   * @param {import('./Employee.mjs').default} employee
   * @param {number} workHours
   * @returns {number}
   */
  computeRegularPayAmount(employee, workHours) {
    return employee.rate * workHours
  }
}
