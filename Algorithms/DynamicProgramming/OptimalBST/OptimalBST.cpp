#include <iostream>
#include <cfloat>
#include "OptimalBST.h"
using namespace std;

/*
  Given n keywords and n+1 dummy keys, we can take any of the n keys as a root and get a expected cost e.
  e[i,j]=min_{r=i}^j{e[i,r-1]+e[r+1,j]+w[i,j]} if j!=i-1
  e[i,i-1]=q[i-1]
  w[i,j]=\sum_{k=i}^j p[k] + \sum_{k=i-1}^j q[k]  if j!=i-1
  w[i,i-1]=q[i-1]

  double e[n+1, n+1], double w[n+1, n+1]
  int w[n+1, n+1]
  for i=1 to n
    e[i][i-1] = q[i-1]
    w[i][i-1] = q[i-1]
  for l=0 to n-1
    for i=1 to n-l
      j=i+l
      w[i,j]=w[i,j-1]+p[i-1]+q[i]
      min = double_max
      for r=i to j
        if min>(e[i,r-1]+e[r+1,j]+w[i,j])
	  min = e[i,r-1]+e[r+1,j]+w[i,j]
      e[i,j]=min

*/
void optimalBST (const double *p, const double *q, const int &n) {
  //initialize e and w
  double **e = new double*[n+2] ();	//e[i,j] is the minimal expected cost of the BST from i to j
  double **w = new double*[n+2] ();	
  for (int i=0; i<=n+1; i++) {
    e[i] = new double[n+2] ();
    w[i] = new double[n+2] ();
  }
  for (int i=1; i<=n+1; i++) {
    e[i][i-1] = q[i-1];
    w[i][i-1] = q[i-1];
  }

  //using DP to update e and w
  for (int l=0; l<n; l++) {
    for (int i=1; i<=n-l; i++) {
      int j=i+l;
      w[i][j] = w[i][j-1] + p[j-1] + q[j];
      double min = DBL_MAX;
      for (int r=i; r<=i+l; r++) {
        if (min > (e[i][r-1]+e[r+1][j]+w[i][j]))
	  min = (e[i][r-1]+e[r+1][j]+w[i][j]);
      }
      e[i][j]=min;
    }
  }

  //output the min expected cost
  cout << "minimal expected cost: " << e[1][n] << endl;
}
