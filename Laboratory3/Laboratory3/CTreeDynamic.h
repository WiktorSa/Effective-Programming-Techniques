#pragma once
#include <vector>
#include <iostream>

class CNodeDynamic
{
	public:
		CNodeDynamic() { i_val = 0; pc_parent_node = NULL; };
		~CNodeDynamic();
		void vSetValue (int i_val) { this->i_val = i_val; };

		int iGetChildrenNumber() { return v_children.size(); };
		void vAddNewChild();
		void vAddNewChild(CNodeDynamic* pc_child);
		CNodeDynamic* pcGetChild(int i_child_offset);

		void vPrint() { std::cout << " " << i_val; };
		void vPrintAllBelow();
		void vPrintAllUp();

		bool bCanRemove() { return pc_parent_node != NULL; };
		void vRemoveFromParent();
		CNodeDynamic* multiplyNodes(CNodeDynamic* other);
		

	private:
		std::vector<CNodeDynamic*> v_children;
		CNodeDynamic* pc_parent_node;
		int i_val;
};


class CTreeDynamic
{
	public:
		CTreeDynamic() { pc_root = new CNodeDynamic(); };
		~CTreeDynamic() { delete pc_root; };

		CNodeDynamic* pcGetRoot() { return pc_root; }
		void vPrintTree() { pc_root->vPrintAllBelow(); };
		bool bMoveSubtree(CNodeDynamic* pc_parent, CNodeDynamic* pc_child);
		CTreeDynamic* multiplyTrees(CTreeDynamic* other);
	
	private:
		CNodeDynamic* pc_root;
};

