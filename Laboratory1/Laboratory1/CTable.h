#pragma once
#include <string>

class CTable
{
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	~CTable();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	int getITableLen();

private:
	static const std::string sDefaultName;
	static const int iDefaultlTableLen;
	std::string sName;
	int iTableLen;
	int* cTableArray;
};

