#ifndef UTILITY_H
#define UTILITY_H
#include <random>
#include <iostream>


/*
  generate random array of length N
*/
template <class T, size_t N>
void generateRandomArray (T (&array)[N]); 


/*
  output an array, without a return character
*/
template <class T, size_t N>
std::ostream& operator<< (std::ostream &os, T (&array)[N]); 




#include "utility.cpp"
#endif
