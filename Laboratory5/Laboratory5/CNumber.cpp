#include "CNumber.h"
#include <iostream>

CNumber::CNumber(const CNumber& pc_other)
{
	value = new double(*pc_other.value);
}

CNumber::CNumber(CNumber&& pc_other) noexcept
{
	value = pc_other.value;
	pc_other.value = NULL;
}

void CNumber::operator=(const CNumber& pc_other)
{
	if (value != NULL) {
		delete value;
	}
	value = new double(*pc_other.value);
}

CNumber CNumber::operator+(const CNumber& pc_other)
{
	CNumber result;
	result.setValue(*value + *pc_other.value);
	return std::move(result);
}
