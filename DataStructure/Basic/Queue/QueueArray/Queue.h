#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include <iostream>
#include <stdexcept>
#define CAPACITY 20

/*
  Queue implemented with array
  The capacity of the queue is predefined, can't be altered.
  We need to allocate CAPACITY+1 locations.
  head is the index of the first element, tail is the index of the next element to be pushed.
  Empty if head==tail.
  Full if (tail+1)%(capacity+1)==head
  Support enqueue and dequeue
  Complexity: enqueue O(1)
      dequeue  O(1)
*/

template <class T> class Queue;

template <class T>
std::ostream& operator<< (std::ostream&, const Queue<T>&);

template <class T>
class Queue {
friend std::ostream& operator<< <T> (std::ostream&, const Queue<T>&);
public:
  Queue ();
  Queue (const size_t &);
  Queue (const Queue<T>&);
  Queue<T>& operator= (const Queue<T>&);
  void enqueue (const T&) throw (std::overflow_error);
  T dequeue () throw (std::underflow_error);
  bool empty () const;
  size_t size () const;
//  size_t capacity () const;
  inline size_t next (const size_t &) const;	//return the next position
  inline size_t previous (const size_t &) const;	//return the previous position
  ~Queue ();
private:
  size_t head;	//first element
  size_t tail;	//the position after the last element
  size_t capacity;
  T *array;
};

template <class T>
inline size_t Queue<T>::next (const size_t &i) const {
  return (i+size_t(1))%(capacity+size_t(1));
}

template <class T>
inline size_t Queue<T>::previous (const size_t &i) const {
  return (i-size_t(1))%(capacity+size_t(1));
}

#include "Queue.cpp"
#endif
