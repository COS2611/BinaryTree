// binaryTree.cpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binaryTree.h"
#include "binarySearchTree.h"
#include "tests.h"


int main()
{
//	bSearchTreeType<int> treeRoot = enterNodes();
//	std::cout << "Number of nodes: " << treeRoot.treeNodeCount() << std::endl;
//	std::cout << "Number of Leaves: " << treeRoot.treeLeavesCount() << std::endl;
//	std::cout << "Tree height: " << treeRoot.treeHeight() << std::endl;
//	traverseTree(treeRoot);
	
	test_leavesCount();
	test_nodeCount();
	test_height();
	test_swapSubtrees();
	test_swapRoot();
	
	return 0;
}
