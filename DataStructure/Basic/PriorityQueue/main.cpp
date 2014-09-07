#include <iostream>
#include "PriorityQueue.h"
using namespace std;


int main () {
  cout << "test PriorityQueue begin" << endl;
  PriorityQueue<int> q1;
  for (int i=5; i>0; i--)
    q1.insert(i);
  cout << q1.fetch() << endl;
  cout << q1.fetch() << endl;

  int p[] = {4, 7, 1, 5};
  PriorityQueue<int> q2(p);
  cout << q2.maximal() << endl;
  cout << "test PriorityQueue end" << endl;
  return 0;
}
