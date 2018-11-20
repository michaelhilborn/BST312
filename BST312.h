/*  BST312.h
 CS 312 Fall 2018

 a simple implementation of a binary search tree


 */

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;

template<class ItemType>
class BST_312 {
public:

    BST_312();

    //Copy constructor
    BST_312(const BST_312 & src);

    ~BST_312();

    /****************************
     makeEmpty

     Function: Removes all the items from the BST.
     Preconditions: BST has been initialized
     Postconditions: All the items have been removed

     done
     *****************************/
    void makeEmpty();

    /****************************
     isEmpty

     Function: Checks to see if there are any items in the BST.
     Preconditions: BST has been initialized
     Postconditions: Returns true if there are no items in the BST, else false.

     done
     *****************************/
    bool isEmpty() const;

    /****************************
     isFull

     Function: Determines if you have any more room to add items to the BST
     Preconditions: BST has been initialized
     Postconditions: Returns true if there is no more room to add items, else false

     done
     *****************************/
    bool isFull() const;

    /****************************
     insertItem

     Function: Adds newItem to the BST.
     Preconditions: BST has been initialized and is not full.
     Postconditions: newItem is in the proper position for a BST.

     done
     *****************************/
    void insertItem(const ItemType &);

    /****************************
     deleteItem

     Function: Removes target from BST.
     Preconditions: BST has been initialized.
     Postconditions: If found, element has been removed from BST.

     done
     *****************************/
    void deleteItem(const ItemType& newItem);

    /****************************
     countNodes

     Function: Counts the number of nodes in the BST
     Preconditions: BST has been initialized.
     Postconditions: returns the number of nodes in the BST

     done
     *****************************/
    int countNodes();

    /****************************
     preOrderTraversal

     Function: Returns the preOder (Node, Left, Right) as a vector of ItemTypes
     Preconditions: BST has been initialized.
     Postconditions: none

     done
     *****************************/
    vector<ItemType> preOrderTraversal();

    /****************************
     inOrderTraversal

     Function: Returns the inOder (Left, Node, Right) as a vector of ItemTypes
     Preconditions: BST has been initialized.
     Postconditions: none

     done
     *****************************/
    vector<ItemType> inOrderTraversal();

    /****************************
     postOrderTraversal

     Function: returns the postOder (Left, Right, Node) as a vector of ItemTypes
     Preconditions: BST has been initialized.
     Postconditions: none

     done
     *****************************/
    vector<ItemType> postOrderTraversal();

    /********************
     isItemInTree

     Function: Determines if a given Item is in tree.
     Preconditions: BST has been initialized.
     Postconditions: none

     done
     *****************************/

    bool isItemInTree(const ItemType& item);


private:
    struct TreeNode {
        ItemType data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode * root;

    /*********************
     Function: inserts an item into the BST
     Preconditions: BST has been initialized.
     Postconditions: the item has been inserted into the BST

     done
     *********************/
    void insertItem(TreeNode*& t, const ItemType& newItem);

    /****************************
     inOrderTraversal

     Function: Returns the inOder (Left, Node, Right) as a vector of ItemTypes
     Preconditions: BST has been initialized.
     Postconditions: none

     done
     *****************************/
    void inOrderTraversal(TreeNode* t,vector<ItemType>& result) const;

    /****************************
     countNodes

     Function: Counts the number of nodes in the BST
     Preconditions: BST has been initialized.
     Postconditions: returns the number of nodes in the BST in the numNodes variable

     done
     *****************************/
    void countNodes(TreeNode* t, int &numNodes);

    /****************************
     deleteItem

     Function: Removes node from BST.
     Preconditions: BST has been initialized.
     Postconditions: If found, node has been removed from BST.

     done
     *****************************/
    void deleteNode(TreeNode*& node);

    /*********************
     Function: clears the dynamically allocated tree
     Preconditions: BST has been initialized.
     Postconditions: BST has had all the memory deleted

     done
     *********************/
    void makeEmpty(TreeNode*& t);

    /****************************
     deleteItem

     Function: Removes target from BST.
     Preconditions: BST has been initialized.
     Postconditions: If found, element has been removed from BST.

     done
     *****************************/
    void deleteItem(TreeNode*& t, const ItemType& newItem);

    /****************************
     getPredecessor

     Function: finds the largest item
     Preconditions: BST has been initialized.
     Postconditions:

     done
     *****************************/
    void getPredecessor(TreeNode* t, ItemType& data);

    /****************************
     preOrderTraversal

     Function: Returns the inOder (Node, Left, Right) as a vector of ItemTypes
     Preconditions: BST has been initialized.
     Postconditions: none

     done
     *****************************/
    void preOrderTraversal(TreeNode* t,vector<ItemType>& result) const;

    /****************************
     postOrderTraversal

     Function: Returns the inOder (Left, Right, Node) as a vector of ItemTypes
     Preconditions: BST has been initialized.
     Postconditions: none

     done
     *****************************/
    void postOrderTraversal(TreeNode* t,vector<ItemType>& result) const;

    /****************************
     copyTree

     Function: copies the item from original tree to the copy
     Preconditions: BST has been initialized.
     Postconditions: the copy will be an identical copy to the original tree that is not a shallow copy

     done
     *****************************/
    void copyTree(TreeNode*& copy, const TreeNode *originalTree);

};

/*******************************
//Function implementations
 ********************************/

template<class ItemType>
BST_312<ItemType>::BST_312 ()
{
    root = NULL;
}

template<class ItemType>
BST_312<ItemType>::BST_312(const BST_312 & src)
{
    copyTree(root, src.root);
}

template<class ItemType>
BST_312<ItemType>::~BST_312()
{
    makeEmpty();

}


template<class ItemType>
void BST_312<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->data = originalTree->data;

        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}


template<class ItemType>
void BST_312 <ItemType>::deleteNode(TreeNode*& t)
{
    ItemType info;
    TreeNode *tempPtr;

    tempPtr = t;

    if (t->left == NULL)
    {
        t = t->right;
        delete tempPtr;
    }
    else if (t->right == NULL)
    {
        t = t->left;
        delete tempPtr;
    }
    else
    {
        getPredecessor(t->left, info);
        t->data = info;
        deleteItem(t->left, info);
    }
}



//find largest in left subtree
template<class ItemType>
void BST_312 <ItemType>::getPredecessor(TreeNode* t, ItemType& data)
{

    while (t->right != NULL){
        t = t->right;
    }

    data = t->data;

}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
    if (t == NULL)
        return;
    else if (newItem < t->data)
        deleteItem(t->left, newItem);
    else if (newItem > t->data)
        deleteItem(t->right, newItem);
    else
        deleteNode(t);
}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(const ItemType& newItem)
{
    deleteItem(root, newItem);

}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty(TreeNode*& t){

    if(t->left != NULL){
        makeEmpty(t->left);
    }
    delete t->left;

    if(t->right != NULL){
        makeEmpty(t->right);
    }
    delete t->right;
}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty()
{
    makeEmpty(root);
    root = NULL;
}

template<class ItemType>
bool BST_312 <ItemType>::isEmpty() const
{
    return root == NULL;
}



template<class ItemType>
bool BST_312 <ItemType>::isFull() const
{
    try
    {
        TreeNode *temp = new TreeNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }

}


template<class ItemType>
void BST_312 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem){
    if(t == NULL){
        TreeNode temp = new TreeNode;
        temp->data = newItem;
        temp->left = NULL;
        temp->right = NULL;
        t = temp;
    }
    else if(t->data < newItem){

        insertItem(t->left, newItem);
    }
    else if(t->data > newItem){

        insertItem(t->right, newItem);
    }
}

template<class ItemType>
void BST_312 <ItemType>::insertItem(const ItemType& newItem){

    insertItem(root, newItem);
}

template<class ItemType>
void BST_312 <ItemType>::countNodes(TreeNode* t, int &numNodes){

    if(t->left != NULL){
        countNodes(t->left, numNodes);
    }
    if(t->right != NULL){
        countNodes(t->right, numNodes);
    }

    numNodes ++;
}


template<class ItemType>
int BST_312 <ItemType>::countNodes()
{
    int numNodes = 0;
    countNodes(root, numNodes);
    return numNodes;
}

template<class ItemType>
void BST_312 <ItemType>::preOrderTraversal(TreeNode* t,vector<ItemType>& result) const{

    result.push_back(t->data);

    if(t->left != NULL){
        preOrderTraversal(t->left, result);
    }

    if(t->right != NULL){
        preOrderTraversal(t->right, result);
    }
}


template<class ItemType>
vector<ItemType> BST_312 <ItemType>::preOrderTraversal()
{
    vector<ItemType> result;

    preOrderTraversal(root, result);
    return result;
}

template<class ItemType>
void BST_312 <ItemType>::inOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{

    if(t->left != NULL){
        inOrderTraversal(t->left, result);
    }

    result.push_back(t->data);

    if(t->right != NULL){
        inOrderTraversal(t->right, result);
    }

}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::inOrderTraversal()
{
    vector<ItemType> result;

    inOrderTraversal(root, result);
    return result;
}

template<class ItemType>
void BST_312 <ItemType>::postOrderTraversal(TreeNode* t,vector<ItemType>& result) const{

    if(t->left != NULL){
        postOrderTraversal(t->left, result);
    }

    if(t->right != NULL){
        postOrderTraversal(t->right, result);
    }

    result.push_back(t->data);
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::postOrderTraversal()
{
    vector<ItemType> result;

    postOrderTraversal(root, result);
    return result;
}

template<class ItemType>
bool BST_312 <ItemType>::isItemInTree(const ItemType& item)
{
    bool itemFound = false;

    vector<ItemType> data;
    data = inOrderTraversal();

    vector<ItemType> temp;

    for(int i = 0; i < data.size(); i++){

        temp = data.pop_back();
        if(data == temp){
            itemFound = true;
        }
    }
    return itemFound;
}

#endif
