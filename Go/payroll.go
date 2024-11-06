package payroll

type Employee struct {
	Rate      int
	Separated bool
	Retired   bool
}

type PayCheck struct {
	Amount     float64
	ReasonCode string
}

func PayAmount(employee Employee, workHours int) PayCheck {
	var result PayCheck

	if !employee.Separated {
		if employee.Retired {
			result = PayCheck{
				Amount:     0,
				ReasonCode: "RET",
			}
		} else {
			// Logic to compute amount
			bonus := computeBonus(workHours)
			regularAmount := computeRegularPayAmount(employee, float64(workHours))
			amount := bonus + regularAmount
			result = PayCheck{
				Amount:     amount,
				ReasonCode: "EMP",
			}
		}
	} else {
		result = PayCheck{
			Amount:     0,
			ReasonCode: "SEP",
		}
	}

	return result
}

func computeBonus(workHours int) float64 {
	if workHours > 40 {
		return 1000
	} else {
		return 0
	}
}

func computeRegularPayAmount(employee Employee, workHours float64) float64 {
	return float64(employee.Rate) * workHours
}
