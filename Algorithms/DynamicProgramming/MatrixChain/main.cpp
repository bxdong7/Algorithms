#include <iostream>
#include "MatrixChain.h"
using namespace std;


int main () {
  cout << "test matrixChainMulti begin" << endl; 
  int p[7];
  p[0] = 30;
  p[1] = 35;
  p[2] = 15;
  p[3] = 5;
  p[4] = 10;
  p[5] = 20;
  p[6] = 25;
  matrixChainMulti (p, 6);
  cout << "test matrixChainMulti end" << endl; 
  return 0;
}
