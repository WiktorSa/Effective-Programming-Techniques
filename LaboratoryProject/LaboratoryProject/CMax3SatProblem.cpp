#include "CMax3SatProblem.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

const int CMax3SatProblem::iClauseLength = 3;
const char CMax3SatProblem::delimeter = ' ';

CMax3SatProblem::~CMax3SatProblem()
{
	for (int i = 0; i < pVariables.size(); i++)
	{
		delete pVariables.at(i);
	}
	pVariables.clear();
}

bool CMax3SatProblem::bLoad(std::string sSourcePath)
{
	std::ifstream file;
	file.open(sSourcePath);

	if (!file) {
		return false;
	}

	int iNoClausule = 0;
	std::string line;
	while (std::getline(file, line))
	{
		pVariables.push_back(new int[iClauseLength]);

		// Erase brackets
		line.erase(0, 2);
		line.erase(line.length() - 2);

		std::istringstream iss(line);
		std::string splitLine;

		int iNoLine = 0;
		int iNoNumber = 0;
		while (std::getline(iss, splitLine, delimeter))
		{
			// Because there are two spaces and getline can only omit one space we will do this simple check to omit empty lines
			if (iNoLine % 2 == 0) {
				int number = std::stoi(splitLine);
				pVariables.at(iNoClausule)[iNoNumber] = number;;
				// Every number is used at least once
				if (number > iNoVariables) {
					iNoVariables = number;
				}
				iNoNumber++;
			}
			iNoLine++;
		}

		iNoClausule++;
	}

	// There is also number 0 in our clausules
	iNoVariables++;

	return true;
}

double CMax3SatProblem::dCompute(int* pdGenotype)
{
	int iNoGoodClauses = 0;
	for (const auto clause : pVariables)
	{
		bool bGoodClause = true;
		for (int i = 0; i < iClauseLength; i++)
		{
			int iWhatShouldBeEqualTo = std::abs(clause[i]) == clause[i] ? 1 : 0;
			if (iWhatShouldBeEqualTo != pdGenotype[std::abs(clause[i])]) {
				bGoodClause = false;
			}

		}

		if (bGoodClause) {
			iNoGoodClauses++;
		}
	}

	return double(iNoGoodClauses) / double(pVariables.size());
}
