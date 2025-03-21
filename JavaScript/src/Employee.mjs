export default class Employee {
  /**
   * @readonly
   * @type {number}
   */
  rate

  /**
   * @private
   * @readonly
   * @type {boolean}
   */
  #separated

  /**
   * @private
   * @readonly
   * @type {boolean}
   */
  #retired

  /**
   * @param {number} rate
   * @param {boolean} separated
   * @param {boolean} retired
   */
  constructor(rate, separated, retired) {
    this.rate = rate
    this.#separated = separated
    this.#retired = retired
  }

  /**
   * @returns {number}
   */
  get rate() {
    return this.rate
  }

  /**
   * @returns {boolean}
   */
  isSeparated() {
    return this.#separated
  }

  /**
   * @returns {boolean}
   */
  isRetired() {
    return this.#retired
  }
}
