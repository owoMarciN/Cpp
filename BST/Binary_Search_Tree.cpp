#include "BST.h"

int main(){
    BST Tree;
    
    int to_search;
    int node_num = 7;

    srand(time(NULL));

    // std::cout << "How many nodes should the tree have?" << std::endl;
    // std::cin >> node_num;

    for(int i = 0; i < node_num; i++){
        Tree.insertNode(Tree.root, rand() % 100+1);
    }

    if(Tree.root){
        std::cout << "Tree form left to right:\n" << std::endl;
        Tree.InOrder(Tree.root, 0);
        std::cout << std::endl;

        std::cout << "Maximum: " << Tree.MaxKey() << std::endl;
        std::cout << "Minimum: " << Tree.MinKey() << std::endl;

        // std::cout << "What number you want to search for?" << std::endl;
        // std::cin >> to_search;
        // if(Tree.searchTree(Tree.root, to_search)){
        //     std::cout << "Number \'" << to_search << "\' was found!" << std::endl;
        // }
        // else{
        //     std::cout << "There's no \'" << to_search << "\' number in this tree!" << std::endl;
        // }
        std::cout << "Inorder" << std::endl;
        Tree.InOrder(Tree.root);
        std::cout << std::endl;
        std::cout << "Preorder" << std::endl;
        Tree.PreOrder(Tree.root);
        std::cout << std::endl;
        std::cout << "Postorder" << std::endl;
        Tree.PostOrder(Tree.root);
        std::cout << std::endl;
    }
    else{
        std::cout << "Error!" << std::endl;
    }
    
    return 0;
}