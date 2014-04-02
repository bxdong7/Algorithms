#include <iostream>
#include <stdexcept>
#include "LinkedList.h"


template <class T>
Node<T>::Node () : value(T()), next(NULL) {}

template <class T>
Node<T>::Node (const T& t) : value(t), next(NULL) {}

template <class T>
Node<T>::Node (const T& t, T* const n) : value(t), next(n) {} 

template <class T>
Node<T>::Node (const Node<T>& n) : value(n.value), next(n.next) {}

template <class T>
Node<T>& Node<T>::operator= (const Node<T>& n) {
  value = n.value;
  next = n.next;
}

template <class T>
Node<T>::~Node () {
  if (next != NULL)
    delete next;
}

template <class T>
std::ostream &operator<< (std::ostream &os, const Node<T> &n) {
  os << n.value;
  return os;
}


template <class T>
LinkedList<T>::LinkedList () {
  head = NULL;
  Node<T> *current;
  first_free = new Node<T>();
  current = first_free;
  for (size_t i=1; i<static_cast<size_t>(DEFAULT); i++) {
    current->next = new Node<T> ();
    current = current->next;
  }
}

template <class T>
LinkedList<T>::LinkedList (const size_t &size) {
  head = NULL;
  Node<T> *current;
  first_free = new Node<T>();
  current = first_free;
  for (size_t i=1; i<size; i++) {
    current->next = new Node<T> ();
    current = current->next;
  }
}

template <class T>
LinkedList<T>::LinkedList (const LinkedList<T> &l) {
  head = NULL;
  Node<T> *current;
  first_free = new Node<T>();
  current = first_free;
  for (size_t i=1; i<static_cast<size_t>(DEFAULT); i++) {
    current->next = new Node<T> ();
    current = current->next;
  }
  for (const Node<T> *p=l.head; p!=NULL; p=p->next) {
    insert(p->value);
  }
}

template <class T>
LinkedList<T> &LinkedList<T>::operator= (const LinkedList<T> &l) {
  while(head != NULL) 
    remove ();
  for (const Node<T> *p=l.head; p!=NULL; p=p->next) 
    insert(p->value);
  return *this; 
}

template <class T>
void LinkedList<T>::insert (const T &v) {
  if (first_free == NULL) 
    allocate ();  
  
  Node<T> *p = first_free;
  p->value = v;
  p->next = NULL;
  first_free = first_free->next;
  
  //find tail
  Node<T> *tail = NULL;
  if (head == NULL)
    head = p;
  else {
    tail = head;
    while (tail->next != NULL)
      tail = tail->next;
    tail->next = p;
  }
}

template <class T>
void LinkedList<T>::append (const T &v) {
  if (first_free == NULL)
    allocate ();

  Node<T> *p = first_free;
  Node<T> *q = first_free->next;
  p->value = v;
  p->next = head;
  head = p;
  first_free = q;
}

template <class T>
void LinkedList<T>::remove (const T &v) {
  Node<T> *p1, *p2;
  p1 = NULL;
  p2 = NULL;	//p1 = p2 + 1
  //if head->value == v
  if((head!=NULL) && (head->value==v)) {
    //add head to first_free
    Node<T> *p = first_free;
    Node<T> *q = head->next;
    first_free = head;
    first_free->next = p;
    //remove head from this
    head = q;
  }
  else {
    p2 = head;
    p1 = head->next;
    while (p1 != NULL) {
      if (p1->value == v) {
        //remove p1 from this
        p2->next = p1->next;
	//add p1 to first_free
	p1->next = first_free;
	first_free = p1;
	break;
      }
      p1 = p1->next;
      p2 = p2->next;
    } 
  }
}

template <class T>
void LinkedList<T>::remove () throw (std::underflow_error){
  if (head == NULL)
    throw std::underflow_error("remove head from an empty linked list");
  else 
    remove (head->value); 
}

template <class T>
void LinkedList<T>::remove (const Node<T> *n) throw (std::invalid_argument){
  if (n == NULL)
    throw std::invalid_argument("remove a NULL pointer");
  
  Node<T> *p1, p2;
  p1 = NULL;
  p2 = NULL;	//p1 = p2 + 1
  //if head->value == v
  if((head!=NULL) && (head==n)) {
    //add head to first_free
    Node<T> *p = first_free;
    Node<T> *q = head->next;
    first_free = head;
    first_free->next = p;
    //remove head from this
    head = q;
  }
  else {
    p2 = head;
    p1 = head->next;
    while (p1 != NULL) {
      if (p1 == n) {
        //remove p1 from this
        p2->next = p1->next;
	//add p1 to first_free
	p1->next = first_free;
	first_free = p1;
	break;
      }
      p1 = p1->next;
      p2 = p2->next;
    } 
  }
}

template <class T>
Node<T>* LinkedList<T>::search (const T &v) const {
  if (head == NULL)
    return NULL;

  for (Node<T> *p=head; p!=NULL; p=p->next) {
    if (p->value == v)
      return p;
  }

  return NULL;
}

template <class T>
LinkedList<T>::~LinkedList () {
  if (head != NULL)
    delete head;
  if (first_free != NULL)
    delete first_free;
}

template <class T>
void LinkedList<T>::allocate () {
  first_free = new Node<T> ();
  for (size_t i=1; i<static_cast<size_t>(DEFAULT); i++) {
    Node<T> *p = new Node<T> ();
    p->next = first_free;
    first_free = p;
  }
}

template <class T>
std::ostream &operator<< (std::ostream &os, const LinkedList<T> &l) {
  for (Node<T> *p=l.head; p!=NULL; p=p->next)
    os << *p << std::endl;
  return os;
}
