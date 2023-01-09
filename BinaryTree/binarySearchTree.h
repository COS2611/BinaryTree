//Header File Binary Search Tree

#ifndef H_binarySearchTree
#define H_binarySearchTree
#include <iostream>
#include <cassert>
#include "binaryTree.h"

//*************************************************************
// Author: D.S. Malik
//
// This class specifies the basic operations to implement a
// binary search tree.
//*************************************************************

using namespace std;

template <class Type>
class bSearchTreeType: public binaryTreeType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine if searchItem is in the binary 
      //search tree.
      //Postcondition: Returns true if searchItem is found in the 
      //    binary search tree; otherwise, returns false.

    void insert(const Type& insertItem);
      //Function to insert insertItem in the binary search tree.
      //Postcondition: If no node in the binary search tree has the
      //    same info as insertItem, a node with the info insertItem
      //    is created and inserted in the binary search tree.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the binary search tree 
      //Postcondition: If a node with the same info as deleteItem 
      //    is found, it is deleted from the binary search tree.

private:
    void deleteFromTree(binaryTreeNode<Type>* &p);
      //Function to delete the node to which p points is deleted
      //from the binary search tree.
      //Postcondition: The node to which p points is deleted from
      //    the binary search tree.
};


template <class Type>
bool bSearchTreeType<Type>::
              search(const Type& searchItem) const
{
    binaryTreeNode<Type> *current;
    bool found = false;

    if (binaryTreeType<Type>::root == NULL)
       cerr << "Cannot search the empty tree." << endl;
    else
    { 
        current = binaryTreeType<Type>::root;

        while (current != NULL && !found)
        {
            if (current->info == searchItem)
                found = true;
            else if (current->info > searchItem)
                current = current->llink;
            else
                current = current->rlink;
        }//end while
    }//end else

    return found;
}//end search

template <class Type>
void bSearchTreeType<Type>::insert(const Type& insertItem)
{
    binaryTreeNode<Type> *current;  	//pointer to traverse the tree
    binaryTreeNode<Type> *trailCurrent; //pointer behind current
    binaryTreeNode<Type> *newNode;  	//pointer to create the node

    newNode = new binaryTreeNode<Type>;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (binaryTreeType<Type>::root == NULL)
        binaryTreeType<Type>::root = newNode;
    else
    {
        current = binaryTreeType<Type>::root;
 
        while (current != NULL)
        {
            trailCurrent = current;

            if (current->info == insertItem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed." 
                     << insertItem << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->llink;
            else
                current = current->rlink;
        }//end while

        if (trailCurrent->info > insertItem)
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
}//end insert

template <class Type>
void bSearchTreeType<Type>::deleteNode(const Type& deleteItem)
{
    binaryTreeNode<Type> *current;  //pointer to traverse the tree
    binaryTreeNode<Type> *trailCurrent; //pointer behind current
    bool found = false;

    if (binaryTreeType<Type>::root == NULL)
        cout << "Cannot delete from the empty tree." << endl;
    else
    {
        current = binaryTreeType<Type>::root;
        trailCurrent = binaryTreeType<Type>::root;

        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }//end while

        if (current == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (found)
        {
            if (current == binaryTreeType<Type>::root)
                deleteFromTree(binaryTreeType<Type>::root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->llink);
            else
                deleteFromTree(trailCurrent->rlink);
        }//end if
    }
}//end deleteNode

template <class Type>
void bSearchTreeType<Type>::deleteFromTree
                                 (binaryTreeNode<Type>* &p)
{
    binaryTreeNode<Type> *current; //pointer to traverse the tree
    binaryTreeNode<Type> *trailCurrent;   //pointer behind current
    binaryTreeNode<Type> *temp;        //pointer to delete the node

    if (p == NULL)
        cerr << "Error: The node to be deleted is NULL." << endl;
    else if(p->llink == NULL && p->rlink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if(p->llink == NULL)
    {
        temp = p;
        p = temp->rlink;
        delete temp;
    }
    else if(p->rlink == NULL)
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else
    {
        current = p->llink;
        trailCurrent = NULL;

        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }//end while

        p->info = current->info;

        if (trailCurrent == NULL) //current did not move; 
                                  //current == p->llink; adjust p
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;
 
        delete current;
    }//end else
}//end deleteFromTree


#endif
