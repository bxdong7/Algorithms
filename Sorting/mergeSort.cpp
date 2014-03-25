#include "mergeSort.h"

template <size_t N>
void divide (int (&array)[N], int start, int end);

template <size_t N>
void conquer (int (&array)[N], int start, int mid, int end);
