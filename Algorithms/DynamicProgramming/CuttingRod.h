#ifndef CUTTINGROD_H
#define CUTTINGROD_H

/*
  find the way to cut a rod with maximal revenue
  p[i] = the price for a rod of length i, for i=1 to n
  complexity: O(n^2)
*/

int cuttingRod_TopDown (const int *p, const int &n);

int cuttingRod_TopDown_Aux (const int *p, const int &n, int *c, int *m);

int cuttingRod_BottomUp (const int *p, const int &n);

#endif
