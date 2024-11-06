package payroll_test

import (
	"testing"

	"github.com/gregorriegler/payroll-refactoring-kata"
	"github.com/stretchr/testify/assert"
)

const IRRELEVANT = 666

func TestWithoutBonus(t *testing.T) {
	employee := payroll.Employee{
		Rate:      100,
		Separated: false,
		Retired:   false,
	}
	payCheck := payroll.PayAmount(employee, 30)
	assert.Equal(t, payCheck, payroll.PayCheck{
		Amount:     3000,
		ReasonCode: "EMP",
	})
}

func TestWithBonus(t *testing.T) {
	employee := payroll.Employee{
		Rate:      10,
		Separated: false,
		Retired:   false,
	}
	payCheck := payroll.PayAmount(employee, 41)
	assert.Equal(t, payCheck, payroll.PayCheck{
		Amount:     1410,
		ReasonCode: "EMP",
	})
}

func TestRetired(t *testing.T) {
	employee := payroll.Employee{
		Rate:      IRRELEVANT,
		Separated: false,
		Retired:   true,
	}
	payCheck := payroll.PayAmount(employee, IRRELEVANT)
	assert.Equal(t, payCheck, payroll.PayCheck{
		Amount:     0,
		ReasonCode: "RET",
	})
}

func TestSeparated(t *testing.T) {
	employee := payroll.Employee{
		Rate:      IRRELEVANT,
		Separated: true,
		Retired:   false,
	}
	payCheck := payroll.PayAmount(employee, IRRELEVANT)
	assert.Equal(t, payCheck, payroll.PayCheck{
		Amount:     0,
		ReasonCode: "SEP",
	})
}
