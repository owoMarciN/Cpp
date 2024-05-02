#include "BST.h"

Node * createNode(int value){
    Node * node = new Node;
    node->key = value;
    node->left = node->right = nullptr;
    return node;
}

bool BST::searchTree(Node * x, int key){
    if(!x)
        return false;
    else if(x->key == key)
        return true;
    else if(key < x->key)
        return SEARCH(x->left, key);
    else
        return SEARCH(x->right, key);
}

void BST::RecursiveTreeInsert(Node * z){
    if(root == NULL)
        root = z;
    else
        INSERT(NULL, root, z);
}

void BST::drawTree(Node * root, int space){
    Node * current = root;
    if(current != NULL){
        space += count;
        drawTree(current->right, space);
        for(int i = count; i < space; i++)
            std::cout << " ";
        std::cout << current->key << '\n';
        drawTree(current->left, space); 
    } 
}

int BST::Maximum(Node * x){
    if(x->right != NULL)
        return Maximum(x->right);
    else 
        return x->key;
}

int BST::Minimum(Node * x){
    if(x->left != NULL)
        return Minimum(x->left);
    else 
        return x->key;
}

int BST::Predecessor(Node * x){
    if(x->left != NULL)
        return Maximum(x->left);
    Node * y = x->parent;
    while(y != NULL && x == y->left){
        x = y;
        y = y->parent;
    }
    return y->key;
}

int BST::Successor(Node * x){
    if(x->right != NULL)
        return Minimum(x->right);
    Node * y = x->parent;
    while(y != NULL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y->key;
}

void BST::InOrder(Node * x){
    if(x != NULL){
        InOrder(x->left);
        std::cout << x->key << " ";
        InOrder(x->right);
    }
}

void BST::PreOrder(Node * x){
    if(x != NULL){
        std::cout << x->key << " ";
        PreOrder(x->left);
        PreOrder(x->right);
    }
}

void BST::PostOrder(Node * x){
    if(x != NULL){
        PostOrder(x->left);
        PostOrder(x->right);
        std::cout << x->key << " ";
    }
}

void BST::RightRotate(Node * y){
    Node * x = y->left;
    y->left = x->right;
    if(x->right != NULL)
        x->right->parent = y;
    x->parent = y->parent;
    if(y->parent == NULL)
        root = x;
    else if(y == y->parent->right)
        y->parent->right = x;
    else 
        y->parent->left = x;
    x->right = y;
    y->parent = x;
}
   
void BST::LeftRotate(Node * x){
    Node * y = x->right;
    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else 
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void BST::INSERT(Node * p, Node * x, Node * z){
    if(x == NULL){
        z->parent = p;
        if(z->key < p->key)
            p->left = z;
        else
            p->right = z;
    }
    else if(z->key < x->key)
        INSERT(x, x->left, z);
    else
        INSERT(x, x->right, z);
}

Node * BST::SEARCH(Node * x, int key){
    if(!x)
        return NULL;
    else if(x->key == key)
        return x;
    else if(key < x->key)
        return SEARCH(x->left, key);
    else
        return SEARCH(x->right, key);
}

Node * BST::MAXIMUM(Node * x){
    if(x->right != NULL)
        return MAXIMUM(x->right);
    else 
        return x;
}

Node * BST::MINIMUM(Node * x){
    if(x->left != NULL)
        return MINIMUM(x->left);
    else 
        return x;
}
