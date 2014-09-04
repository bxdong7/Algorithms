#include <iostream>
#include "AS.h"
using namespace std;

void ActivitySelector (const int *s, const int *f, const int &n) {
  //add the first activity which finishes the earliest first
  cout << 0 << endl;

  //search for the activity m which starts after activity k finishes
  int k = 0;
  for (int m=1; m<n; m++) {
    if (s[m] >= f[k]) {
      cout << m << endl;
      k = m;
    }  
  }
}
