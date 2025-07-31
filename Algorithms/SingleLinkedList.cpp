#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class Node{
public:
    int value;
    Node * next;
};

class List{
public:
    Node * Head = nullptr;
    void push_back(int V);
    void print_List();
    Node * search_List(int V);
    void delete_Node(Node *&D);
    void sort_List();
    int size();
    bool empty();
};

void List::sort_List(){
    Node * i = Head;
    Node * minNode, *j;
    while(i){
        minNode = i;
        j = i->next;
        while(j){
            if(minNode->value > j->value){
                minNode = j;
            }
            j = j->next;
        }
        std::swap(i->value, minNode->value);
        i = i->next;
    }
}

bool List::empty(){
    if(Head)
        return 1;
    else
        return 0;
}

int List::size(){
    Node * current = Head;
    int count = 0;
    while(current){
        count++;
        current = current->next;
    }
    return count;
}

void List::push_back(int V){
    Node * newNode = new Node;
    newNode->value = V;
    newNode->next = nullptr;
    if(!Head){
        Head = newNode;
    }
    else{
        Node* current = Head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void List::print_List(){
    Node * current = Head;
    int count = 0;
    std::cout << "List: " << std::endl;
    while(current){
        std::cout << ++count << ". " << current->value << std::endl;
        current = current->next;
    }
}

Node * List::search_List(int V){
    Node * current = Head;
    while(current != nullptr && current->value != V){
        current = current->next;
    }
    return current;
}

void List::delete_Node(Node *&D){
    Node * current = Head;
    if(Head == D){
        Head = D->next;
    }
    else{
        while(current->next != D){
            current=current->next;
        }
        if(!D->next){
            current->next = nullptr;
        }
        else{
            current->next = D->next;
        }
    }
}

int main(){
    List ListA;
    int n, value;

    std::cout << "How many elements of the list you want to insert: ";
    std::cin >> n;

    srand(time(NULL));

    for(int i = 0; i < n; i++){
        ListA.push_back(rand() % 1000 + 1);
    }
    
    std::cout << std::endl;
    ListA.print_List();
    std::cout << std::endl;

    std::cout << "Which node you want to delete? (Provide the value): " << std::endl;
    std::cin >> value;

    Node * ToDelete = ListA.search_List(value);
    if(!ToDelete){
        std::cout << "This node DOESN'T EXISTS!\n" << std::endl;
    }
    else{
        std::cout << "Node deleted successfully!\n" << std::endl;
        ListA.delete_Node(ToDelete);
        ListA.print_List();
    }

    std::cout << "Size of the list: " << ListA.size() << std::endl;
    if(!ListA.empty()){
        std::cout << "List is EMPTY!\n" << std::endl;
    }
    else{
        std::cout << "The current list still have elements!\n" << std::endl;
    }

    //List Sorting
    std::cout << "List after sorting: " << std::endl;
    ListA.sort_List();
    ListA.print_List();

    return 0;
}
