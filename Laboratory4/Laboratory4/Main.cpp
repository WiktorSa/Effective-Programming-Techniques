#include <iostream>
#include <string>
#include "CTreeDynamic.h"

int main()
{
	// Test dynamic nodes
	std::cout << "pc_root test" << std::endl;
	CNodeDynamic<int>* pc_root = new CNodeDynamic<int>;

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

	// Test dynamic tree
	std::cout << std::endl << std::endl << "pc_tree test" << std::endl;
	CTreeDynamic<std::string>* pc_tree = new CTreeDynamic<std::string>();
	pc_tree->pcGetRoot()->vSetValue("Hello");
	pc_tree->pcGetRoot()->vAddNewChild();
	pc_tree->pcGetRoot()->vAddNewChild();
	pc_tree->pcGetRoot()->pcGetChild(0)->vSetValue("World");
	pc_tree->pcGetRoot()->pcGetChild(1)->vSetValue("!");
	pc_tree->pcGetRoot()->vPrintAllBelow();

	// Test bMoveSubtree for dynamic trees
	std::cout << std::endl << std::endl << "bMoveSubtree for dynamic test" << std::endl;
	CTreeDynamic<double>* tree_3 = new CTreeDynamic<double>();
	tree_3->pcGetRoot()->vAddNewChild();
	tree_3->pcGetRoot()->vAddNewChild();
	tree_3->pcGetRoot()->vAddNewChild();
	tree_3->pcGetRoot()->pcGetChild(2)->vAddNewChild();
	tree_3->pcGetRoot()->pcGetChild(0)->vSetValue(42.3);
	tree_3->pcGetRoot()->pcGetChild(1)->vSetValue(2.42);
	tree_3->pcGetRoot()->pcGetChild(2)->vSetValue(3.52);
	tree_3->pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4.1);

	CTreeDynamic<double>* tree_4 = new CTreeDynamic<double>();
	tree_4->pcGetRoot()->vAddNewChild();
	tree_4->pcGetRoot()->vAddNewChild();
	tree_4->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_4->pcGetRoot()->pcGetChild(0)->vAddNewChild();
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
	tree_4->pcGetRoot()->vSetValue(50.35);
	tree_4->pcGetRoot()->pcGetChild(0)->vSetValue(54.242);
	tree_4->pcGetRoot()->pcGetChild(1)->vSetValue(55.42);
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56.657);
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57.11);
	tree_4->pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58.001);

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
	std::cout << std::endl << std::endl;


	delete pc_root;
	delete pc_tree;
	delete tree_3;
	delete tree_4;

	std::cout << "Modification" << std::endl;
	CTreeDynamic<int>* mod1 = new CTreeDynamic<int>;
	mod1->pcGetRoot()->vAddNewChild();
	mod1->pcGetRoot()->vAddNewChild();
	mod1->pcGetRoot()->vAddNewChild();
	mod1->vPrintTree();

	std::cout << std::endl << std::endl;

	CTreeDynamic<bool>* mod2 = new CTreeDynamic<bool>;
	mod2->pcGetRoot()->vAddNewChild();
	mod2->pcGetRoot()->vAddNewChild();
	mod2->pcGetRoot()->vAddNewChild();
	mod2->vPrintTree();

	std::cout << std::endl;

	delete mod1;
	delete mod2;

	return 0;
}