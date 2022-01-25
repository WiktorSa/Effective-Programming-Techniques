#include <iostream>
#include "HelperFunctions.h"

// Ignore error because compiler uses by default move constructor
CTab cCreateTab()
{
	CTab c_result;
	c_result.bSetSize(5);
	return std::move(c_result);
}

int iIgnoreResult()
{
	cCreateTab();
	return 0;
}

CTable cCreateTable()
{
	CTable c_result;
	c_result.bSetNewSize(5);
	return std::move(c_result);
}

int iIgnoreResultTable()
{
	cCreateTable();
	return 0;
}
