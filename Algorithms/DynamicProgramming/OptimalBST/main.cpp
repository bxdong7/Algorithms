#include <iostream>
#include "OptimalBST.h"
using namespace std;


int main () {
  cout << "test OptimalBST begin" << endl;
  double p[5];
  p[0] = 0.15;
  p[1] = 0.10;
  p[2] = 0.05;
  p[3] = 0.10;
  p[4] = 0.20;
  double q[6];
  q[0] = 0.05;
  q[1] = 0.10;
  q[2] = 0.05;
  q[3] = 0.05;
  q[4] = 0.05;
  q[5] = 0.10;

  optimalBST (p, q, 5);

  cout << "test OptimalBST end" << endl;
  return 0;
}
