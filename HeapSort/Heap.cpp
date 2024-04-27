#include "Heap.h"

int Parent(int i){ return i/2;}
int Left(int i){ return 2 * i;}
int Right(int i){ return 2 * i + 1; }

void HeapSort(Heap &heap){
    BuildMaxHeap(heap, heap.A.size());
    for(int i = heap.HeapSize - 1; i > 0; i--){
        std::swap(heap.A[0], heap.A[i]);
        heap.HeapSize--;
        MaxHeapify(heap, 0);
    }
}

void BuildMaxHeap(Heap &heap, int n){
    heap.HeapSize = n;
    for(int i = floor(n/2); i >= 0; i--)
        MaxHeapify(heap, i);
}

void MaxHeapify(Heap &heap, int i){
    int largest;
    int l = Left(i);
    int r = Right(i);
    if(l < heap.HeapSize && heap.A[l] > heap.A[i])
        largest = l;
    else    
        largest = i;
    if(r < heap.HeapSize && heap.A[r] > heap.A[largest])
        largest = r;
    if(largest != i){
        std::swap(heap.A[i], heap.A[largest]);
        MaxHeapify(heap, largest);
    }
}   

void BuildMinHeap(Heap &heap, int n){
    heap.HeapSize = n;
    for(int i = floor(n/2); i >= 0; i--)
        MinHeapify(heap, i);
}

void MinHeapify(Heap &heap, int i){
    int min;
    int l = Left(i);
    int r = Right(i);
    if(l < heap.HeapSize && heap.A[l] < heap.A[i])
        min = l;
    else    
        min = i;
    if(r < heap.HeapSize && heap.A[r] < heap.A[min])
        min = r;
    if(min != i){
        std::swap(heap.A[i], heap.A[min]);
        MinHeapify(heap, min);
    }
}

void printHeap(Heap &heap){
    for(int i = 0; i < heap.A.size(); i++)
        std::cout << heap.A[i] << " ";
    std::cout << std::endl;
}

// int MaxHeapMaximum(Heap &heap){
//     if(heap.HeapSize < 0)
//         throw std::underflow_error("Heap underflow");
//     return heap.A[0];
// }

// int MaxHeapExtractMax(Heap &heap){
//     int max = MaxHeapMaximum(heap);
//     heap.A[0] = heap.A[heap.HeapSize];
//     heap.HeapSize--;
//     MaxHeapify(heap, 0);
// }