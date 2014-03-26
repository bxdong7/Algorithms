#include <iostream>
#include <random>
#include "utility.h"


std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1, 100);
void generateRandomArray (int *array) {

  for (size_t i=0; i<N; i++) {
    int number = distribution(generator);
    array[i] = number;
  }
}


std::ostream& operator<< (std::ostream &os, int *array) {
  os << "array: ";
  for (size_t i=0; i<N; i++)
    os << array[i] << ", ";
  return os;
}
