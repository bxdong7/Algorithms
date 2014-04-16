#include <iostream>
#include "CuttingRod.h"
using namespace std;


int main () {
  //test cuttingRod
  cout << "test cuttingRod begin" << endl;
  int p[10] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  cout << cuttingRod_BottomUp(p, 10) << endl;
  cout << cuttingRod_TopDown(p, 10) << endl;
  cout << "test cuttingRod end" << endl;

  return 0;
}
