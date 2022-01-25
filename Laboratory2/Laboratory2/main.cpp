#include <iostream>
#include "CTable.h"

int main()
{
	// Zad 1 - dojdzie do crashu programu gdyz podczas kopiowania CTable
	// nie kopiujemy tablicy tylko mowimy c_tab_0, zeby jego wskaznik wskazywal na ten sam obszar
	// pamiêci co wskaznik w c_tab_1. Podczas wywolywania destruktora obu obiektow program
	// bedzie chcial skasowac ten sam obszar w pamieci dwukrotnie co prowadzi do crasha
	// 
	// Zad 2 - nie dojdzie do crasha gdyz domyslny destruktor niszczy wskaznik, ale nie usuwa
	// z pamieci tablicy na ktora dany wskaznik wskazywal (w przeciwienstwie do wlasnego destruktora
	// ktory zwalnia miejsce z pamieci i kasuje wskaznik)
	// Mimo ze program nie crashuje to nalezy zauwazyc, ze jest to memory leak i nalezy unikac tego
	//
	// Zad 3 - patrz zad 1 po uzasadnienie
	//
	// INFO - BEDA TUTAJ WYCIEKI PAMIECI BO SKASOWALEM DESTRUKTOR, ZEBY PROGRAM PRZY OPERATORZE = SIE NIE WYWALIL (BO TEN OPERATOR JEST ZLE ZAIMPLEMENTOWANY)

	CTable c_tab_0, c_tab_1;
	c_tab_0.bSetNewSize(6);
	c_tab_1.bSetNewSize(4);
	c_tab_0 = c_tab_1;
	c_tab_1.vSetValueAt(2, 123);
	c_tab_0.vPrint();
	c_tab_1.vPrint();
	std::cout << std::endl;

	// Test zadania 3
	CTable c_tab_2;
	c_tab_2.vSetValueAt(-1, 10);
	c_tab_2.vSetValueAt(1, 10);
	c_tab_2.vSetValueAt(3, 10);
	c_tab_2.vSetValueAt(7, 10);
	c_tab_2.vPrint();
	std::cout << std::endl;

	// Test zadanie 4
	CTable* c_tab_3 = new CTable("2", 2);
	CTable* c_tab_4 = new CTable("3", 3);
	(*c_tab_3).vSetValueAt(0, 5);
	(*c_tab_3).vSetValueAt(1, 2);
	(*c_tab_4).vSetValueAt(0, 6);
	(*c_tab_4).vSetValueAt(1, 9);
	(*c_tab_4).vSetValueAt(2, -2);
	(*c_tab_3).vPrint();
	(*c_tab_4).vPrint();
	std::cout << std::endl;

	CTable c_tab_5("Static", 1);
	c_tab_5.vSetValueAt(0, 0);
	c_tab_5.vPrint();
	std::cout << std::endl;

	c_tab_5 = (*c_tab_3) + (*c_tab_4) + c_tab_5;
	std::cout << std::endl;
	c_tab_5.vPrint();

	delete c_tab_3;
	delete c_tab_4;

	CTable c_tab_6("test_minus_operator", 5);
	c_tab_6.vSetValueAt(0, 0);
	c_tab_6.vSetValueAt(1, 1);
	c_tab_6.vSetValueAt(2, 2);
	c_tab_6.vSetValueAt(3, 3);
	c_tab_6.vSetValueAt(4, 4);
	std::cout << std::endl;

	c_tab_6.vPrint();
	std::cout << std::endl;

	c_tab_6 = c_tab_6 - (-5);
	c_tab_6.vPrint();
	std::cout << std::endl;

	c_tab_6 = c_tab_6 - 3;
	c_tab_6.vPrint();
	std::cout << std::endl;

	c_tab_6 = c_tab_6 - 4;
	c_tab_6.vPrint();
	std::cout << "Jak nie printuje liczb to jest dobrze" << std::endl;

	std::cout << std::endl;
}
