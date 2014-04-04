#include <iostream>
#include "LinkedList.h"
using namespace std;


int main () {
  //test LinkedList
  cout << "test LinkedList begin" << endl;
  LinkedList<int> l1;
  for (int i=0; i<5; i++)
    l1.insert(i);
  for (int i=5; i<10; i++) 
    l1.append (i);
  l1.remove (8);
  cout << "l1: " << endl;
  cout << l1 << endl;
  LinkedList<int> l2 (l1);
  l2.remove (4);
  l2.remove ();
  l2.search (6);
  cout << "l2" << endl;
  cout << l2 << endl;
  LinkedList<int> l3 (l1);
  l3 = l2;
  cout << "l3" << endl;
  cout << l3 << endl;
  cout << "test LinkedList end" << endl;

  return 0;
}
