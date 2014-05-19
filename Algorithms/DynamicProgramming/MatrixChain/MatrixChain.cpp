#include <iostream>
#include <climits>
#include "MatrixChain.h"

/*
  use m[i][j] to store the number of minimal multiplications to compute the matrix multiplication from M(i+1) to M(j+1)
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

  matrixChainMultiAux(const_cast<const int **>(s), 0, n-1);
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


void matrixChainMultiAux (const int **s, const int &i, const int &j) {
  if (i==j)
    std::cout << "A" << i;
  else {
    int k = s[i][j];
    std::cout << "(";
    matrixChainMultiAux(s, i, k);
    matrixChainMultiAux(s, k+1, j);
    std::cout << ")";
  }
}


int matrixChainTopDown (const int *p, const int &n) {
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
  
  int v = matrixChainLookup (m, s, p, 0, n-1);
  matrixChainMultiAux (const_cast<const int **>(s), 0, n-1);
  std::cout << std::endl;
  return v;
}

int matrixChainLookup (int **m, int **s, const int *p, const int &i, const int &j) {
  if (m[i][j]!=INT_MAX)
    return m[i][j];
  else {
    if (i==j) {
      m[i][j] = 0;
      s[i][j] = i;
    }
    else {
      for (int k=i; k<j; k++) {
        int q = matrixChainLookup(m, s, p, i, k) + matrixChainLookup(m, s, p, k+1, j) + p[i]*p[k+1]*p[j+1];
	if (m[i][j] > q) {
	  m[i][j] = q;
	  s[i][j] = k;
	}
      }
    }

    return m[i][j];
  }
}
