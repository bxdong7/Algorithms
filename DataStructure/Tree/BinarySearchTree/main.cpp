#include <iostream>
#include "BinarySearchTree.h"
using namespace std;


int main () {
  cout << "test BinarySearchTree begin" << endl;
  BST<int> t;
  for (int i=5; i<10; i++) 
    t.insert(i);
  for (int i=5; i>0; i--)
    t.insert(i);
  cout << "inOrder: "; 
  t.inOrder (); 
  cout << endl;
  cout << "successor(7): " << t.successor(7) << endl;
  cout << "remove (7): ";
  t.remove (7);
  t.inOrder ();
  cout << endl;
  t.insert (15);
  t.insert (12);
  t.insert (13);
  t.insert (11);
  t.inOrder ();
  cout << endl;
  t.remove (9);
  t.inOrder ();
  cout << endl;
  cout << "test BinarySearchTree end" << endl;

  return 0;
}
