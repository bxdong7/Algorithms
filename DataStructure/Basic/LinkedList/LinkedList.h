#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
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

template <class T>
std::ostream& operator<< (std::ostream &, const Node<T>&);

template <class T>
std::ostream &operator<< (std::ostream &, const LinkedList<T>&);

template <class T>
class Node {
friend class LinkedList<T>;
friend std::ostream& operator<< <T> (std::ostream &, const Node<T>&);
friend std::ostream& operator<< <T> (std::ostream &, const LinkedList<T>&);
private:
  Node ();
  Node (const T&);
  Node (const T&, T* const);
  Node (const Node<T>&);
  Node<T>& operator= (const Node<T>&);
  ~Node ();

  T value;
  T* next;
};


template <class T>
class LinkedList {
friend std::ostream& operator<< <T> (std::ostream &, const LinkedList<T>&);

public:
  LinkedList ();
  LinkedList (const size_t &);
  LinkedList (const LinkedList<T> &);
  LinkedList<T>& operator= (const LinkedList<T> &);
  void insert (const T&);
  void remove (const T&);
  const Node<T>& search (const T&) const;
  ~LinkedList *();
private:
  Node<T> *head;
};

#include "LinkedList.cpp"
#endif
