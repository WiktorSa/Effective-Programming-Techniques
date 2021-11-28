#include "CTreeStatic.h"
#include <iostream>

CNodeStatic::CNodeStatic(const CNodeStatic& other)
{
	i_val = other.i_val;
	// We can copy the pointer to the parent 
	pc_parent_node = other.pc_parent_node;

	// Copy children (do not forget to update the pointers to parents)
	for (CNodeStatic child : other.v_children)
	{
		CNodeStatic updated_node(child);
		this->vAddNewChild(updated_node);
	}
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic child;
	this->vAddNewChild(child);
}

void CNodeStatic::vAddNewChild(CNodeStatic pc_child)
{
	pc_child.pc_parent_node = this;
	v_children.push_back(pc_child);
}

CNodeStatic* CNodeStatic::pcGetChild(int i_child_offset)
{
	if (i_child_offset < 0 || i_child_offset >= iGetChildrenNumber()) {
		return NULL;
	}

	return &v_children.at(i_child_offset);
}

void CNodeStatic::vPrintAllBelow()
{
	vPrint();
	for (CNodeStatic child : v_children)
	{
		child.vPrintAllBelow();
	}
}

void CNodeStatic::vPrintAllUp()
{
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintAllUp();
	}
}

// Force parent to remove one of it's children
void CNodeStatic::vRemoveFromParent()
{
	if (this->bCanRemove()) {
		int i_index_removal = -1;
		for (int i = 0; i < pc_parent_node->iGetChildrenNumber(); i++)
		{
			if (&pc_parent_node->v_children.at(i) == this) {
				i_index_removal = i;
			}
		}

		pc_parent_node->v_children.erase(pc_parent_node->v_children.begin() + i_index_removal);
	}
}

/*
Quick note on copy:
We copy pc_child because after calling vRemoveFromParent pc_child points to the next value in the vector
For instance if pc_child points to CNodeStatic with i_val = 54 than after vRemoveFromParent it will point to
CNodeStatic with i_val = 55
*/

bool CTreeStatic::bMoveSubtree(CNodeStatic* pc_parent, CNodeStatic* pc_child)
{
	if (pc_child->bCanRemove()) {
		CNodeStatic pc_child_copy(*pc_child);
		pc_child->vRemoveFromParent();
		pc_parent->vAddNewChild(pc_child_copy);
		return true;
	}

	return false;
}
