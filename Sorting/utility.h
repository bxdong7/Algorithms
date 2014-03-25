#ifndef UTILITY_H
#define UTILITY_H
#include <random>
#include <iostream>

extern const size_t N;

/*
  generate random array of length N
*/
template <size_t N>
void generateRandomArray (int (&array)[N]); 


/*
  output an array, without a return character
*/
template <size_t N>
std::ostream& operator<< (std::ostream &os, int (&array)[N]); 





#endif
