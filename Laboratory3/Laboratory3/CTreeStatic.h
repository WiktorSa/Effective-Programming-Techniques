#pragma once
#include <iostream>
#include <vector>

class CNodeStatic
{
	public:
		CNodeStatic() { i_val = 0; pc_parent_node = NULL; };
		CNodeStatic(const CNodeStatic& other);
		//~CNodeStatic() {};
		
		void vSetValue(int i_val) { this->i_val = i_val; };

		int iGetChildrenNumber() { return v_children.size(); };
		void vAddNewChild();
		void vAddNewChild(CNodeStatic pc_child);
		CNodeStatic* pcGetChild(int i_child_offset);

		void vPrint() { std::cout << " " << i_val; };
		void vPrintAllBelow();
		void vPrintAllUp();
		
		bool bCanRemove() { return pc_parent_node != NULL; };
		void vRemoveFromParent();
		

	private: 
		std::vector<CNodeStatic> v_children;
		CNodeStatic* pc_parent_node;
		int i_val;
};

class CTreeStatic
{
	public:
		CTreeStatic() { c_root = CNodeStatic(); };
		~CTreeStatic() {};

		CNodeStatic* pcGetRoot() { return &c_root; };
		void vPrintTree() { c_root.vPrintAllBelow(); };
		bool bMoveSubtree(CNodeStatic* pc_parent, CNodeStatic* pc_child);

	private:
		CNodeStatic c_root;
};
