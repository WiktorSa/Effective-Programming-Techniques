#include "CTreeDynamic.h"

CNodeDynamic::~CNodeDynamic()
{
	for (int i = 0; i < this->iGetChildrenNumber(); i++)
	{
		delete v_children.at(i);
	}

	v_children.clear();
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic* pc_child = new CNodeDynamic;
	this->vAddNewChild(pc_child);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic* pc_child)
{
	pc_child->pc_parent_node = this;
	v_children.push_back(pc_child);
}

CNodeDynamic* CNodeDynamic::pcGetChild(int i_child_offset)
{
	if (i_child_offset < 0 || i_child_offset >= iGetChildrenNumber()) {
		return NULL;
	}

	return v_children.at(i_child_offset);
}

void CNodeDynamic::vPrintAllBelow()
{
	vPrint();
	for (int i = 0; i < iGetChildrenNumber(); i++)
	{
		v_children.at(i)->vPrintAllBelow();
	}
}

void CNodeDynamic::vPrintAllUp()
{
	vPrint();
	if (pc_parent_node != NULL) {
		pc_parent_node->vPrintAllUp();
	}
}

// Force one of the parents to remove it's children
void CNodeDynamic::vRemoveFromParent()
{
	if (this->bCanRemove()) {
		std::vector<CNodeDynamic*> v_children;
		for (int i = 0; i < pc_parent_node->iGetChildrenNumber(); i++)
		{
			if (pc_parent_node->v_children.at(i) != this) {
				v_children.push_back(pc_parent_node->v_children.at(i));
			}
		}
		this->pc_parent_node->v_children = v_children;
	}
}

CNodeDynamic* CNodeDynamic::multiplyNodes(CNodeDynamic* other)
{
	CNodeDynamic* pc_result = new CNodeDynamic;
	
	// Calculate the value of the node
	pc_result->i_val = this->i_val * other->i_val;

	// Calculate the number of children
	int i_children_number = 0;
	if (this->iGetChildrenNumber() > other->iGetChildrenNumber()) {
		i_children_number = other->iGetChildrenNumber();
	}
	else {
		i_children_number = this->iGetChildrenNumber();
	}

	// Add children (vAddNewChild will update the parent)
	for (int i = 0; i < i_children_number; i++)
	{
		CNodeDynamic* child = this->pcGetChild(i)->multiplyNodes(other->pcGetChild(i));
		pc_result->vAddNewChild(child);
	}

	return pc_result;
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic* pc_parent, CNodeDynamic* pc_child)
{
	if (pc_child->bCanRemove()) {
		pc_child->vRemoveFromParent();
		pc_parent->vAddNewChild(pc_child);
		return true;
	}

	return false;
}

CTreeDynamic* CTreeDynamic::multiplyTrees(CTreeDynamic* other)
{
	CTreeDynamic* tree_result = new CTreeDynamic;
	delete tree_result->pc_root;
	tree_result->pc_root = this->pc_root->multiplyNodes(other->pcGetRoot());
	return tree_result;
}
