#pragma once
#include <string>

class CTable
{
public:
	CTable();
	CTable(std::string s_name, int i_table_len);
	CTable(const CTable& pc_other);
	CTable(CTable&& pc_other) noexcept;
	~CTable();
	void vSetName(std::string s_name);
	bool bSetNewSize(int i_table_len);
	CTable* pcClone();
	void operator=(const CTable& pc_other);
	CTable operator+(CTable& pc_new_val);
	CTable operator-(int i_reduction_size);
	void vSetValueAt(int i_offset, int i_new_val);
	void vPrint();

private:
	static const std::string s_default_name;
	static const std::string s_default_concat_name;
	static const int i_default_table_len;
	std::string s_name;
	int i_table_len;
	int* c_table_array;
};
