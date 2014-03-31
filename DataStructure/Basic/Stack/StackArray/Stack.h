#ifndef STACK_H
#define STACK_H
#include <memory>
#include <iostream>
#define DEFAULT 10	//the default number of allocations

template <class T>
class Stack;

template <class T>
std::ostream& operator<< (std::ostream&, const Stack<T>&);


/*
  Stack implemented by array
  Idea: allocate consecutive memory, keep track of the last element and
       the first free element. When never we pop an element, destroy the
       element, but do not free the memory. Instead, keep the memory for
       future use.
  Complexity: pop: O(1)
  	      push O(1) but may require memory allocation
*/
template <class T>
class Stack {
//declare operator<< <T> as friend function
friend std::ostream& operator<< <T> (std::ostream&, const Stack<T>&);
public:
  Stack ();
  Stack (size_t n);
  Stack (const Stack<T>&);
  Stack<T>& operator= (const Stack<T>&);
  void push (const T&);	//two operations of stack
  T pop ();	
  size_t size () const;
  size_t capacity() const;
  ~Stack ();

private:
  static std::allocator<T> alloc;	//the allocator of this class
  T* first_free;	
  T* last_free;
  T* first_element;
};

template <class T>
std::ostream& operator<< (std::ostream&, const Stack<T>&);

#include "Stack.cpp"
#endif
