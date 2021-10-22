#include "CTable.h"
#include <iostream>
#include <string>

const std::string CTable::sDefaultName = "Default";
const int CTable::iDefaultlTableLen = 5;
const int CTable::iPiVal = 58;

CTable::CTable()
{
	sName = sDefaultName;
	iTableLen = iDefaultlTableLen;
	cTableArray = new int[iTableLen];
	pi_val = new int;
	*pi_val = iPiVal;

	std::cout << "bezp: " + sName << std::endl;
}

CTable::CTable(std::string sName, int iTableLen)
{
	this->sName = sName;
	this->iTableLen = iTableLen;
	std::cout << "parametr: " + sName << std::endl;

	if (iTableLen <= 0) {
		std::cout << "Negative length of array. Using default value" << std::endl;
		this->iTableLen = iDefaultlTableLen;
	}

	cTableArray = new int[this->iTableLen];
	pi_val = new int;
	*pi_val = iPiVal;
}

CTable::CTable(CTable& pcOther)
{
	sName = pcOther.sName + "_copy";
	iTableLen = pcOther.iTableLen;
	cTableArray = new int;
	*cTableArray = *pcOther.cTableArray;
	pi_val = new int;
	*pi_val = *pcOther.pi_val;
	std::cout << "kopiuj: " + sName << std::endl;
}

CTable::~CTable()
{
	std::cout << "usuwam: " + sName << std::endl;
	delete[] cTableArray;
	delete pi_val;
}

void CTable::vSetName(std::string sName)
{
	CTable::sName = sName;
}

bool CTable::bSetNewSize(int iTableLen)
{
	if (iTableLen <= 0) {
		return false;
	}

	// Save from copying values that are outside of the array
	int indexCopy = 0;
	if (iTableLen > this->iTableLen) {
		indexCopy = this->iTableLen;
	}
	else {
		indexCopy = iTableLen;
	}

	int* newArray = new int[iTableLen];
	this->iTableLen = iTableLen;

	for (int i = 0; i < indexCopy; i++)
	{
		*(newArray + i) = *(cTableArray + i);
	}

	// Change cTableArray memory allocation
	delete[] cTableArray;
	cTableArray = newArray;

	return true;
}

CTable* CTable::pcClone()
{
	return new CTable(*this);
}

int CTable::getITableLen()
{
	return iTableLen;
}
