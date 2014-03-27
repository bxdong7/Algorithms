#include "sort.h"

/*
  start: {0, ..., length-1}
  end: {0, ..., length-1}
  functions like the divide and conquer procedure: keeps partitioning the array until it only contains only one element.

  if(start<end) 
    value = array[end]
    i = start-1	//the index of the last element whose value is smaller than ${value}
    j = start	//the index of the last element whose value is larger than ${value}
    while (j < end)
      if (array[j] < value)
        switch array[j] and array[i+1]
	i++
      j++
    switch array[i+1] and array[end]
    partition(array, start, i)
    partition(array, i+2, end)
*/
void partition (int *array, int start, int end) {
  if (start < end) {
    int value = array[end];
    int i = start-1;	//the index of the last element whose value is smaller than array[end]
    int j = start;	//go through the array
    while (j < end) {
      if (array[j] < value) {
        //switch array[i+1] and array[end]
	int tmp = array[i+1];
	array[i+1] = array[j];
	array[j] = tmp;
	//i++
	i++;
      }
      j++;
    }
    array[end] = array[i+1];
    array[i+1] = value;
    partition (array, start, i);
    partition (array, i+2, end);
  }
}


/*
  divide and conquer: partition
  combine: do nothing
*/
void quickSort (int *array) {
  partition (array, 0, N-1);
}
