#include <iostream>
#include <string>
#include "utility.h"
#include "sort.h"
using namespace std;


int main () {
  //will use this array to do all the tests
  int array[6]; 

  //test insertion sort
  cout <<string("test insertion sort begin") << endl;
  generateRandomArray (array);
  cout <<string("before sort ") << array << endl;
  insertionSort (array);
  cout <<string("after sort ") << array << endl;
  cout <<string("test insertion sort end") << endl;
  cout <<string("-------------------------------") << endl << endl << endl;

  //test merge sort
  cout <<string("test merge sort begin") << endl;
  generateRandomArray (array);
  cout <<string("before sort ") << array << endl;
  mergeSort (array);
  cout <<string("after sort ") << array << endl;
  cout <<string("test merge sort end") << endl;
  cout <<string("-------------------------------") << endl << endl << endl;
  
  //test heap sort
  cout <<string("test heap sort begin") << endl;
  generateRandomArray (array);
  cout <<string("before sort ") << array << endl;
  heapSort (array);
  cout <<string("after sort ") << array << endl;
  cout <<string("test heap sort end") << endl;
  cout <<string("-------------------------------") << endl << endl << endl;
  
  //test quick sort
  cout <<string("test quick sort begin") << endl;
  generateRandomArray (array);
  cout <<string("before sort ") << array << endl;
  quickSort (array);
  cout <<string("after sort ") << array << endl;
  cout <<string("test quick sort end") << endl;
  cout <<string("-------------------------------") << endl << endl << endl;
  
  //test counting sort
  cout <<string("test counting sort begin") << endl;
  generateRandomArray (array);
  cout <<string("before sort ") << array << endl;
  countingSort (array, 100);
  cout <<string("after sort ") << array << endl;
  cout <<string("test counting sort end") << endl;
  cout <<string("-------------------------------") << endl << endl << endl;
  
  //test radix sort
  cout <<string("test radix sort begin") << endl;
  generateRandomArray (array);
  cout <<string("before sort ") << array << endl;
  radixSort (array, 2, 10);
  cout <<string("after sort ") << array << endl;
  cout <<string("test radix sort end") << endl;
  cout <<string("-------------------------------") << endl << endl << endl;
  
  return 0;
}
