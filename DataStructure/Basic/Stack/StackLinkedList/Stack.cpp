#include <iostream>
#include <stdexcept>
#include "Stack.h"


template <class T>
Stack<T>::Stack () : tail(NULL){}

template <class T>
Stack<T>::Stack (const size_t &s) : LinkedList<T>(s), tail(NULL){
}

template <class T>
Stack<T>::Stack (const Stack<T> &s) : LinkedList<T>(s) {
  tail = this->head;
  while (tail->next!=NULL) 
    tail = tail->next;
}

template <class T>
Stack<T>& Stack<T>::operator= (const Stack<T> &s) {
  clear();
  Node<T> *n = s.head;
  while (n != NULL) {
    push (n->value); 
    n = n->next;
  }
  return *this;
}

template <class T>
void Stack<T>::push (const T& t) {
  if (this->first_free == NULL)
    this->allocate ();

  if (this->head == NULL) 
    this->head = this->first_free;
  else 
    tail->next = this->first_free;

  (this->first_free)->value = t;
  tail = this->first_free;
  this->first_free = this->first_free->next;
  tail->next = NULL;
  
}

template <class T>
T Stack<T>::pop () throw (std::underflow_error) {
  if (empty()) {
    throw std::underflow_error ("pop element from an empty stack");
  }
  Node<T> *p = this->head;
  T v;
  if (this->head == tail) {
    p = this->head;
    v = p->value;
    this->head = NULL;
    tail = NULL;
    p->next = this->first_free;
    this->first_free = p;
  }
  else {
    while (p->next != tail)
      p = p->next;
    v = tail->value;
    tail->next = this->first_free;
    this->first_free = tail;
    tail = p;
    tail->next = NULL;
  }
  return v;
}

template <class T>
bool Stack<T>::empty () const {
  return (this->head == NULL);
}

template <class T>
size_t Stack<T>::size () const {
  size_t s (0);
  Node<T> *p = this->head;
  while (p != NULL) {
    s++;
    p = p->next;
  }
  return s;
}

template <class T>
void Stack<T>::clear () {
  while (!empty())
    pop ();
}

template <class T>
Stack<T>::~Stack () {

}


template <class T>
std::ostream& operator<< (std::ostream &os, const Stack<T> &s) {
  os << static_cast<LinkedList<T> >(s); 
  return os;
}
