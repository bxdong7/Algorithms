#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <cstdlib>

/*
  insertionSort
  parameter: a reference to an Teger array of size N
  complexity: O(N^2)
  idea: keep the front of the array sorted, everytime add a new element to the sorted sub-array
*/
template <class T, size_t N>
void insertionSort (T (&array)[N]);


/*
  merge sort
  idea: follows the divide-and-conquer logic. Keep spliting an array in half to two sub-arrays, and combine the sorted half-arrays
  complexity: O(n*logn)
*/
template <class T, size_t N>
void mergeSort (T (&array)[N]);


/*
  heap sort
  heap: a complete binary tree
  max-heap: parent>=child, min-heap: parent<=child
  idea: Build a maximal heap first. Everytime extract the root of the heap, put it in the end of the array. Get the last member in the heap to the root, re-max-heapify the heap.
  complexity: O(n*logn)
*/
template <class T, size_t N>
void heapSort (T (&array)[N]);


/*
  quick sort
  idea: divide-conquer-combine. 
  	Divide partitions the subarray such that the last element is a pivot, and all elements before the pivot is smaller than it, all elements after it is larger than it.
	Conquer: keeps partitioning until the subarray contains only one element
	Combine: do nothing, because after the previous two steps, the array is already sorted
  complexity: worst case O(n^2). Average O(cnlogn), but the constant is very small.
*/
template <class T, size_t N>
void quickSort (T (&array)[N]);


/*
  counting sort
  condition: input array of size n, each element in the range [0, k], where k is O(n)
  idea: three loops
  	first go through the array to count the frequency of element value in [0, k]
	second calculate the number of elements in array whose value is no larger than i in [0, k]
	third put each element in the array in the correct position
  complexity: O(k+n)=O(n)
*/
template <class T, size_t N>
void countingSort (T (&array)[N], const long &k);
#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "heapSort.h"
#include "quickSort.cpp"
#include "countingSort.cpp"

#endif
