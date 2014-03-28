#include <cmath>
#include "sort.h"

template <class T, size_t N>
void countingSort (T (&array)[N], const int &i, const int &k);



/*
  radixSort (A, d, n)
    for i=0 to d-1
      countingSort (A, i, n)
*/
template <class T, size_t N>
void radixSort (T (&array)[N], const int &d, const int &k) {
  for (int i=0; i<d; i++) 
    countingSort (array, i, k);
}


/*
  counting sort based on the i-th digit in each element of A
*/
template <class T, size_t N>
void countingSort (T (&array)[N], const int &index, const int &k) {
  T* B = new T[k+1]();
  for (int i=0; i<=k; i++) 
    B[i] = 0;
  for (long i=0; i<static_cast<long>(N); i++) {
    int digit = static_cast<int>(array[i] / pow(10, index)) % 10;
    B[digit]++;
  }
  for (long i=1; i<static_cast<long>(k); i++)
    B[i] += B[i-1];

  T C[N];
  for (long i=0; i<static_cast<long>(N); i++)
    C[i] = array[i];
  for (long i=static_cast<long>(N-1); i>=0; i--) {
    int digit = static_cast<int>(C[i] / pow(10, index)) % 10;
    array[--B[digit]] = C[i];
  }
}
