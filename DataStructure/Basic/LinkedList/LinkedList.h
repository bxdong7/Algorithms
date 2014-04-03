#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <stdexcept>
#define DEFAULT 10

/*
  LinkedList
  Idea: This data structure only needs to keep the head of the list. It should support
      functions such as insert, delete, search.
  Complexity: insert O(1)
  	      delete O(n) because of search
	      search O(n)
*/


template <class T> class Node;
template <class T> class LinkedList;
template <class T> class Stack;

template <class T>
std::ostream& operator<< (std::ostream &, const Node<T>&);

template <class T>
std::ostream &operator<< (std::ostream &, const LinkedList<T>&);

template <class T>
class Node {
friend class LinkedList<T>;
friend class Stack<T>;
friend std::ostream& operator<< <T> (std::ostream &, const Node<T>&);
friend std::ostream& operator<< <T> (std::ostream &, const LinkedList<T>&);
protected:
  Node ();
  Node (const T&);
  Node (const T&, T* const);
  Node (const Node<T>&);
  Node<T>& operator= (const Node<T>&);
  ~Node ();

  T value;
  Node<T>* next;
};


template <class T>
class LinkedList {
friend std::ostream& operator<< <T> (std::ostream &, const LinkedList<T>&);

public:
  LinkedList ();
  LinkedList (const size_t &);
  LinkedList (const LinkedList<T> &);
  LinkedList<T>& operator= (const LinkedList<T> &);
  void insert (const T&);	//add at the head
  void append (const T&);	//add at the end
  void remove (const T&);
  void remove () throw (std::underflow_error);	//remove the head
  void remove (const Node<T> *) throw (std::invalid_argument);
  Node<T>* search (const T&) const;
  ~LinkedList ();
protected:
  void allocate ();
  Node<T> *head;
  Node<T> *first_free;
};

#include "LinkedList.cpp"
#endif
