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

int main()
{
	test_traverseTree();

	return 0;
}
