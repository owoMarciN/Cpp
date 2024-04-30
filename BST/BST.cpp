#include "BST.h"

bool BST::searchTree(Node * node, int value){
    if(!node)
        return false;
    else if(node->key == value){
        return true;
    }
    else if(value < node->key){
        return searchTree(node->left, value);
    }
    else{
        return searchTree(node->right, value);
    }
}

int BST::MaxKey(){
    Node * current = root;
    while(current->right){
        current = current->right;
    }
    return current->key;
}

int BST::MinKey(){
    Node * current = root;
    while(current->left){
        current = current->left;
    }
    return current->key;
}

Node * createNode(int value){
    Node * node = new Node;
    node->key = value;
    node->left = node->right = nullptr;
    return node;
}

Node * BST::insertNode(Node * &node, int data){
    if(!node){
        node = createNode(data);
        return node;
    }
    if(data < node->key)
        node->left = insertNode(node->left, data);
    else if (data >= node->key)
        node->right = insertNode(node->right, data); 

    return node;
}

// INSERT FUNCTION ITERATIVE APPROACH //
// void BST::insertNode(int value){
//     Node * newNode = createNode(value);
//     if(!root){
//         root = newNode;
//     }
//     else{
//         Node * current = root;
//         while(1){
//             if(current->key <= newNode->key && !current->right){
//                 current->right = newNode;
//                 break;
//             }
//             else if(current->key <= newNode->key && current->right){
//                 current = current->right;
//             }
//             else if(current->key > newNode->key && !current->left){
//                 current->left = newNode;
//                 break;
//             }
//             else{
//                 current = current->left;
//             }
//         }
//     }
// }

void BST::InOrder(Node * root, int space){
    Node * current = root;
    if(!current){
        return;
    }

    space += count;

    InOrder(current->right, space);

    for(int i = count; i < space; i++)
        std::cout << " ";
    std::cout << current->key << '\n';

    InOrder(current->left, space);  
}

void BST::InOrder(Node * root){
    Node * current = root;
    if(!current){
        return;
    }
    InOrder(current->right);
    std::cout << current->key << ' ';
    InOrder(current->left);  
}

void BST::PreOrder(Node * root){
    Node * current = root;
    if(!current){
        return;
    }
    std::cout << current->key << ' ';
    PreOrder(current->right);
    PreOrder(current->left);  
}

void BST::PostOrder(Node * root){
    Node * current = root;
    if(!current){
        return;
    }
    PostOrder(current->right);
    PostOrder(current->left);  
    std::cout << current->key << " ";
}

//  BST-Predecessor(x)
//      if x.left ≠ NIL then
//          return BST-Maximum(x.left)
//      end if
//      y := x.parent
//      while y ≠ NIL and x = y.left do
//          x := y
//          y := y.parent
//      repeat
//      return y
// Node * Precessor(Node * root){

// }

// BST-Successor(x)
//      if x.right ≠ NIL then
//          return BST-Minimum(x.right)
//      end if
//      y := x.parent
//      while y ≠ NIL and x = y.right do
//          x := y
//          y := y.parent
//      repeat
//      return y

// Node * Successor(Node * root){

// }

// 1    BST-Delete(BST, D)
// 2      if D.left = NIL then
// 3        Shift-Nodes(BST, D, D.right)
// 4      else if D.right = NIL then
// 5        Shift-Nodes(BST, D, D.left)
// 6      else
// 7        E := BST-Successor(D)
// 8        if E.parent ≠ D then
// 9          Shift-Nodes(BST, E, E.right)
// 10         E.right := D.right
// 11         E.right.parent := E
// 12       end if
// 13       Shift-Nodes(BST, D, E)
// 14       E.left := D.left
// 15       E.left.parent := E
// 16     end if



// 1    Shift-Nodes(BST, u, v)
// 2      if u.parent = NIL then
// 3        BST.root := v
// 4      else if u = u.parent.left then
// 5        u.parent.left := v
// 5      else
// 6        u.parent.right := v
// 7      end if
// 8      if v ≠ NIL then
// 9        v.parent := u.parent
// 10     end if