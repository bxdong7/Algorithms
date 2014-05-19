#include <string>
#include <iostream>
#include <cmath>
#include "LCS.h"
using namespace std;

/*
  LCS (X, Y) {
    m = X.size()+1;
    n = Y.size()+1;
    int c[m][n]
    for i=0 to n
      c[0][i] = 0;
    for i=0 to m
      c[i][0] = 0;
    for i=1 to m
      for j=1 to n
        if m[i]==n[j]
          c[i][j] = c[i-1][j-1]+1
        else
          c[i][j] = max{c[i-1][j], c[i][j-1]}
  }
*/
string LCS (const string &X, const string &Y) {
  int m = static_cast<int> (X.size()) + 1;
  int n = static_cast<int> (Y.size()) + 1;
  int **c = new int*[m];	//c[i][j] is the length of longest substring of X[i] and Y[j]
  for (int i=0; i<m; i++) 
    c[i] = new int[n];
  
  //initialize c
  //c[0][j] = 0, c[i][0] = 0
  for (int i=0; i<m; i++) 
    c[i][0] = 0;
  for (int j=0; j<n; j++)
    c[0][j] = 0;
  
  //fill in the blank of c
  for (int i=1; i<m; i++) {
    for (int j=1; j<n; j++) {
      if (X[i-1] == Y[j-1]) 
        c[i][j] = c[i-1][j-1] + 1;
      else 
        c[i][j] = static_cast<int> (fmax(c[i-1][j], c[i][j-1]));
    }
  }
  
  //get the LCS
  string s = LCSAux (const_cast<const int**>(c), X, Y);

  //free the memory
  for (int i=0; i<m; i++)
    delete[] c[i];
  delete[] c;

  return s;
}


string LCSAux (const int **c, const string &X, const string &Y) {
  string s;
  LCSStr (s, X.size(), Y.size(), c, X, Y);
  return s;
}


void LCSStr (string &s, int i, int j, const int **c, const string &X, const string &Y) {
  if ((i==0)||(j==0))
    return;
  else {
    if (c[i][j]==(c[i-1][j-1]+1)) {
      s.insert(0, 1, X[i-1]);
      LCSStr (s, i-1, j-1, c, X, Y);
    }
    else {
      if (c[i][j] == c[i-1][j])
        LCSStr (s, i-1, j, c, X, Y);
      else 
        LCSStr (s, i, j-1, c, X, Y);
    }
  }
}
