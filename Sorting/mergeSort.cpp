#include <climits>
#include "sort.h"

void divide (int *array, size_t start, size_t end);

void conquer (int *array, size_t start, size_t mid, size_t end);


void mergeSort (int *array) {
  //divide start from 0 to N-1
  divide (array, 0, N-1);
}


void divide (int *array, size_t start, size_t end) {
  if (start < end) {
    size_t mid = (start+end)/2;
    divide (array, start, mid);
    divide (array, mid+1, end);
    conquer (array, start, mid, end);
  }
}


void conquer (int *array, size_t start, size_t mid, size_t end) {
  //assume array[start->mid] and array[mid+1->end] are sorted, combine them in ascending order also
  
  //copy array[start->mid] to left, copy array[mid+1->end] to right
  size_t size_1 = mid-start+1;	//left size
  size_t size_2 = end-mid;	//right size
  int *left = new int[size_1+1] ();
  int *right = new int[size_2+1] ();
  for (size_t i=0; i<size_1; i++) 
    left[i] = array[i+start];
  left[size_1] = INT_MAX;
  for (size_t i=0; i<size_2; i++)
    right[i] = array[mid+1+i];
  right[size_2] = INT_MAX;

  //set up an index for both left and right
  size_t index1, index2;
  index1 = 0;
  index2= 0;

  //compare the pointed number and copy the number into array
  for(size_t i=start; i<=end; i++) {
    if(left[index1] <= right[index2]) {
      array[i] = left[index1];
      index1++;
    }
    else {
      array[i] = right[index2];
      index2++;
    }
  }

  delete[] left;
  delete[] right;
}
