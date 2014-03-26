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
*/
void mergeSort (int *array);


#endif
