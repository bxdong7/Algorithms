#include <iostream>
#include <climits>
#include "CuttingRod.h"

/*
  find the best cutting way in a bottom up fashion
    int *c = new int[n+1]()	//use c[i] to store the best price we could get for a cod of length i
    int *m = new int[n+1]()	//use m[i] to store the best cutting point for a cod of length i
    c[0] = 0
    m[0] = 0
    m[1] = 0
    for i=1 to n
      c[i] = negative_infinity
    for i=2 to n
      max = p[i-1]
      maxIndex = 0
      for j=1 to i
        if max<p[j]+c[i-j]
	  max=p[j]+c[i-j]
	  maxIndex=j
      c[i] = max
      m[i] = maxIndex
    return c[n]
*/
int cuttingRod_BottomUp (const int *p, const int &n) {
  int *c = new int[n+1] ();	//use c[i] to store the best price we could get for a cod of length i
  int *m = new int[n+1] ();
  c[0] = 0;
  c[1] = p[0];
  m[0] = 0;
  m[1] = 0;

  for (int i=2; i<=n; i++)
    c[i] = INT_MIN;
  
  for (int i=2; i<=n; i++) {
    int max = p[i-1];
    int maxIndex = 0;
    //find the best split point and best price for a cod of length i
    for (int j=1; j<=i; j++) { 
      //for a cod of length i, the best price we can get if we split at j, with 1-j uncut, and do whatever to j-i
      if (max < (p[j-1]+c[i-j])) {
        max = (p[j-1]+c[i-j]);
	maxIndex = j;
      }
    }
    c[i] = max;
    m[i] = maxIndex;
  }
  
  //print out the best split point
  int point = m[n];
  while (point != 0) {
    std::cout << point << ", ";
    point = m[point];
  }
  std::cout << std::endl;

  return c[n];
}



int cuttingRod_TopDown (const int *p, const int &n) {
  int *c = new int[n+1] ();
  int *m = new int[n+1] ();
  c[0] = 0;
  m[0] = 0;
  for (int i=1; i<=n; i++)
    c[i] = INT_MIN;
  
  int best_price = cuttingRod_TopDown_Aux (p, n, c, m);
  int point = m[n];
  while (point != 0) {
    std::cout << point << ", ";
    point = m[point];
  }
  std::cout << std::endl;
  
  return best_price;
}


int cuttingRod_TopDown_Aux (const int *p, const int &i, int *c, int *m) {
  if (c[i] >= 0)
    return c[i];
  else {
    int max = p[i-1];
    int maxIndex = 0;
    for (int j=1; j<=i; j++) {
      if (max < (p[j-1]+cuttingRod_TopDown_Aux(p, i-j, c, m))) {
        max = p[j-1] + cuttingRod_TopDown_Aux(p, i-j, c, m);
	maxIndex = j;
      }
    }
    c[i] = max;
    m[i] = maxIndex;
    return c[i];
  }
}
