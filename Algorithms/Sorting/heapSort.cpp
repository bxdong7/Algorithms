#include <iostream>
#include "sort.h"
#include "heapSort.h"
#include "utility.h"

/*
  maxHeapify (A, i, size) {
    left = left(i);
    right = right(i);
    largest = i;
    if(A[left]>A[i])&&(left<=size)
      largest = left
    if(A[right]>A[largest])&&(right<=size)
      largest = right

    switch A[i] and A[largest]
    if(i!=largest)
      maxHeapify(A, largest, size)
  }
*/
template <class T, size_t N>
void maxHeapify (T (&array)[N], size_t i, const size_t &size) {
  size_t left = LEFT(i);
  size_t right = RIGHT(i);
  size_t largest = i;
  if((left<=size) && (array[largest]<array[left]))
    largest = left;
  if((right<=size) && (array[largest]<array[right]))
    largest = right;

  if(largest != i) {
    T tmp = array[i];
    array[i] = array[largest];
    array[largest] = tmp;
    maxHeapify (array, largest, size);
  }
}


/*
  buildHeap (A) {
    length = N
    //as index in [length/2, ..., length-1] are all leafs, they are originally max-heapified
    for (i=length/2-1; i>=0; i--) 
      maxHeapify (A, i, length-1);
  }
*/
template <class T, size_t N>
void buildMaxHeap (T (&array)[N]) {
  size_t length = N;
  for(long i=length/2-1; i>=0; i--) {
    maxHeapify (array, i, length-1);
  }
}


/*
  heapSort (A) {
    buildHeap (A)
    for size=length-1 to 1
      switch A[0] and A[size]
      size--
      maxHeapify (A, 0, size)
  }
*/
template <class T, size_t N>
void heapSort (T (&array)[N]) {
  buildMaxHeap (array);
  size_t length = N;
  size_t size = length-1;
  for (; size>0; ) {
    T max = array[0];
    array[0] = array[size];
    array[size] = max;
    size--;
    maxHeapify(array, 0, size);
  }
}
