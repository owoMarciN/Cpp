#include <iostream>
#include <vector>
#include <cmath>

void Merge(std::vector<int> &A, int start, int mid, int end){
    int nL = mid - start + 1;
    int nR = end - mid;
    
    std::vector<int> L;
    std::vector<int> R;

    for(int i = 0; i < nL; i++)
        L.push_back(A[start + i]);
    for(int j = 0; j < nR; j++)
        R.push_back(A[mid + j + 1]);

    int i, j, k;
    i = 0;
    j = 0;
    k = start;

    while( i < L.size() && j < R.size()){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < L.size()){
        A[k] = L[i];
        i++; k++;
    }
    while( j < R.size()){
        A[k] = R[j];
        j++; k++;
    }
}

void MergeSort(std::vector<int> &A, int start, int end){
    if(start < end){
        int mid = floor((start + end)/2);
        MergeSort(A, start, mid);
        MergeSort(A, mid+1, end);
        Merge(A, start, mid, end);
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

    std::cout << "Merge-Sort: " << std::endl;
    std::cout << "Before:" << std::endl;
    printVector(A);

    MergeSort(A, 0, A.size()-1);

    std::cout << "After:" << std::endl;
    printVector(A);

    return 0;
}
