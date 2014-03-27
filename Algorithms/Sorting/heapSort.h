#ifndef HEAPSORT_H
#define HEAPSORT_H
#include "sort.h"

/*
  calculate the index of left child of an index in the heap array
  declare here because inline function needs to be declared in header file
*/
inline size_t LEFT (const size_t &index) {
  return 2*index+1;
}

inline size_t RIGHT (const size_t &index) {
  return 2*index+2;
}

inline size_t PARENT (const size_t &index) {
  return (index-1)/2;
}

/*
  idea: assume i's left children and right children are max-heap, adjust the position of the array so that i and its children are max-heap
  i: index of the value wanted to insert into the max-heap
  size: up to where the array is a heap-array, from 0 to length-1
  complexity: O(logn)
*/
void maxHeapify (int *array, size_t i, const size_t &size);

/*
  make the array a max-heap-array
  idea: for i=length/2 to length-1, A[i] is leaf.
        So iteratively heapify i=length/2-1 to 0
  complexity: O(nlogn)
*/
void buildMaxHeap (int *array);

#endif
