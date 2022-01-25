#include "CTable.h"
#include <iostream>
#include <string>

const std::string CTable::s_default_name = "Default";
const std::string CTable::s_default_concat_name = "Concatenate";
const int CTable::i_default_table_len = 5;

CTable::CTable()
{
	s_name = s_default_name;
	i_table_len = i_default_table_len;
	c_table_array = new int[i_table_len];

	std::cout << "bezp: " + s_name << std::endl;
}

CTable::CTable(std::string s_name, int i_table_len)
{
	this->s_name = s_name;
	this->i_table_len = i_table_len;
	std::cout << "parametr: " + s_name << std::endl;

	if (i_table_len < 0) {
		this->i_table_len = i_default_table_len;
	}

	c_table_array = new int[i_table_len];
}

CTable::CTable(const CTable& pc_other)
{
	s_name = pc_other.s_name + "_copy";
	i_table_len = pc_other.i_table_len;
	c_table_array = new int[i_table_len];
	for (int i = 0; i < i_table_len; i++)
	{
		*(c_table_array + i) = *(pc_other.c_table_array + i);
	}

	std::cout << "kopiuj: " + s_name << std::endl;
}

CTable::CTable(CTable&& pc_other) noexcept
{
	s_name = pc_other.s_name;
	i_table_len = pc_other.i_table_len;
	c_table_array = pc_other.c_table_array;
	pc_other.c_table_array = NULL;
}

CTable::~CTable()
{
	std::cout << "usuwam: " + s_name << std::endl;
	if (c_table_array != NULL) {
		delete[] c_table_array;
	}
}

void CTable::vSetName(std::string s_name)
{
	CTable::s_name = s_name;
}

bool CTable::bSetNewSize(int i_table_len)
{
	if (i_table_len <= 0) {
		return false;
	}

	// Save from copying values that are outside of the array
	int indexCopy = i_table_len > this->i_table_len ? this->i_table_len : i_table_len;

	int* c_table_array = new int[i_table_len];
	this->i_table_len = i_table_len;

	for (int i = 0; i < indexCopy; i++)
	{
		*(c_table_array + i) = *(this->c_table_array + i);
	}

	// Change cTableArray memory allocation
	delete[] this->c_table_array;
	this->c_table_array = c_table_array;

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

void CTable::operator=(const CTable& pc_other)
{
	if (c_table_array != NULL) {
		delete[] c_table_array;
	}

	s_name = pc_other.s_name;
	i_table_len = pc_other.i_table_len;
	c_table_array = new int[i_table_len];

	for (int i = 0; i < i_table_len; i++)
	{
		*(c_table_array + i) = *(pc_other.c_table_array + i);
	}
}

CTable CTable::operator+(CTable& pc_new_val)
{
	int i_new_table_len = i_table_len + pc_new_val.i_table_len;
	CTable concatenatedCTable(s_default_concat_name, i_new_table_len);

	for (int i = 0; i < i_table_len; i++)
	{
		*(concatenatedCTable.c_table_array + i) = *(c_table_array + i);
	}

	for (int i = i_table_len; i < i_new_table_len; i++)
	{
		*(concatenatedCTable.c_table_array + i) = *(pc_new_val.c_table_array + i - i_table_len);
	}

	return std::move(concatenatedCTable);
}

CTable CTable::operator-(int reduction_size)
{
	if (reduction_size <= 0) {
		return std::move(*this);
	}

	int i_size_after_reduction = i_table_len - reduction_size;

	if (i_size_after_reduction < 0) {
		i_size_after_reduction = 0;
	}

	CTable reducted_c_table(s_name, i_size_after_reduction);

	for (int i = 0; i < i_size_after_reduction; i++)
	{
		*(reducted_c_table.c_table_array + i) = *(c_table_array + i);
	}

	return std::move(reducted_c_table);
}

void CTable::vSetValueAt(int i_offset, int i_new_val)
{
	if (i_offset >= 0 && i_offset < i_table_len) {
		*(c_table_array + i_offset) = i_new_val;
	}
}

void CTable::vPrint()
{
	for (int i = 0; i < i_table_len; i++)
	{
		std::cout << *(c_table_array + i) << " ";
	}
	std::cout << std::endl;
}