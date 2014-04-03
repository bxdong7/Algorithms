#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include <iostream>
#include "LinkedList.h"
/*
  stack implemented with linked list
  Support pop and push operations
  Compelxity: pop:  O(n)
  	      push O(1)
*/
template <class T>
class Stack;


template <class T>
std::ostream &operator<< (std::ostream&, const Stack<T> &);

template <class T>
class Stack : protected LinkedList <T> {
friend std::ostream &operator<< <T> (std::ostream &, const Stack<T>&);
public:
 // using LinkedList <T>::search (const T&);
  Stack ();
  Stack (const size_t &);
  Stack (const Stack<T> &);
  Stack<T>& operator= (const Stack<T> &);
  void push (const T&);
  T pop () throw (std::underflow_error);
  bool empty () const;
  size_t size () const;
  void clear ();
  ~Stack();
private:
  Node<T> *tail;
};

#include "Stack.cpp"
#endif
