#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>& A) {
    const int n = A.size();
    for (int i = 0; i < n - 1; ++i) {
        int jMin = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[jMin]) {
                jMin = j;
            }
        }
        if (i != jMin) {
            std::swap(A[i], A[jMin]);
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

    std::cout << "Selection-Sort: " << std::endl;
    std::cout << "Before:" << std::endl;
    printVector(A);

    SelectionSort(A);

    std::cout << "After:" << std::endl;
    printVector(A);

    return 0;
}
