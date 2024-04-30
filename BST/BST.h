#ifndef TREE_H_
#define TREE_H_

/// LIBRARIES ///
#include <iostream>

/// CONSTANTS ///
const int count = 10;

/// CLASSES ///
class Node{
public:
    int key;
    Node * left;
    Node * right;
};

class BST{
public:
    Node * root = nullptr;
    int MaxKey();
    int MinKey();
    bool searchTree(Node * root, int value);
    Node * insertNode(Node * &node, int value);
    void deleteNode(Node * root, int value);
    Node * Precessor(Node * root);
    Node * Successor(Node * root);
    void InOrder(Node * root, int space);
    void InOrder(Node * root);
    void PreOrder(Node * root);
    void PostOrder(Node * root);
    //void insertNode(int value);
};

#endif