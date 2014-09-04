#include <iostream>
#include "AS.h"
using namespace std;


int main () {
  //test activity selector
  cout << "test activity selector begins" << endl;
  int s[] = {1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
  int f[] = {4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};
  ActivitySelector (s, f, 11);

  cout << "test activity selector ends" << endl;
  return 0;
}
