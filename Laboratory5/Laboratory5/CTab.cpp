#include <iostream>
#include "CTab.h"

CTab::CTab(const CTab& c_other)
{
	v_copy(c_other);
	std::cout << "Copy ";
}

CTab::CTab(CTab&& c_other) noexcept
{
	pi_tab = c_other.pi_tab;
	i_size = c_other.i_size;
	c_other.pi_tab = NULL;
	std::cout << "MOVE ";
}

CTab::~CTab()
{
	if (pi_tab != NULL) {
		delete pi_tab;
	}
	std::cout << "Destr ";
}

bool CTab::bSetSize(int i_size)
{
	if (i_size < 0) {
		return false;
	}

	int index_copy = (i_size > this->i_size) ? this->i_size : i_size;
	int* pi_tab = new int[i_size];

	for (int i = 0; i < index_copy; i++)
	{
		*(pi_tab + i) = *(this->pi_tab + i);
	}

	delete this->pi_tab;

	this->pi_tab = pi_tab;
	this->i_size = i_size;

	return true;
}

CTab CTab::operator=(CTab& c_other)
{
	if (pi_tab != NULL) {
		delete pi_tab;
	}
	v_copy(c_other);
	
	std::cout << "op= ";

	return *this;
}

CTab CTab::operator=(CTab&& c_other) noexcept
{
	if (pi_tab != NULL) {
		delete pi_tab;
	}

	pi_tab = c_other.pi_tab;
	i_size = c_other.i_size;
	c_other.pi_tab = NULL;
	return std::move(*this);
}

void CTab::v_copy(const CTab& c_other)
{
	pi_tab = new int[c_other.i_size];
	i_size = c_other.i_size;
	for (int i = 0; i < c_other.i_size; i++)
	{
		pi_tab[i] = c_other.pi_tab[i];
	}
}


