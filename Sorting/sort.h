#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <cstdlib>

extern const size_t N;

/*
  insertionSort
  parameter: a reference to an integer array of size N
  complexity: O(N^2)
  idea: keep the front of the array sorted, everytime add a new element to the sorted sub-array
*/
void insertionSort (int *array);

/*
  merge sort
  idea: follows the divide-and-conquer logic. Keep spliting an array in half to two sub-arrays, and combine the sorted half-arrays
  complexity: O(n*logn)
*/
void mergeSort (int *array);


/*
  heap sort
  heap: a complete binary tree
  max-heap: parent>=child, min-heap: parent<=child
  idea: Build a maximal heap first. Everytime extract the root of the heap, put it in the end of the array. Get the last member in the heap to the root, re-max-heapify the heap.
  complexity: O(n*logn)
*/
void heapSort (int *array);

#endif
