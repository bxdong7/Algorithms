#include <climits>
#include "sort.h"

template <class T, size_t N>
void divideConquer (T (&array)[N], size_t start, size_t end);

template <class T, size_t N>
void combine (T (&array)[N], size_t start, size_t mid, size_t end);


template <class T, size_t N>
void mergeSort (T (&array)[N]) {
  //divideConquer start from 0 to N-1
  divideConquer (array, 0, N-1);
}


template <class T, size_t N>
void divideConquer (T (&array)[N], size_t start, size_t end) {
  if (start < end) {
    size_t mid = (start+end)/2;
    divideConquer (array, start, mid);
    divideConquer (array, mid+1, end);
    combine (array, start, mid, end);
  }
}


template <class T, size_t N>
void combine (T (&array)[N], size_t start, size_t mid, size_t end) {
  //assume array[start->mid] and array[mid+1->end] are sorted, combine them in ascending order also
  
  //copy array[start->mid] to left, copy array[mid+1->end] to right
  size_t size_1 = mid-start+1;	//left size
  size_t size_2 = end-mid;	//right size
  T *left = new T[size_1+1] ();
  T *right = new T[size_2+1] ();
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

  //compare the poTed number and copy the number To array
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
