// binaryTree.cpp
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binaryTree.h"
#include "binarySearchTree.h"

using namespace std;


// TODO: implement createBT()
// TODO: create BT and BST with random values

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


static void generateValues() {
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
		value[i] = n;	// store the genrated number in the aarray
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

template <class Type>
int leavesCount(binaryTreeNode<Type>* root)
{
	if (!root)
	{
		return 0;
		
	}
	else if (!root->llink && !root->rlink)
	{
		return 1;
		
	}
	else
	{
		return leavesCount(root->llink) + leavesCount(root->rlink);
	}
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

static void test_leavesCount()
{
	// Test 0: binary tree created with createBinaryTree()
	binaryTreeNode<int> * root = createBinaryTree();
	assert(leavesCount(root) == 3);
	
	// Test 1: Check that the function returns 0 for an empty tree
	binaryTreeNode<int>* empty_tree = NULL;
	assert(leavesCount(empty_tree) == 0);
	
	// Test 2: Check that the function returns 1 for a tree with a single node
	binaryTreeNode<int>* single_node_tree = new binaryTreeNode<int>(5);
	assert(leavesCount(single_node_tree) == 1);
	
	// Test 3: Check that the function returns the correct number of leaves for a tree with multiple nodes
	binaryTreeNode<int>* multi_node_tree = new binaryTreeNode<int>(5);
	multi_node_tree->llink = new binaryTreeNode<int>(3);
	multi_node_tree->rlink = new binaryTreeNode<int>(7);
	multi_node_tree->llink->llink = new binaryTreeNode<int>(1);
	multi_node_tree->llink->rlink = new binaryTreeNode<int>(4);
	assert(leavesCount(multi_node_tree) == 3);
	
	// Test 4: Check that the function returns the correct number of leaves for a tree with a single branch
	binaryTreeNode<int>* single_branch_tree = new binaryTreeNode<int>(5);
	single_branch_tree->llink = new binaryTreeNode<int>(3);
	single_branch_tree->llink->llink = new binaryTreeNode<int>(1);
	single_branch_tree->llink->rlink = new binaryTreeNode<int>(4);
	assert(leavesCount(single_branch_tree) == 2);
}


int main()
{
	test_leavesCount();

	return 0;
}
