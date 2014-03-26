#include "sort.h"
#include "heapSort.h"

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


/*
  buildHeap (A) {
    length = N
    //as index in [length/2, ..., length-1] are all leafs, they are originally max-heapified
    for (i=length/2-1; i>=0; i--) 
      maxHeapify (A, i, length-1);
  }
*/


/*
  heapSort (A) {
    buildHeap (A)
    for size=length-1 to 1
      switch A[0] and A[size]
      size--
      maxHeapify (A, 0, size)
  }
*/
