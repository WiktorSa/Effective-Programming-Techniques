#ifndef CTABLE
#define CTABLE
#include <string>

class CTable
{
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable& pcOther);
	//~CTable();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();
	void operator=(const CTable& pcOther);
	CTable operator+(CTable& pcNewVal);
	void vSetValueAt(int iOffset, int iNewVal);
	void vPrint();

private:
	static const std::string sDefaultName;
	static const std::string sDefaultConcatName;
	static const int iDefaultlTableLen;
	std::string sName;
	int iTableLen;
	int* cTableArray;
};

#endif

