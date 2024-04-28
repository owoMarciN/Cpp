#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> CountingSort(std::vector<int> A){
    int MaxValue = 0;
    for(int i = 0; i < A.size(); i++)
        MaxValue = std::max(MaxValue, A[i]);

    std::vector<int> C;
    std::vector<int> B;

    for(int i = 0; i <= MaxValue; i++)
        C.push_back(0);

    for(int i = 0; i < A.size(); i++)
        B.push_back(0);

    for(int i = 0; i < A.size(); i++)
        C[A[i]]++;

    for(int i = 1; i <= MaxValue; i++)
        C[i] += C[i - 1];

    for(int i = A.size() - 1; i >= 0; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    return B;
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

    std::cout << "Counting-Sort: " << std::endl;
    std::cout << "Before:" << std::endl;
    printVector(A);

    A = CountingSort(A);

    std::cout << "After:" << std::endl;
    printVector(A);

    return 0;
}