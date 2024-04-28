#include <iostream>
#include <vector>
#include <cmath>

void StableSort(std::vector<int> &A, int exp){  // Counting-Sort
    int MaxValue = 10;

    std::vector<int> C;
    std::vector<int> B;

    for(int i = 0; i <= MaxValue; i++)
        C.push_back(0);

    for(int i = 0; i < A.size(); i++)
        B.push_back(0);

    for(int i = 0; i < A.size(); i++)
        C[(A[i] / exp) % 10]++;

    for(int i = 1; i <= MaxValue; i++)
        C[i] += C[i - 1];

    for(int i = A.size() - 1; i >= 0; i--){
        B[C[(A[i] / exp) % 10] - 1] = A[i];
        C[(A[i] / exp) % 10]--;
    }

    for(int i = 0; i < A.size(); i++)
        A[i] = B[i];
}

int getMax(std::vector<int> A){
    int max = A[0];
    for(int i = 1; i < A.size(); i++)
        if(max < A[i])
            max = A[i];
    return max;        
}

void RadixSort(std::vector<int> &A, int digit){
    int MaxNum = getMax(A);
    for(int exp = 1;  MaxNum / exp > 0; exp *= 10)
        StableSort(A, exp);
}

void printVector(std::vector<int> &A){
    for(int i = 0; i < A.size(); i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int main(){
    int vectorSize, d;
    std::vector<int> A;
    srand(time(NULL));
    
    std::cout << "Provide the number of digits: " << std::endl;
    std::cin >> d;

    if(d <= 0)
        d = 3;
    
    std::cout << "Provide array size: ";
    std::cin >> vectorSize;

    int rmin, rmax;
    rmin = pow(10, d-1);
    rmax = 9*pow(10, d-1);
    for(int i = 0; i < vectorSize; i++)
        A.push_back(rand() % rmax + rmin);

    std::cout << "Radix-Sort: " << std::endl;
    std::cout << "Before:" << std::endl;
    printVector(A);

    RadixSort(A, d);

    std::cout << "After:" << std::endl;
    printVector(A);

    return 0;
}