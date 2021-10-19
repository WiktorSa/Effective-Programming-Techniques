#include "CTable.h"
#include <iostream>
#include <string>

const std::string CTable::sDefaultName = "Default";
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

	if (iTableLen <= 0) {
		std::cout << "Negative length of array. Using default value" << std::endl;
		this->iTableLen = iDefaultlTableLen;
	}

	cTableArray = new int[this->iTableLen];
}

CTable::CTable(CTable& pcOther)
{
	sName = pcOther.sName + "_copy";
	iTableLen = pcOther.iTableLen;
	cTableArray = new int;
	*cTableArray = *pcOther.cTableArray;
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

	this->iTableLen = iTableLen;
	cTableArray = new int[iTableLen];
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
