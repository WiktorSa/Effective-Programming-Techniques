#pragma once

#define DEF_TAB_SIZE 10
class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
	CTab(const CTab& c_other);
	CTab(CTab&& c_other) noexcept;
	~CTab();

	bool bSetSize(int i_size);
	int iGetSize() { return i_size; }

	CTab operator=(CTab& c_other);
	CTab operator=(CTab&& c_other) noexcept;

private:
	void v_copy(const CTab& c_other);

	int* pi_tab;
	int i_size;
};

