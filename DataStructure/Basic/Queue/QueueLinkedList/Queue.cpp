#include <iostream>
#include <stdexcept>
#include <new>
#include "Queue.h"

template <class T>
Queue<T>::Queue () : LinkedList<T>() {

}

template <class T>
Queue<T>::Queue (const size_t &s) : LinkedList<T>(s) {

}

template <class T>
Queue<T>::Queue (const Queue<T> &q) {
  LinkedList<T>::head = NULL;
  LinkedList<T>::first_free = NULL;

  for (Node<T> *p=q.LinkedList<T>::head; p!=q.LinkedList<T>::first_free; p=p->next) 
    enqueue (p->value);
}

template <class T>
Queue<T>& Queue<T>::operator= (const Queue<T> &q) {
  while (!empty()) 
    dequeue ();

  for (Node<T> *p=q.LinkedList<T>::head; p!=q.LinkedList<T>::first_free; p=p->next) 
    enqueue (p->value);
}

template <class T>
void Queue<T>::enqueue (const T &v) throw (std::bad_alloc) {
  try{
    LinkedList<T>::append (v); 
  }
  catch (const std::bad_alloc &e) {
    std::cout << "bad_alloc in enqueue" << std::endl;
    throw;
  }
}

template <class T>
T Queue<T>::dequeue () throw (std::exception) {
  if (empty()) 
    throw std::underflow_error ("dequeue an empty queue");
  
  T v = this->head->value;
  LinkedList<T>::remove(this->head);
  return v;
}

template <class T>
size_t Queue<T>::size () const {
  if (empty())
    return size_t(0);
  else {
    size_t s(0);
    for (Node<T> *p=LinkedList<T>::head; p!=LinkedList<T>::first_free; p=p->next) 
      s++;
    return s;
  }
}

template <class T>
Queue<T>::~Queue () {

}


template <class T>
std::ostream& operator<< (std::ostream &os, const Queue<T> &q) {
  os << static_cast<LinkedList<T> >(q) << std::endl; 
  return os;
}
