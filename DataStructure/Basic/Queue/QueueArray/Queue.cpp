#include <iostream>
#include <stdexcept>
#include "Queue.h"


template <class T>
Queue<T>::Queue () {
  capacity = size_t(CAPACITY);
  array = new T[capacity+1]();
  head = size_t(0);
  tail = size_t(0);
}

template <class T>
Queue<T>::Queue (const size_t &s) {
  capacity = size_t(s);
  array = new T[capacity+1]();
  head = size_t(0);
  tail = size_t(0);
}

template <class T>
Queue<T>::Queue (const Queue<T> &q) {
  capacity = q.capacity;
  array = new T[capacity+1+1]();
  head = size_t(0);
  tail = size_t(0);
  for (size_t i=q.head; i!=q.tail; i=next(i))
    enqueue (q.array[i]);
}
template <class T>
Queue<T>& Queue<T>:: operator= (const Queue<T> &q) {
  while (!empty())
    dequeue ();
  delete[] array;
  
  capacity = q.capacity;
  array = new T[capacity+1+1]();
  head = size_t(0);
  tail = size_t(0);
  for (size_t i=q.head; i!=q.tail; i=next(i))
    enqueue (q.array[i]);
}

template <class T>
void Queue<T>::enqueue (const T &v) throw (std::overflow_error){
  if (size() != capacity) {
    array[tail] = v;
    tail = next(tail); 
  }
  else
    throw std::overflow_error("enqueue to a full queue");
}

template <class T>
T Queue<T>::dequeue () throw (std::underflow_error) {
  if (empty())
    throw std::underflow_error("dequeue an empty queue");

  T v = array[head];
  head = next(head);
  return v;
}

template <class T>
bool Queue<T>::empty () const {
  return head==tail;
}

template <class T>
size_t Queue<T>::size () const {
  return (tail+capacity+1-head)%(capacity+1);
}

template <class T>
Queue<T>::~Queue () {
  delete[] array;
}


template <class T>
std::ostream& operator<< (std::ostream &os, const Queue<T> &q) {
  if (q.empty())
    os << "empty queue" << std::endl;
  for (size_t p=q.head; p!=q.tail ; p=q.next(p)) 
    os << q.array[p] << std::endl;
  return os;
}
