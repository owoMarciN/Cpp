#include "Heap.h"

// How to compile? ----> g++ HeapSort.cpp Heap.cpp //

int main(){
    int arraysize;
    srand(time(NULL));

    Heap heap;

    std::cout << "Provide the number of random elements: " << std::endl;
    std::cin >> arraysize;

    for(int i= 0; i < arraysize; i++)
        heap.A.push_back(rand()%200+1);
    //heap.A = {5, 3, 17, 10, 84, 19, 6, 22, 9};

    std::cout << "Max-Heap:" << std::endl;
    Heap copy = heap;
    BuildMaxHeap(copy, copy.A.size());
    printHeap(copy);

    std::cout << "Min-Heap:" << std::endl;
    BuildMinHeap(copy, copy.A.size());
    printHeap(copy);

    std::cout << std::endl;

    std::cout << "Before sorting:" << std::endl;
    printHeap(heap);

    HeapSort(heap);

    std::cout << "After sorting:" << std::endl;
    printHeap(heap);   

    return 0;
}