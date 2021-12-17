#pragma once
#include <iostream>
class CNumber
{
public:
	CNumber() { value = new double(0); };
	~CNumber() { if (value != NULL) delete value; };
	CNumber(const CNumber& pc_other);
	CNumber(CNumber&& pc_other) noexcept;

	void setValue(double value) { *this->value = value; };
	double getValue() { return *value; };

	void operator=(const CNumber& pc_other);
	CNumber operator+(const CNumber& pc_other);

private:
	double* value;
};

