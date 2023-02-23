//
//  tests.h
//  BinaryTree
//
//  Created by Mitch Campbell on 2023/02/20.
//

#ifndef tests_h
#define tests_h

// TODO: implement createBT()
// TODO: create BT and BST with random values

static void generateValues()
{
	const int AMOUNT = 6;	// amount of random numbers that need to be generated
	const int MAX = 100;	// maximum value
	
	int value[AMOUNT];		// array to store the random numbers
	srand(time(NULL));		// seed rand with sys time
	
	// generate random numbers
	for (int i = 0; i < AMOUNT; i++)
	{
		bool check;	// check if number is used
		int n;		// store each generated number
		
		do
		{
			n = rand() % MAX + 1;
			
			check = true;
			
			for (int j = 0; j < i; j++)
			{
				if (n == value[j])
				{
					check = false;
					break;	// no need to check the other elements of value
				}
			}
		}	while (!check);	// loop until new unique number is found
		value[i] = n;	// store the generated number in the array
	}
	
	cout << "Here are your values\n\n";
	for (int i = 0; i < AMOUNT; i++)
	{
		cout << value[i] << "\t";
	}
	cout << endl;
}


template <class Type>
void traverseTree(const binaryTreeType<Type>& tree)
{
	std::cout << "Pre-order: ";
	tree.preorderTraversal();
	std::cout << std::endl;

	std::cout << "In-order: ";
	tree.inorderTraversal();
	std::cout << std::endl;

	std::cout << "Post-order: ";
	tree.postorderTraversal();
	std::cout << std::endl;
}

static binaryTreeNode<int> *createBinaryTree()
{
	binaryTreeNode<int>* root = createNode(53);
	
	// add second level
	root->llink = createNode(24);
	root->rlink = createNode(59);
	
	// add third level
	root->llink->llink = createNode(14);
	root->llink->rlink = createNode(28);
	root->rlink->rlink = createNode(85);
	return root;
}

template <class Type>
bSearchTreeType<Type>* createBST()
{
	bSearchTreeType<int> myTree;
	myTree.insert(4);
	myTree.insert(5);
	myTree.insert(6);
	myTree.insert(1);
	myTree.insert(2);
	myTree.insert(3);
	return myTree;
}

static bSearchTreeType<int> enterNodes()
{
	bSearchTreeType<int>  treeRoot, otherTreeRoot;
	int num;
	std::cout << "Enter numbers ending with -999" << std::endl;
	std::cin >> num;
	while (num != -999)
	{
		treeRoot.insert(num);
		std::cin >> num;
	}
	return treeRoot;
}

static void test_traverseTree()
{
	bSearchTreeType<int> myTree;
	myTree.insert(4);
	myTree.insert(5);
	myTree.insert(6);
	myTree.insert(1);
	myTree.insert(2);
	myTree.insert(3);
	traverseTree(myTree);
}

static void test_nodeCount()
{
	// Test 1: Check that the function returns 0 for an empty tree
	{
		bSearchTreeType<int> empty_tree;
		assert(empty_tree.treeNodeCount() == 0);
	}

	// Test 2: Check that the function returns 1 for a tree with a single node
	{
		bSearchTreeType<int> single_node_tree;
		single_node_tree.insert(5);
		assert(single_node_tree.treeNodeCount() == 1);
	}

	// Test 3: Check that the function returns the correct number of nodes for a tree with multiple nodes
	{
		bSearchTreeType<int> multi_node_tree;
		multi_node_tree.insert(5);
		multi_node_tree.insert(3);
		multi_node_tree.insert(7);
		multi_node_tree.insert(1);
		multi_node_tree.insert(4);
		assert(multi_node_tree.treeNodeCount() == 5);
	}

	// Test 4: Check that the function returns the correct number of nodes for a tree with a single branch
	{
		bSearchTreeType<int> single_branch_tree;
		single_branch_tree.insert(5);
		single_branch_tree.insert(3);
		single_branch_tree.insert(1);
		single_branch_tree.insert(4);
		assert(single_branch_tree.treeNodeCount() == 4);
	}
}

static void test_leavesCount()
{
	// Test 1: Check that the function returns 0 for an empty tree
	{
		bSearchTreeType<int> empty_tree;
		assert(empty_tree.treeLeavesCount() == 0);
	}

	// Test 2: Check that the function returns 1 for a tree with a single node
	{
		bSearchTreeType<int> single_node_tree;
		single_node_tree.insert(5);
		assert(single_node_tree.treeLeavesCount() == 1);
	}

	// Test 3: Check that the function returns the correct number of leaves for a tree with multiple nodes
	{
		bSearchTreeType<int> multi_node_tree;
		multi_node_tree.insert(5);
		multi_node_tree.insert(3);
		multi_node_tree.insert(7);
		multi_node_tree.insert(1);
		multi_node_tree.insert(4);
		assert(multi_node_tree.treeLeavesCount() == 3);
	}

	// Test 4: Check that the function returns the correct number of leaves for a tree with a single branch
	{
		bSearchTreeType<int> single_branch_tree;
		single_branch_tree.insert(5);
		single_branch_tree.insert(3);
		single_branch_tree.insert(1);
		single_branch_tree.insert(4);
		assert(single_branch_tree.treeLeavesCount() == 2);
	}
}

static void test_height()
{
	// Test 1: Check that the function returns 0 for an empty tree
	{
		   bSearchTreeType<int> empty_tree;
		   assert(empty_tree.treeHeight() == 0);
	}

	// Test 2: Check that the function returns 1 for a tree with a single node
	{
		   bSearchTreeType<int> single_node_tree;
		   single_node_tree.insert(5);
		   assert(single_node_tree.treeHeight() == 1);
	}

	// Test 3: Check that the function returns the correct height for a tree with multiple nodes
	{
		   bSearchTreeType<int> multi_node_tree;
		   multi_node_tree.insert(5);
		   multi_node_tree.insert(3);
		   multi_node_tree.insert(7);
		   multi_node_tree.insert(1);
		   multi_node_tree.insert(4);
		   assert(multi_node_tree.treeHeight() == 3);
	}

	// Test 4: Check that the function returns the correct height for a tree with a single branch
	{
		   bSearchTreeType<int> single_branch_tree;
		   single_branch_tree.insert(5);
		   single_branch_tree.insert(3);
		   single_branch_tree.insert(1);
		   single_branch_tree.insert(4);
		   assert(single_branch_tree.treeHeight() == 3);
	}
}

static void test_swapSubtrees()
{
	// Test 1: Swap subtrees of an empty tree
	{
		bSearchTreeType<int> empty_tree;
		empty_tree.swapSubtrees(empty_tree.getRoot());
		assert(empty_tree.isEmpty());
	}

	// Test 2: Swap subtrees of a tree with only the root node
	{
		bSearchTreeType<int> root_only_tree;
		root_only_tree.insert(5);
		root_only_tree.swapSubtrees(root_only_tree.getRoot());
		assert(root_only_tree.getRoot()->info == 5);
		assert(root_only_tree.getRoot()->llink == NULL);
		assert(root_only_tree.getRoot()->rlink == NULL);
	}

	// Test 3: Swap subtrees of a tree with two levels
	{
		bSearchTreeType<int> two_level_tree;
		two_level_tree.insert(5);
		two_level_tree.getRoot()->llink = new binaryTreeNode<int>(3);
		two_level_tree.getRoot()->rlink = new binaryTreeNode<int>(7);
		two_level_tree.swapSubtrees(two_level_tree.getRoot());
		assert(two_level_tree.getRoot()->info == 5);
		assert(two_level_tree.getRoot()->llink->info == 7);
		assert(two_level_tree.getRoot()->rlink->info == 3);
	}

	// Test 4: Swap subtrees of a tree with three levels
	{
		bSearchTreeType<int> three_level_tree;
		three_level_tree.insert(5);
		three_level_tree.getRoot()->llink = new binaryTreeNode<int>(3);
		three_level_tree.getRoot()->rlink = new binaryTreeNode<int>(7);
		three_level_tree.getRoot()->llink->llink = new binaryTreeNode<int>(1);
		three_level_tree.getRoot()->llink->rlink = new binaryTreeNode<int>(4);
		three_level_tree.getRoot()->rlink->llink = new binaryTreeNode<int>(6);
		three_level_tree.getRoot()->rlink->rlink = new binaryTreeNode<int>(9);
		three_level_tree.swapSubtrees(three_level_tree.getRoot());
		assert(three_level_tree.getRoot()->info == 5);
		assert(three_level_tree.getRoot()->llink->info == 7);
		assert(three_level_tree.getRoot()->rlink->info == 3);
		assert(three_level_tree.getRoot()->llink->llink->info == 9);
		assert(three_level_tree.getRoot()->llink->rlink->info == 6);
		assert(three_level_tree.getRoot()->rlink->llink->info == 4);
		assert(three_level_tree.getRoot()->rlink->rlink->info == 1);
	}
}

static void test_swapRoot()
{
	// Test 1: Swap root of an empty tree
	{
		bSearchTreeType<int> empty_tree;
		empty_tree.swapRoot();
		assert(empty_tree.isEmpty());
	}

	// Test 2: Swap root of a tree with only the root node
	{
		bSearchTreeType<int> root_only_tree;
		root_only_tree.insert(5);
		root_only_tree.swapRoot();
		assert(root_only_tree.getRoot()->info == 5);
		assert(root_only_tree.getRoot()->llink == NULL);
		assert(root_only_tree.getRoot()->rlink == NULL);
	}

	// Test 3: Swap root of a tree with two levels
	{
		bSearchTreeType<int> two_level_tree;
		two_level_tree.insert(5);
		two_level_tree.getRoot()->llink = new binaryTreeNode<int>(3);
		two_level_tree.getRoot()->rlink = new binaryTreeNode<int>(7);
		two_level_tree.swapRoot();
		assert(two_level_tree.getRoot()->info == 5);
		assert(two_level_tree.getRoot()->llink->info == 7);
		assert(two_level_tree.getRoot()->rlink->info == 3);
	}

	// Test 4: Swap root of a tree with three levels
	{
		bSearchTreeType<int> three_level_tree;
		three_level_tree.insert(5);
		three_level_tree.getRoot()->llink = new binaryTreeNode<int>(3);
		three_level_tree.getRoot()->rlink = new binaryTreeNode<int>(7);
		three_level_tree.getRoot()->llink->llink = new binaryTreeNode<int>(1);
		three_level_tree.getRoot()->llink->rlink = new binaryTreeNode<int>(4);
		three_level_tree.getRoot()->rlink->llink = new binaryTreeNode<int>(6);
		three_level_tree.getRoot()->rlink->rlink = new binaryTreeNode<int>(9);
		three_level_tree.swapRoot();
		assert(three_level_tree.getRoot()->info == 5);
		assert(three_level_tree.getRoot()->llink->info == 7);
		assert(three_level_tree.getRoot()->rlink->info == 3);
		assert(three_level_tree.getRoot()->llink->llink->info == 6);
		assert(three_level_tree.getRoot()->llink->rlink->info == 9);
		assert(three_level_tree.getRoot()->rlink->llink->info == 1);
		assert(three_level_tree.getRoot()->rlink->rlink->info == 4);
	}
}

static void test_doubleP()
{
	// Test case 1: Empty tree
	{
		bSearchTreeType<int> emptyTree;
		assert(emptyTree.doubleP(emptyTree.getRoot()) == 0);
	}

	// Test case 2: Tree with one node
	{
		bSearchTreeType<int> treeWithOneNode;
		treeWithOneNode.insert(10);
		assert(treeWithOneNode.doubleP(treeWithOneNode.getRoot()) == 0);
	}

	// Test case 3: Tree with two nodes, one parent and one child
	{
		bSearchTreeType<int> treeWithTwoNodes;
		treeWithTwoNodes.insert(20);
		treeWithTwoNodes.insert(10);
		assert(treeWithTwoNodes.doubleP(treeWithTwoNodes.getRoot()) == 0);
	}

	// Test case 4: Tree with three nodes, one parent and two children
	{
		bSearchTreeType<int> treeWithThreeNodes;
		treeWithThreeNodes.insert(20);
		treeWithThreeNodes.insert(10);
		treeWithThreeNodes.insert(30);
		assert(treeWithThreeNodes.doubleP(treeWithThreeNodes.getRoot()) == 1);
	}

	// Test case 5: Tree with four nodes, one parent and three children
	{
		bSearchTreeType<int> treeWithFourNodes;
		treeWithFourNodes.insert(20);
		treeWithFourNodes.insert(10);
		treeWithFourNodes.insert(30);
		treeWithFourNodes.insert(5);
		assert(treeWithFourNodes.doubleP(treeWithFourNodes.getRoot()) == 1);
	}

	// Test case 6: Tree with five nodes, two parents and three children
	{
		bSearchTreeType<int> treeWithFiveNodes;
		treeWithFiveNodes.insert(20);
		treeWithFiveNodes.insert(10);
		treeWithFiveNodes.insert(30);
		treeWithFiveNodes.insert(5);
		treeWithFiveNodes.insert(25);
		assert(treeWithFiveNodes.doubleP(treeWithFiveNodes.getRoot()) == 1);
	}

}

#endif /* tests_h */
