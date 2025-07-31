#include <iostream>
#include <vector>

void BubbleSort(std::vector<int> &A){
    for(int i = 0; i < A.size(); i++){
        for(int j = A.size()-1; j > i; j--){
            if(A[j] < A[j-1]){
                std::swap(A[j], A[j-1]);
            }
        }
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

    std::cout << "Bubble-Sort: " << std::endl;
    std::cout << "Before:" << std::endl;
    printVector(A);

    BubbleSort(A);

    std::cout << "After:" << std::endl;
    printVector(A);

    return 0;
}
