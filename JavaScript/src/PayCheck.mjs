export default class PayCheck {
  /**
   * @private
   * @readonly
   * @type {number}
   */
  #amount

  /**
   * @private
   * @readonly
   * @type {string}
   */
  #reasonCode

  /**
   * @param {number} amount
   * @param {string} reasonCode
   */
  constructor(amount, reasonCode) {
    this.#amount = amount
    this.#reasonCode = reasonCode
  }

  /**
   * @override
   * @returns {string}
   */
  toString() {
    return `${this.#reasonCode} ${this.#amount}`
  }

  /**
   * @param {PayCheck} other
   * @returns {boolean}
   */
  equals(other) {
    if (other === undefined || other === null) {
      return false
    }

    return (
      this.#reasonCode === other.#reasonCode &&
      this.#amount === other.#amount
    )
  }
}
