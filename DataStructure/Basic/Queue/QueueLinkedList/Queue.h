#ifndef QUEUE_H 
#define QUEUE_H
#include <iostream>
#include <stdexcept>
#include <new>
#include "LinkedList.h"

/*
  Queue implemented with LinkedList
  LinkedList<T>::first_free functions like tail, pointer to the position after the last element
  Support enqueue, dequeue
  Complexity: enqueue O(1) 
  	      dequeue O(1)
*/

template <class T> class Queue;

template <class T>
std::ostream& operator<< (std::ostream &, const Queue<T> &);


template <class T>
class Queue : private LinkedList<T> {
friend std::ostream& operator<< <T> (std::ostream &, const Queue<T> &);
public:
  Queue ();
  Queue (const size_t &);
  Queue (const Queue<T> &);
  Queue<T>& operator= (const Queue<T> &);
  void enqueue (const T&) throw (std::bad_alloc);
  T dequeue () throw (std::exception);
  inline bool empty () const;
  size_t size () const;
  ~Queue ();
};

template <class T>
inline bool Queue<T>::empty () const {
  return (LinkedList<T>::head==NULL)||(LinkedList<T>::head==LinkedList<T>::first_free);
}

#include "Queue.cpp"
#endif
