#include <iostream>
#include <string>
#include <random>
#include "utility.h"


std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(10, 99);

template <class T, size_t N>
void generateRandomArray (T (&array)[N]) {

  for (size_t i=0; i<N; i++) {
    T number = distribution(generator);
    array[i] = number;
  }
}


template <class T, size_t N>
std::ostream& operator<< (std::ostream &os, T (&array)[N]) {
  os << std::string("array: ");
  for (size_t i=0; i<N; i++)
    os << array[i] << std::string(", ");
  return os;
}
