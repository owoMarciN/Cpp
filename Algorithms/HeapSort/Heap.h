#ifndef HEAP_H_
#define HEAP_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

struct Heap{
    int HeapSize;
    std::vector<int> A;
};

void HeapSort(Heap &heap);

// MAX-HEAP FUNCTIONS //
void BuildMaxHeap(Heap &heap, int n);
void MaxHeapify(Heap &heap, int i);

// MIN-HEAP FUNCTIONS //
void BuildMinHeap(Heap &heap, int n);
void MinHeapify(Heap &heap, int i);

// FUTURE PROJECT MAX-PRIORITY QUEUE

// int MaxHeapMaximum(Heap &heap);
// int MaxHeapExtractMax(Heap &heap);

void printHeap(Heap &heap);

int Parent(int i);
int Left(int i);
int Right(int i);

#endif