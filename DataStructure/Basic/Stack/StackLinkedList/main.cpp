#include <iostream>
#include "Stack.h"
using namespace std;


int main () {
  //test Stack 
  cout << "test Stack begin" << endl;
  Stack<int> s1; 
  for (int i=0; i<5; i++)
    s1.push (i);
  for (int i=9; i>4; i--)
    s1.push (i);
  cout << "s1: " << endl;
  cout << s1 << endl;

  Stack<int> s2 (s1);
  cout << "s2: " << endl;
  cout << s2 << endl;
  s2.pop ();
  cout << "s2: " << endl;
  cout << s2 << endl;
  s2.pop ();
  cout << "s2: " << endl;
  cout << s2 << endl;

  cout << "test Stack end" << endl;

  return 0;
};
