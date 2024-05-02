#include "BST.h"

int main(){
    BST T;
    int to_search;
    int node_num = 10;
    srand(time(NULL));

    Node * z;
    
    for(int i = 0; i < node_num; i++){
        z = createNode(rand()%100 + 1);
        T.RecursiveTreeInsert(z);
    }

    if(T.root){
        std::cout << "Tree form left to right:\n\n";
        T.drawTree(T.root, 0);
        std::cout << '\n';

        std::cout << "Maximum: " << T.Maximum(T.root) << '\n';
        
        std::cout << "Minimum: " << T.Minimum(T.root) << '\n';

        std::cout << "What number you want to search for?" << '\n';
        std::cin >> to_search;

        if(T.searchTree(T.root, to_search))
            std::cout << "Number \'" << to_search << "\' was found!\n" << '\n';
        else
            std::cout << "There's no \'" << to_search << "\' number in this tree!\n" << '\n';

        std::cout << "TREE WALKS:\n";
        std::cout << "Inorder\n";
        T.InOrder(T.root);
        std::cout << '\n';

        std::cout << "Preorder\n";
        T.PreOrder(T.root);
        std::cout << '\n';

        std::cout << "Postorder\n";
        T.PostOrder(T.root);
        std::cout << "\n\n";

        std::cout << "Provide the node value to find it's Predecessor and Successor:\n";
        std::cin >> to_search;

        z = T.SEARCH(T.root, to_search);

        if(z != NULL){
            std::cout << "Predecessor of the node: " << T.Predecessor(z) << '\n'; 
            std::cout << "Successor of the node: " << T.Successor(z) << '\n';
        }
        else
            std::cout << "Error: This node doesn't exists!\n";
    }
    else
        std::cout << "Error!\n";
    return 0;
}
