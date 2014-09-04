#ifndef AS_H
#define AS_H


/*
  find the set of activities such that the largest number of them can be scheduled
  s[i]: the starting time of activity i
  f[i]: the finish time of activity i
  complexity: O(n)
*/

void ActivitySelector (const int *s, const int *f, const int &n);

#endif
