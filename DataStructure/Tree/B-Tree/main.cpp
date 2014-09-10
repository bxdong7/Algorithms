#include <iostream>
#include "BTree.h"
using namespace std;


int main () {
  cout << "begin test b-tree" << endl;
  BTree tree (2);
  for (int i=1; i<6; i++) {
    tree.insert (i);
  }

  cout << tree << endl;
  cout << "test b-tree end" << endl;
  return 0;
}
