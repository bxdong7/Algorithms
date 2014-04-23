#ifndef MATRIXCHAIN_H
#define MATRIXCHAIN_H

/*
  find the best parenthesization of a chain a matrices to minimize number of scalar multiplications
  Example: M1 is 10*100, M2 is 100*5, M3 is 5*50. If (M1*M2)*M3, complexity is 7500; if M1*(M2*M3), complexity is 75000
  Input: p[n+1], n is number of matrices, M[i] is of size p[i-1]*p[i]
  Output: parenthesization
  Return: minimal number of scalar multiplications
  complexity: O(n^3)
*/
int matrixChainMulti (const int *p, const int &n);

//help output the parenthesization
void matrixChainMutliAux (const int **s, const int &i, const int &j);

#endif
