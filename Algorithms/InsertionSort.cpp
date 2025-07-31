#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> &A){
    int key, j;
    for(int i = 1; i < A.size(); i++){
        key = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--; 
        }
        A[j+1] = key;
    }
}

void printVector(std::vector<int> &A){
    for(int i = 0; i < A.size(); i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main(){
    int vectorSize;
    std::vector<int> A;
    srand(time(NULL));

    std::cout << "Provide array size: ";
    std::cin >> vectorSize;

    for(int i = 0; i < vectorSize; i++)
        A.push_back(rand() % 200 + 1);

    std::cout << "Insertion-Sort: " << std::endl;
    std::cout << "Before:" << std::endl;
    printVector(A);

    InsertionSort(A);

    std::cout << "After:" << std::endl;
    printVector(A);

    return 0;
}
