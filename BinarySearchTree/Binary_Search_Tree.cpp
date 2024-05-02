#include "BST.h"

int main(){
    BST T;
    int to_search;

    /*
    HOW THE TREE LOOKS LIKE

           50
          /  \
        17   76
       /  \
      9   23

    */
    Node * z = new Node;
    z = createNode(50);
    T.RecursiveTreeInsert(z);
    z = createNode(17);
    T.RecursiveTreeInsert(z);
    z = createNode(76);
    T.RecursiveTreeInsert(z);
    z = createNode(9);
    T.RecursiveTreeInsert(z);
    z = createNode(23);
    T.RecursiveTreeInsert(z);

    // DRAWING THE TREE

    std::cout << "Tree form left to right:\n";
    T.drawTree(T.root, 0);
    std::cout << '\n';

    // MINUMUM AND MAXIMUM

    std::cout << "Maximum: " << T.getMax(T.root) << '\n';
    std::cout << "Minimum: " << T.getMin(T.root) << '\n';

    // SEARCHING THE TREE FOR THE GIVEN VALUE

    std::cout << "What value to search for?" << '\n';
    std::cin >> to_search;

    if(T.searchTree(T.root, to_search))
        std::cout << "Number \'" << to_search << "\' was found!\n" << '\n';
    else
        std::cout << "There's no \'" << to_search << "\' value in this tree!\n" << '\n';

    // TREE WALKS

    std::cout << "TREE WALKS:\n";
    std::cout << "Inorder:\n";
    T.InOrder(T.root);
    std::cout << '\n';

    std::cout << "Preorder:\n";
    T.PreOrder(T.root);
    std::cout << '\n';

    std::cout << "Postorder:\n";
    T.PostOrder(T.root);
    std::cout << "\n";

    // SUCCESSOR AND PREDECESSOR OF A GIVEN VALUE

    std::cout << "Provide the value to find it's Predecessor and Successor:\n";
    std::cin >> to_search;

    z = T.getElementByValue(to_search);
    if(z != NULL){
        try{
            std::cout << "Predecessor of the node: " << T.getPredecessor(z) << '\n'; 
        }
        catch(const std::runtime_error &e){
            std::cout << "\rError: " << e.what() << '\n';
        }
        try{
            std::cout << "Successor of the node: " << T.getSuccessor(z) << '\n'; 
        }
        catch(const std::runtime_error &e){
            std::cout << "\rError: " << e.what() << '\n';
        }
    }
    else
        std::cout << "Error: Node with the give value doesn't exists!\n";

    // LEFT AND RIGHT ROTATIONS

    std::cout << "Performing the right-rotation on the value \'50\':\n";

    T.RightRotate(T.root);
    T.drawTree(T.root, 0);

    std::cout << "Inorder:\n";
    T.InOrder(T.root);
    std::cout << '\n';

    std::cout << "Performing the left-rotation on the value \'17\':\n";

    T.LeftRotate(T.root);
    T.drawTree(T.root, 0);

    std::cout << "Inorder:\n";
    T.InOrder(T.root);
    std::cout << '\n';

    // DELETION OF A NODE
    
    std::cout << "Deleting node with the value \'17\':\n";
    z = T.getElementByValue(17);
    T.DeleteNode(z);

    T.drawTree(T.root, 0);

    std::cout << "Inorder:\n";
    T.InOrder(T.root);
    std::cout << '\n';

    delete z;
    return 0;
}
