#include "PayCheck.h"

#include <utility>

PayCheck::PayCheck(double amount, std::string reasonCode)
        : amount(amount), reasonCode(std::move(reasonCode)) {}