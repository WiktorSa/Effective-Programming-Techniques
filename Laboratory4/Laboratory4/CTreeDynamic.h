#pragma once
#include <vector>
#include <iostream>
#include <limits>

template <typename T> class CNodeDynamic
{
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(T i_val) { this->i_val = i_val; };

	int iGetChildrenNumber() { return v_children.size(); };
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic<T>* pc_child);
	CNodeDynamic<T>* pcGetChild(int i_child_offset);

	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintAllUp();

	bool bCanRemove() { return pc_parent_node != NULL; };
	void vRemoveFromParent();


private:
	std::vector<CNodeDynamic*> v_children;
	CNodeDynamic<T>* pc_parent_node;
	T i_val;
	static const int iMaxNumChildren;
};

template <typename T> class CTreeDynamic
{
public:
	CTreeDynamic() { pc_root = new CNodeDynamic<T>; };
	~CTreeDynamic() { delete pc_root; };

	CNodeDynamic<T>* pcGetRoot() { return pc_root; }
	void vPrintTree() { pc_root->vPrintAllBelow(); };
	bool bMoveSubtree(CNodeDynamic<T>* pc_parent, CNodeDynamic<T>* pc_child);

private:
	CNodeDynamic<T>* pc_root;
};

const int CNodeDynamic<bool>::iMaxNumChildren = 2;
template <typename T>
const int CNodeDynamic<T>::iMaxNumChildren = std::numeric_limits<int>::max();

template <typename T>
CNodeDynamic<T>::CNodeDynamic()
{
	i_val = {};
	pc_parent_node = NULL;
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
	for (int i = 0; i < this->iGetChildrenNumber(); i++)
	{
		delete v_children.at(i);
	}

	v_children.clear();
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild()
{
	if (iGetChildrenNumber() < iMaxNumChildren) {
		CNodeDynamic<T>* pc_child = new CNodeDynamic<T>;
		this->vAddNewChild(pc_child);
	}
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T>* pc_child)
{
	if (iGetChildrenNumber() < iMaxNumChildren) {
		pc_child->pc_parent_node = this;
		v_children.push_back(pc_child);
	}
	else {
		delete pc_child;
	}
}

template <typename T>
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int i_child_offset)
{
	if (i_child_offset < 0 || i_child_offset >= iGetChildrenNumber()) {
		return NULL;
	}

	return v_children.at(i_child_offset);
}


template <typename T>
void CNodeDynamic<T>::vPrintAllBelow()
{
	vPrint();
	for (int i = 0; i < iGetChildrenNumber(); i++)
	{
		v_children.at(i)->vPrintAllBelow();
	}
}

template <typename T>
void CNodeDynamic<T>::vPrintAllUp()
{
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintAllUp();
	}
}

// Force one of the parents to remove it's children
template <typename T>
void CNodeDynamic<T>::vRemoveFromParent()
{
	if (this->bCanRemove()) {
		std::vector<CNodeDynamic<T>*> v_children;
		for (int i = 0; i < pc_parent_node->iGetChildrenNumber(); i++)
		{
			if (pc_parent_node->v_children.at(i) != this) {
				v_children.push_back(pc_parent_node->v_children.at(i));
			}
		}

		this->pc_parent_node->v_children = v_children;
	}
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T>* pc_parent, CNodeDynamic<T>* pc_child)
{
	if (pc_child->bCanRemove()) {
		pc_child->vRemoveFromParent();
		pc_parent->vAddNewChild(pc_child);
		return true;
	}

	return false;
}
