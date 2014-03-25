#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

/*
  insertionSort
  parameter: a reference to an integer array of any size
  complexity: O(N^2)
  N is a template non-type parameter
  idea: keep the front of the array sorted, everytime add a new element to the sorted sub-array
*/
template <size_t N>
void insertionSort (int (&array)[N]);

/*
  merge sort
  idea: follows the divide-and-conquer logic. Keep spliting an array in half to two sub-arrays, and combine the sorted half-arrays
*/
template <size_t N>
void mergeSort (int (&array)[N]);


#endif
