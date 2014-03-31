#include <iostream>
#include <stdexcept>
#include <new>
#include "Stack.h"
using namespace std;


int main () {
  //test Stack<T>
  try{
    cout << "test Stack<T> begins" << endl;
    Stack<int> s1;
    for (int i=0; i<5; i++)
      s1.push(i);
    cout << "s1.size(): " << s1.size() << endl;
    cout << "s1.capacity(): " << s1.capacity() << endl;
    cout << "s1: " << endl;
    cout << s1 << endl;
    Stack<int> s2(s1);
    for (int i=5; i< 15; i++)
      s2.push(i);
    cout << "s2: " << endl;
    cout << s2 << endl;
    cout << "s2.size(): " << s2.size() << endl;
    cout << "s2.capacity(): " << s2.capacity() << endl;
    s2.pop ();
    s2.pop ();
    cout << "s2.size(): " << s2.size() << endl;
    cout << "s2.capacity(): " << s2.capacity() << endl;
    cout << "test Stack<T> ends" << endl;
  }
  catch(const bad_alloc &b) {
    cerr << "bad_alloc caught: " << b.what() << endl; 
  }
  catch(const exception &e) { 
    cerr << "exception caught: " << e.what() << endl; 
  }

  return 0;
}
