#include "sort.h"


/*
  countingSort (A, n, k) {
    B[k+1];
    for i=0 to k
      B[i]=0
    for i=0 to n-1
      B[A[i]]++
    //Now B[i] is the frequency of i in A

    for i=1 to k
      B[i]+=B[i-1]	//B[i] counts the number of elements in A whose value is smaller than or equal to i

    C[n]
    for i=0 to n-1
      C[B[A[i]]-1] = A[i]
      B[A[i]]--
  }
*/

template <class T, size_t N>
void countingSort (T (&array)[N], const long &k) {
  T* B = new T[k+1]();
  for(long i=0; i<=k; i++)
    B[i] = 0;
  for(long i=0; i<static_cast<long>(N); i++)
    B[array[i]]++;
  for(long i=1; i<=k; i++) 
    B[i] += B[i-1];
  
  T C[N];
  for(long i=0; i<static_cast<long>(N); i++)
    C[i] = array[i];
  for(long i=0; i<static_cast<long>(N); i++) 
    array[--B[C[i]]] = C[i];
  delete[] B;
}
