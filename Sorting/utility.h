#ifndef UTILITY_H
#define UTILITY_H
#include <random>
#include <iostream>

extern const size_t N;

/*
  generate random array of length N
*/
void generateRandomArray (int *array); 


/*
  output an array, without a return character
*/
std::ostream& operator<< (std::ostream &os, int *array); 





#endif
