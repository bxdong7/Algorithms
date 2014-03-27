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
  
//  delete[] array;
  return 0;
}
