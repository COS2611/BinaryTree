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

#endif /* tests_h */
