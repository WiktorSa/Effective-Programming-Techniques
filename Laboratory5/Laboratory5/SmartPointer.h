#pragma once

class CRefCounter
{
public:
	CRefCounter() { i_count = 0; }
	
	int iAdd() { return ++i_count; }
	int iDec() { return --i_count; }
	int iGet() { return i_count; }

private:
	int i_count;
};

template <typename T> class CMySmartPointer
{
public:
	CMySmartPointer(T* pc_pointer);
	CMySmartPointer(const CMySmartPointer<T>& pc_other);
	~CMySmartPointer();

	void operator=(const CMySmartPointer<T>& pc_other);
	T& operator*() { return *pc_pointer; }
	T* operator->() { return pc_pointer; }

private:
	CRefCounter* pc_counter;
	T* pc_pointer;
};

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T* pc_pointer)
{
	this->pc_pointer = pc_pointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T>& pc_other)
{
	pc_pointer = pc_other.pc_pointer;
	pc_counter = pc_other.pc_counter;
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec() == 0) {
		delete pc_pointer;
		delete pc_counter;
	}
}

template <typename T>
void CMySmartPointer<T>::operator=(const CMySmartPointer<T>& pc_other)
{
	if (pc_counter->iDec() == 0) {
		delete pc_pointer;
		delete pc_counter;
	}

	pc_pointer = pc_other.pc_pointer;
	pc_counter = pc_other.pc_counter;
	pc_counter->iAdd();
}
