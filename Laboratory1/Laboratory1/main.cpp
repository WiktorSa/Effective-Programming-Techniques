#include <iostream>
#include "Constants.h"
#include "ArrayHandling.h"
#include "CTable.h"

int main()
{
	v_alloc_table_add_5(5);
	v_alloc_table_add_5(-1);
	std::cout << std::endl;

	int** twoDArrayPointer;
	std::cout << b_alloc_table_2_dim(&twoDArrayPointer, -2, 5) << std::endl;
	std::cout << b_alloc_table_2_dim(&twoDArrayPointer, constants::sizeX2DTable, constants::sizeY2DTable) << std::endl;

	for (int i = 0; i < constants::sizeX2DTable; i++)
	{
		for (int j = 0; j < constants::sizeY2DTable; j++)
		{
			std::cout << twoDArrayPointer[i][j] << " ";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << b_dealloc_table_2_dim(twoDArrayPointer, 3, 5) << std::endl;
	std::cout << b_dealloc_table_2_dim(twoDArrayPointer, constants::sizeX2DTable, constants::sizeY2DTable) << std::endl;

	// This line of code will crash the programme
	//std::cout << twoDArrayPointer[0][0];
	std::cout << std::endl;

	CTable cTableStatic("Static", 5);
	std::cout << std::endl;

	CTable* cTableNoParams = new CTable();
	(*cTableNoParams).vSetName("Set new name");
	std::cout << (*cTableNoParams).bSetNewSize(-1) << std::endl;
	std::cout << (*cTableNoParams).bSetNewSize(5) << std::endl;
	delete cTableNoParams;
	std::cout << std::endl;

	CTable* cTableParamsCorrect = new CTable("Correct param", 2);
	CTable* cTableParamsIncorrect = new CTable("Incorrect param", -2);
	delete cTableParamsCorrect;
	delete cTableParamsIncorrect;
	std::cout << std::endl;

	CTable* cTableToCopy = new CTable("Copy", 2);
	CTable staticCopy(*cTableToCopy);
	CTable* dynamicCopy = (*cTableToCopy).pcClone();
	delete cTableToCopy;
	delete dynamicCopy;
	std::cout << std::endl;

	int newSize = 5;
	CTable* cTableToFunction = new CTable("Function", 2);
	v_mod_tab(*cTableToFunction, newSize);
	std::cout << (newSize == (*cTableToFunction).getITableLen()) << std::endl;
	v_mod_tab(cTableToFunction, newSize);
	std::cout << (newSize == (*cTableToFunction).getITableLen()) << std::endl;
	delete cTableToFunction;
	std::cout << std::endl;

	CTable cTableArray[2];
	std::cout << std::endl;

	CTable* cTablePointerArray = new CTable[2];
	delete[] cTablePointerArray;
	std::cout << std::endl;

	return 0;
}
