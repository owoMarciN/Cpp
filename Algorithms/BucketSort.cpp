#include <iostream>
#include <vector>

void InsertionSort(std::vector<double> &bucket){
    for (int i = 1; i < bucket.size(); i++) {
        float key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j+1] = bucket[j];
            j--;
        }
        bucket[j+1] = key;
    }
}

void BucketSort(std::vector<double> &A, int n) {
    // 1) Create n empty buckets
    std::vector<double> B[n];

    // 2) Put array elements in different buckets
    for(int i = 0; i < n; i++){
        int nB = n * A[i];
        B[nB].push_back(A[i]);
    }

    // 3) Sort individual buckets using Insertion_Sort
    for(int i = 0; i < n; i++) {
        InsertionSort(B[i]);
    }

    // 4) Concatenate all buckets into A[]
    int index = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < B[i].size(); j++){
            A[index++] = B[i][j];
        }
    }
}


int main() {
    std::vector<double> A = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    BucketSort(A, A.size());

    std::cout << "Sorted array is \n";
    for(auto &num : A)
        std::cout << num << " ";
    std::cout << '\n';

    return 0;
}
