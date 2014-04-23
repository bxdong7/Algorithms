#include <iostream>
#include <climits>
#include "MatrixChain.h"

/*
  m[i][i] = 0
  m[i][j] = min{m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]}
*/

int matrixChainMulti (const int *p, const int &n) {
  int **m = new int*[n]();
  int **s = new int*[n]();
  for (int i=0; i<n; i++) {
    m[i] = new int[n] ();
    s[i] = new int[n] ();
    for (int j=0; j<n; j++) {
      if (i != j)
        m[i][j] = INT_MAX;
      else 
        m[i][j] = 0;
    }
  }

  for (int l=1; l<n; l++) {
    for (int i=0; i<n-l; i++) {
      int j = i+l;
      for (int k=i; k<j; k++) {
        //std::cout << (m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1]) << std::endl;
        if (m[i][j] > (m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1])) {
	  m[i][j] = m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
	  s[i][j] = k;
	}
      }
    }
  }

//  for (int i=0; i<n; i++) {
//    for (int j=0; j<n; j++) {
//      std::cout << m[i][j] << " ";
//    }
//    std::cout << "\n";
//  }

  matrixChainMutliAux(const_cast<const int **>(s), 0, n-1);
  std::cout << "\n";
  
  int minCost = m[0][n-1];
  for (int i=0; i<n; i++) {
    delete[] m[i];
    delete[] s[i];
  }
  delete[] s;
  delete[] m;
  
  return minCost; 
}


void matrixChainMutliAux (const int **s, const int &i, const int &j) {
  if (i==j)
    std::cout << "A" << i;
  else {
    int k = s[i][j];
    std::cout << "(";
    matrixChainMutliAux(s, i, k);
    matrixChainMutliAux(s, k+1, j);
    std::cout << ")";
  }
}
