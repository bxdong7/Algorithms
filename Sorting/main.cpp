#include <iostream>
#include "utility.h"
#include "sort.h"
using namespace std;

const size_t N = 6;

int main () {
  //will use this array to do all the tests
  int *array = new int[N]();

  //test insertion sort
  cout << "test insertion sort begin" << endl;
  generateRandomArray (array);
  cout << "before sort " << array << endl;
  insertionSort (array);
  cout << "after sort " << array << endl;
  cout << "test insertion sort end" << endl;
  cout << "-------------------------------" << endl << endl << endl;

  //test merge sort
  cout << "test merge sort begin" << endl;
  generateRandomArray (array);
  cout << "before sort " << array << endl;
  mergeSort (array);
  cout << "after sort " << array << endl;
  cout << "test merge sort end" << endl;
  cout << "-------------------------------" << endl << endl << endl;
  
  delete[] array;
  return 0;
}
