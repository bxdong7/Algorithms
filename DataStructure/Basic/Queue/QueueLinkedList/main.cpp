#include <iostream>
#include "Queue.h"
using namespace std;


int main () {
  //test Queue
  cout << "test Queue begin" << endl;
  Queue<int> q1;
  for (int i=0; i<10; i++)
    q1.enqueue(i);
  cout << "q1: " << endl;
  cout << q1 << endl;
  Queue<int> q2 = q1;
  q2.dequeue();
  q2.dequeue();
  cout << "q2: " << endl;
  cout << q2 << endl;
  for (int i=10; i<30; i++)
    q2.enqueue(i);
  cout << "test Queue end" << endl;
  return 0;
}
