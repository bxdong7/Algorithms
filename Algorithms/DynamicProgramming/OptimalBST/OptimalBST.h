#ifndef __OPTIMALBST_H__
#define __OPTIMALBST_H__

/*
  Given n keywords K, such that K_i<K_(i+1), with the searching frequency p. Also given n+1 non-existing "dummy" keys with the searching frequency q. Construct a binary search tree whose expected search cost is smallest.
  complexity: O(n^3)
*/
void optimalBST (const double *p, const double *q, const int &n);


#endif

