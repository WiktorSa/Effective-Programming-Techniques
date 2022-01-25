#pragma once
#include <string>
#include <vector>

class CMax3SatProblem
{
public:
	CMax3SatProblem() { iNoVariables = 0; };
	~CMax3SatProblem();

	bool bLoad(std::string sSourcePath);
	double dCompute(int* pdGenotype);
	int iGetNumberVariables() { return iNoVariables; }

private:
	std::vector<int*> pVariables;
	int iNoVariables;
	static const int iClauseLength;
	static const char delimeter;
};

