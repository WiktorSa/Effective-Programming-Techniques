#include <iostream>
#include "CTreeStatic.h"
#include "CTreeDynamic.h"

int main()
{
	// Test Static
	std::cout << "c_root test" << std::endl;
	CNodeStatic c_root;

	c_root.vAddNewChild();
	c_root.vAddNewChild();

	c_root.pcGetChild(0)->vSetValue(1);
	c_root.pcGetChild(1)->vSetValue(2);

	c_root.pcGetChild(0)->vAddNewChild();
	c_root.pcGetChild(0)->vAddNewChild();

	c_root.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	c_root.pcGetChild(1)->vAddNewChild();
	c_root.pcGetChild(1)->vAddNewChild();

	c_root.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	c_root.vPrint();
	std::cout << std::endl;
	c_root.vPrintAllBelow();
	std::cout << std::endl;
	c_root.pcGetChild(0)->pcGetChild(1)->vPrintAllUp();

	std::cout << std::endl << std::endl << "c_tree test" << std::endl;
	CTreeStatic c_tree;
	c_tree.pcGetRoot()->vSetValue(2);
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vAddNewChild();
	c_tree.pcGetRoot()->vPrintAllBelow();

	// Test Dynamic
	std::cout << std::endl << std::endl << "pc_root test" << std::endl;
	CNodeDynamic* pc_root = new CNodeDynamic();

	pc_root->vAddNewChild();
	pc_root->vAddNewChild();

	pc_root->pcGetChild(0)->vSetValue(1);
	pc_root->pcGetChild(1)->vSetValue(2);

	pc_root->pcGetChild(0)->vAddNewChild();
	pc_root->pcGetChild(0)->vAddNewChild();

	pc_root->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	pc_root->pcGetChild(0)->pcGetChild(1)->vSetValue(12);

	pc_root->pcGetChild(1)->vAddNewChild();
	pc_root->pcGetChild(1)->vAddNewChild();

	pc_root->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	pc_root->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

	pc_root->vPrint();
	std::cout << std::endl;
	pc_root->vPrintAllBelow();
	std::cout << std::endl;
	pc_root->pcGetChild(0)->pcGetChild(1)->vPrintAllUp();

	std::cout << std::endl << std::endl << "pc_tree test" << std::endl;
	CTreeDynamic* pc_tree = new CTreeDynamic();
	pc_tree->pcGetRoot()->vSetValue(2);
	pc_tree->pcGetRoot()->vAddNewChild();
	pc_tree->pcGetRoot()->vAddNewChild();
	pc_tree->pcGetRoot()->vPrintAllBelow();


	std::cout << std::endl << std::endl << "bMoveSubtree for static test" << std::endl;
	CTreeStatic tree_1;
	tree_1.pcGetRoot()->vAddNewChild();
	tree_1.pcGetRoot()->vAddNewChild();
	tree_1.pcGetRoot()->vAddNewChild();
	tree_1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
	tree_1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	tree_1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	tree_1.pcGetRoot()->pcGetChild(2)->vSetValue(3);
	tree_1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	CTreeStatic tree_2;
	tree_2.pcGetRoot()->vAddNewChild();
	tree_2.pcGetRoot()->vAddNewChild();
	tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	tree_2.pcGetRoot()->vSetValue(50);
	tree_2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
	tree_2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
	tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
	tree_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	tree_1.pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;
	tree_2.pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;

	std::cout << tree_1.bMoveSubtree(tree_1.pcGetRoot(), tree_2.pcGetRoot()) << std::endl;
	std::cout << tree_1.bMoveSubtree(tree_1.pcGetRoot()->pcGetChild(2), tree_2.pcGetRoot()->pcGetChild(0)) << std::endl;
	tree_1.pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;
	tree_2.pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;
	tree_1.pcGetRoot()->pcGetChild(2)->pcGetChild(1)->pcGetChild(0)->vPrintAllUp();

	std::cout << std::endl << std::endl << "bMoveSubtree for dynamic test" << std::endl;
	CTreeDynamic* tree_3 = new CTreeDynamic();
	tree_3->pcGetRoot()->vAddNewChild();
	tree_3->pcGetRoot()->vAddNewChild();
	tree_3->pcGetRoot()->vAddNewChild();
	tree_3->pcGetRoot()->pcGetChild(2)->vAddNewChild();
	tree_3->pcGetRoot()->pcGetChild(0)->vSetValue(1);
	tree_3->pcGetRoot()->pcGetChild(1)->vSetValue(2);
	tree_3->pcGetRoot()->pcGetChild(2)->vSetValue(3);
	tree_3->pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

	CTreeDynamic* tree_4 = new CTreeDynamic();
	tree_4->pcGetRoot()->vAddNewChild();
	tree_4->pcGetRoot()->vAddNewChild();
	tree_4->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_4->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	tree_4->pcGetRoot()->vSetValue(50);
	tree_4->pcGetRoot()->pcGetChild(0)->vSetValue(54);
	tree_4->pcGetRoot()->pcGetChild(1)->vSetValue(55);
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

	tree_3->pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;
	tree_4->pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;

	std::cout << tree_3->bMoveSubtree(tree_3->pcGetRoot(), tree_4->pcGetRoot()) << std::endl;
	std::cout << tree_3->bMoveSubtree(tree_3->pcGetRoot()->pcGetChild(2), tree_4->pcGetRoot()->pcGetChild(0)) << std::endl;
	tree_3->pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;
	tree_4->pcGetRoot()->vPrintAllBelow();
	std::cout << std::endl;
	tree_3->pcGetRoot()->pcGetChild(2)->pcGetChild(1)->pcGetChild(0)->vPrintAllUp();
	std::cout << std::endl;


	delete pc_root;
	delete pc_tree;
	delete tree_3;
	delete tree_4;


	std::cout << std::endl << "Modification:" << std::endl;
	CTreeDynamic tree_modification_1;
	tree_modification_1.pcGetRoot()->vSetValue(1);

	tree_modification_1.pcGetRoot()->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(0)->vSetValue(2);

	tree_modification_1.pcGetRoot()->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(1)->vSetValue(3);

	tree_modification_1.pcGetRoot()->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(2)->vSetValue(88);

	tree_modification_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(4);

	tree_modification_1.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(5);

	tree_modification_1.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(7);

	tree_modification_1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->pcGetChild(0)->vSetValue(9);

	tree_modification_1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vAddNewChild();
	tree_modification_1.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->pcGetChild(1)->vSetValue(17);

	std::cout << "Tree 1" << std::endl;
	tree_modification_1.vPrintTree();
	std::cout << std::endl;
	tree_modification_1.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrintAllUp();
	std::cout << std::endl << std::endl;

	CTreeDynamic tree_modification_2;
	tree_modification_2.pcGetRoot()->vSetValue(13);

	tree_modification_2.pcGetRoot()->vAddNewChild();
	tree_modification_2.pcGetRoot()->pcGetChild(0)->vSetValue(4);
	
	tree_modification_2.pcGetRoot()->vAddNewChild();
	tree_modification_2.pcGetRoot()->pcGetChild(1)->vSetValue(5);

	tree_modification_2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_modification_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(6);

	std::cout << "Tree 2" << std::endl;
	tree_modification_2.vPrintTree();
	std::cout << std::endl;
	tree_modification_2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrintAllUp();
	std::cout << std::endl << std::endl;

	CTreeDynamic tree_modification_3 = *tree_modification_1.multiplyTrees(&tree_modification_2);

	std::cout << "Tree 3" << std::endl;
	tree_modification_3.vPrintTree();
	std::cout << std::endl;
	tree_modification_3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrintAllUp();
	std::cout << std::endl << std::endl;

	return 0;
}
