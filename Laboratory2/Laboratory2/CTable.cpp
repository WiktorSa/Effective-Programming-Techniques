#include "CTable.h"
#include <iostream>
#include <string>

const std::string CTable::sDefaultName = "Default";
const std::string CTable::sDefaultConcatName = "Concatenate";
const int CTable::iDefaultlTableLen = 5;

CTable::CTable()
{
	sName = sDefaultName;
	iTableLen = iDefaultlTableLen;
	cTableArray = new int[iTableLen];

	std::cout << "bezp: " + sName << std::endl;
}

CTable::CTable(std::string sName, int iTableLen)
{
	this->sName = sName;
	this->iTableLen = iTableLen;
	std::cout << "parametr: " + sName << std::endl;

	if (iTableLen < 0) {
		std::cout << "Negative length of array. Using default value" << std::endl;
		this->iTableLen = iDefaultlTableLen;
	}

	cTableArray = new int[this->iTableLen];
}

CTable::CTable(CTable& pcOther)
{
	sName = pcOther.sName + "_copy";
	iTableLen = pcOther.iTableLen;
	cTableArray = new int[iTableLen];
	for (int i = 0; i < iTableLen; i++)
	{
		*(cTableArray + i) = *(pcOther.cTableArray + i);
	}

	std::cout << "kopiuj: " + sName << std::endl;
}

CTable::~CTable()
{
	std::cout << "usuwam: " + sName << std::endl;
	delete[] cTableArray;
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

/*void CTable::operator=(const CTable& pcOther)
{
	cTableArray = pcOther.cTableArray;
	iTableLen = pcOther.iTableLen;
}*/

void CTable::operator=(const CTable& pcOther)
{
	delete[] cTableArray;

	sName = pcOther.sName;
	iTableLen = pcOther.iTableLen;
	cTableArray = new int[iTableLen];

	for (int i = 0; i < iTableLen; i++)
	{
		*(cTableArray + i) = *(pcOther.cTableArray + i);
	}
}

CTable CTable::operator+(CTable& pcNewVal)
{
	int newITableLen = iTableLen + pcNewVal.iTableLen;
	CTable concatenatedCTable(sDefaultConcatName, newITableLen);

	for (int i = 0; i < iTableLen; i++)
	{
		*(concatenatedCTable.cTableArray + i) = *(cTableArray + i);
	}

	for (int i = iTableLen; i < newITableLen; i++)
	{
		*(concatenatedCTable.cTableArray + i) = *(pcNewVal.cTableArray + i - iTableLen);
	}

	return concatenatedCTable;
}

CTable CTable::operator-(int reductionSize)
{
	if (reductionSize <= 0) {
		return *this;
	}

	int sizeAfterReduction = iTableLen - reductionSize;

	if (sizeAfterReduction < 0) {
		sizeAfterReduction = 0;
	}

	CTable reductedCTable(sName, sizeAfterReduction);

	for (int i = 0; i < sizeAfterReduction; i++)
	{
		*(reductedCTable.cTableArray + i) = *(cTableArray + i);
	}

	return reductedCTable;
}

void CTable::vSetValueAt(int iOffset, int iNewVal)
{
	if (iOffset < 0 || iOffset >= iTableLen) {
		std::cout << "Not correct index" << std::endl;
		return;
	}

	*(cTableArray + iOffset) = iNewVal;
}

void CTable::vPrint()
{
	for (int i = 0; i < iTableLen; i++)
	{
		std::cout << *(cTableArray + i) << " ";
	}
	std::cout << std::endl;
}
