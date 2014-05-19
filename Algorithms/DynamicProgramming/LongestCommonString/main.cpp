#include "LCS.h"
#include <iostream>
#include <string>
using namespace std;


int main () {
  cout << "test LCS begin" << endl;
  string X ("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA");
  string Y ("GTCGTTCGGAATGCCGTTGCTCTGTAAA");
  string c = LCS(X, Y);
  cout << "LCS(X, Y)= " << c << endl;
  cout << "test LCS end" << endl;
  return 0;
}
