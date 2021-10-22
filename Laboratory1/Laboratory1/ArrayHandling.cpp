#include <iostream>
#include "ArrayHandling.h"
#include "Constants.h"
#include "CTable.h"

// Task 1
// Warning - this function should be bool instead of void
void v_alloc_table_add_5(int iSize)
{
	if (iSize <= 0) {
		std::cout << "Not correct size\n";
		return;
	}

	std::cout << "Correct size. Allocating memory\n";

	int* arrayTask1 = new int[iSize];

	for (int i = 0; i < iSize; i++)
	{
		arrayTask1[i] = i + constants::addedNumberAllocTable;
	}

	std::cout << "Array state\n";

	for (int i = 0; i < iSize; i++)
	{
		std::cout << arrayTask1[i] << " ";
	}

	std::cout << std::endl;
	delete[] arrayTask1;
}

// Task 2
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY)
{
	if (iSizeX <= 0 || iSizeY <= 0) {
		return false;
	}

	*piTable = new int* [iSizeX];
	for (int i = 0; i < iSizeX; i++)
	{
		(*piTable)[i] = new int[iSizeY];
	}

	return true;
}

// Task 3
// Because there is no easy way to calculate array size based on pointer we will use proper constants
// iSizeY is useless here
bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY)
{
	if (iSizeX != constants::sizeX2DTable) {
		return false;
	}

	for (int i = 0; i < iSizeX; i++)
	{
		delete[] piTable[i];
	}

	delete[] piTable;
	return true;
}

void v_mod_tab(CTable* pcTab, int iNewSize)
{
	(*pcTab).bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize)
{
	cTab.bSetNewSize(iNewSize);
}

void v_test()
{
	CTable c_origi;
	CTable c_copy(c_origi);
}
