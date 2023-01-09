//Header File Binary Search Tree
#ifndef H_binaryTree
#define H_binaryTree

//*************************************************************
// Author: D.S. Malik
//
// class binaryTreeType
// This class specifies the basic operations to implement a
// binary tree.
//*************************************************************

#include <iostream>

using namespace std;

     //Definition of the node
template <class Type>
struct binaryTreeNode
{
    Type info;
    binaryTreeNode<Type> *llink;
    binaryTreeNode<Type> *rlink;
	
	// default constructor
	binaryTreeNode()
		: info(NULL), llink(NULL), rlink(NULL) {}
	
	// overloaded constructor
	binaryTreeNode(Type info)
		: info(info), llink(NULL), rlink(NULL) {}
};

   //Definition of the class
template <class Type>
class binaryTreeType
{
	
public:
    const binaryTreeType<Type>& operator=
                 (const binaryTreeType<Type>&);
      //Overload the assignment operator.
    bool isEmpty() const;
      //Returns true if the binary tree is empty;
      //otherwise, returns false.
    void inorderTraversal() const;
      //Function to do an inorder traversal of the binary tree.
    void preorderTraversal() const;
      //Function to do a preorder traversal of the binary tree.
    void postorderTraversal() const;
      //Function to do a postorder traversal of the binary tree.

    int treeHeight() const;
      //Returns the height of the binary tree.
    int treeNodeCount() const;
      //Returns the number of nodes in the binary tree.
    int treeLeavesCount() const;
      //Returns the number of leaves in the binary tree.
    void destroyTree();
      //Deallocates the memory space occupied by the binary tree.
      //Postcondition: root = NULL;

    binaryTreeType(const binaryTreeType<Type>& otherTree);
      //copy constructor

    binaryTreeType();
      //default constructor

    ~binaryTreeType();
      //destructor

	
protected:
    binaryTreeNode<Type>  *root;

private:
    void copyTree(binaryTreeNode<Type>* &copiedTreeRoot,
                  binaryTreeNode<Type>* otherTreeRoot);
      //Makes a copy of the binary tree to which
      //otherTreeRoot points. The pointer copiedTreeRoot
      //points to the root of the copied binary tree.

    void destroy(binaryTreeNode<Type>* &p);
      //Function to destroy the binary tree to which p points. 
      //Postcondition: p = NULL

    void inorder(binaryTreeNode<Type> *p) const;
      //Function to do an inorder traversal of the binary
      //tree to which p points.  
    void preorder(binaryTreeNode<Type> *p) const;
      //Function to do a preorder traversal of the binary
      //tree to which p points.  
    void postorder(binaryTreeNode<Type> *p) const;
      //Function to do a postorder traversal of the binary
      //tree to which p points.  

    int height(binaryTreeNode<Type> *p) const;
      //Function to return the height of the binary tree
      //to which p points. 
    int max(int x, int y) const;
      //Returns the larger of x and y.
    int nodeCount(binaryTreeNode<Type> *p) const;
      //Function to return the number of nodes in the binary 
      //tree to which p points 
    int leavesCount(binaryTreeNode<Type> *p) const;
      //Function to return the number of leaves in the binary 
      //tree to which p points 
};

    //Definition of member functions

template <class Type>
binaryTreeType<Type>::binaryTreeType()
{
    root = NULL;
}

template <class Type>
bool binaryTreeType<Type>::isEmpty() const
{
    return (root == NULL);
}

template <class Type>
void binaryTreeType<Type>::inorderTraversal() const
{
    inorder(root);
}

template <class Type>
void binaryTreeType<Type>::preorderTraversal() const
{
    preorder(root);
}

template <class Type>
void binaryTreeType<Type>::postorderTraversal() const
{
    postorder(root);
}

template <class Type>
int binaryTreeType<Type>::treeHeight() const
{
    return height(root);
}

template <class Type>
int binaryTreeType<Type>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class Type>
int binaryTreeType<Type>::treeLeavesCount() const
{
    return leavesCount(root);
}

template <class Type>
void  binaryTreeType<Type>::copyTree
                      (binaryTreeNode<Type>* &copiedTreeRoot,
		               binaryTreeNode<Type>* otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode<Type>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
} //end copyTree

template <class Type>
void binaryTreeType<Type>::inorder(binaryTreeNode<Type> *p) const
{
    if (p != NULL)
    {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

template <class Type>
void binaryTreeType<Type>::preorder(binaryTreeNode<Type> *p) const
{
	if (p != NULL)
	{
		cout<<p->info<<" ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class Type>
void binaryTreeType<Type>::postorder(binaryTreeNode<Type> *p) const
{
    if (p != NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }		
}

     //Overload the assignment operator
template <class Type>
const binaryTreeType<Type>& binaryTreeType<Type>::
           operator=(const binaryTreeType<Type>& otherTree)
{  
    if (this != &otherTree) //avoid self-copy
    {
        if (root != NULL)  //if the binary tree is not empty, 
                           //destroy the binary tree
            destroy(root);

        if (otherTree.root == NULL) //otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }//end else

    return *this; 
}

template <class Type>
void  binaryTreeType<Type>::destroy(binaryTreeNode<Type>* &p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class Type>
void  binaryTreeType<Type>::destroyTree()
{
    destroy(root);
}

	//copy constructor
template <class Type>
binaryTreeType<Type>::binaryTreeType
              (const binaryTreeType<Type>& otherTree)
{
    if (otherTree.root == NULL) //otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class Type>
binaryTreeType<Type>::~binaryTreeType()
{
    destroy(root);
}

template <class Type>
int binaryTreeType<Type>::height(binaryTreeNode<Type> *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

template <class Type>
int binaryTreeType<Type>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class Type>
int binaryTreeType<Type>::nodeCount(binaryTreeNode<Type> *p) const
{
    cout << "Write the definition of the function nodeCount"
         << endl;

    return 0;
}

template <class Type>
int binaryTreeType<Type>::leavesCount(binaryTreeNode<Type> *p) const
{
    cout << "Write the definition of the function leavesCount"
         << endl;

    return 0;
}


/// OUTSIDE OF CLASS binaryTreeType
/*----------------------------------------------------------------------------------*/
template <class Type>
binaryTreeNode<Type>* createNode(Type info)
{
	binaryTreeNode<Type> *newNode = new binaryTreeNode<Type>();
	newNode->info = info;
	newNode->llink = NULL;
	newNode->rlink = NULL;
	return newNode;
}


template <class Type>
binaryTreeNode<Type>* createTree()
{
	// create a root node
	binaryTreeNode<Type>* root = createNode(53);
	
	// add second level
	root->llink = createNode(24);
	root->rlink = createNode(59);
	
	// add third level
	root->llink->llink = createNode(14);
	root->llink->rlink = createNode(28);
	root->rlink->rlink = createNode(85);
	
	return root;
}

#endif
