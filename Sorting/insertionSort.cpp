#include <cstdlib>
#include "sort.h"


void insertionSort (int *array) {
  //the idea is to everytime add a new value to a sorted array
  //increment the sorted array's size from 1 to N

  for (size_t i=1; i<N; i++) {
    int value = array[i];
    size_t j = i-1;	//the last index of the already sorted array
    //want to add the i-th element to the previously sorted array
    //contaning j elements
    for (; j>=0; j--) {
      if (array[j]<=value) {
        //found the insertion point
	array[j+1] = value;
	break;
      }
      else {
        //array[j]>array[i]
	//move array[j] to array[j+1]
	array[j+1] = array[j];
      }
    }
  }
}
