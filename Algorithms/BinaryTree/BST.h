#ifndef TREE_H_
#define TREE_H_

/// LIBRARIES ///
#include <iostream>
#include <stdlib.h>
#include <time.h>

/// CONSTANTS ///
const int count = 10;

/// CLASSES ///
class Node{
public:

    int key;
    Node * parent;
    Node * left;
    Node * right;

};

class BST{
public:

    Node * root = nullptr;
    
    bool searchTree(Node * x, int key);
    void RecursiveTreeInsert(Node * z);
    void drawTree(Node * root, int space);
    
    int getMax(Node * x);
    int getMin(Node * x);
    int getPredecessor(Node * x);
    int getSuccessor(Node * x);

    void InOrder(Node * x);
    void PreOrder(Node * x);
    void PostOrder(Node * x);

    void RightRotate(Node * y);
    void LeftRotate(Node * x);

    void DeleteNode(Node * z);

    Node * getElementByValue(int value);

private:

    void INSERT(Node * p, Node * x, Node * z);
    Node * SEARCH(Node * x, int key);
    Node * MAXIMUM(Node * x);
    Node * MINIMUM(Node * x);
    Node * PREDECESSOR(Node * x);
    Node * SUCCESSOR(Node * x);
    void TRANSPLANT(Node * u, Node * v);

};

Node * createNode(int value);

#endif
