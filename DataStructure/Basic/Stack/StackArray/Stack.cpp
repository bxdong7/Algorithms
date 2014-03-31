#include <memory>
#include <stdexcept>
#include <iostream>
#include "Stack.h"

template <class T>
std::allocator<T> Stack<T>::alloc;


/*
  may throw exception bad_alloc
*/
template <class T>
Stack<T>::Stack () {
  first_free = alloc.allocate(DEFAULT);
  first_element= NULL;
  last_free = first_free+(DEFAULT-1);
}


template <class T>
Stack<T>::Stack (size_t n) {
  first_free = alloc.allocate(n);
  first_element = NULL;
  last_free = first_free + (DEFAULT-1);
}


/*
  copy constructor
  clean the stack first and then push
*/
template <class T>
Stack<T>::Stack (const Stack<T>& s) {
  first_free = alloc.allocate(s.capacity());
  first_element= NULL;
  last_free = first_free+(s.capacity()-1);
  for (T* t=s.first_element; t!=s.first_free; t++)
    push (*t); 
}


template <class T>
Stack<T>& Stack<T>::operator= (const Stack<T>& s) {
  while (size() != static_cast<size_t>(0))
    pop();

  for (T* t=s.first_element; t!=s.first_free; t++)
    push (*t); 
  
  return *this;
} 

/*
  push
  Idea: if the stack is going to be full, increase the size to be the twice	as large as the current size. Copy the current elements to the new
     space. Free the old space.
*/
template <class T>
void Stack<T>::push (const T& t) {
  if (first_free == last_free) {
    //allocate a much larger memory space
    T* new_first_free = Stack<T>::alloc.allocate(capacity()*static_cast<unsigned long>(2));
    T* new_last_free = new_first_free + capacity()*static_cast<unsigned long>(2) - static_cast<unsigned long>(1);
    //copy
    T* new_first_element = new_first_free; 
    for (T* p=first_element; p!=first_free; p++) { 
      Stack<T>::alloc.construct(new_first_free, *p);
      new_first_free++;
      Stack<T>::alloc.destroy(p);
    }
    //deallocate old space
    Stack<T>::alloc.deallocate(first_element, capacity());
    //update first_free, last_free and first_element
    first_element = new_first_element;
    first_free = new_first_free;
    last_free = new_last_free;
  }
  //push the new element in
  Stack<T>::alloc.construct(first_free, t);
  if (first_element == NULL)
    first_element = first_free;
  first_free++;
}


/*
  pop
  Idea: if the size is not empty, destroy the last element, but do not 
    deallocate the memory space
*/
template <class T>
T Stack<T>::pop () {
  if (size() == static_cast<size_t>(0)) 
    throw std::underflow_error("pop an empty stack");
  
  T t(*(--first_free));
  Stack<T>::alloc.destroy(first_free);
  if (size() == size_t(0))
    first_element = NULL;
  return t;
}


template <class T>
size_t Stack<T>::size () const {
  if (first_element != NULL)
    return (first_free - first_element);

  else
    return size_t(0);
}


template <class T>
size_t Stack<T>::capacity () const {
  if (first_element != NULL)
    return (last_free - first_element + static_cast<size_t>(1));
  else
    return (last_free - first_free + static_cast<size_t>(1));
}


template <class T> 
Stack<T>::~Stack () {
  for (T* p=first_element; p!=first_free; p++) 
    Stack<T>::alloc.destroy(p);

  Stack<T>::alloc.deallocate(first_element, capacity());
}


template <class T>
std::ostream& operator<< (std::ostream &os, const Stack<T> &s) {
  for (T* p=s.first_element; p!=s.first_free; p++)
    os << *p << std::endl;
  return os;
}
