#include <iostream>
#include "LinkedList.h"


template <class T>
Node<T>::Node () : value(T()), next(NULL) {}

template <class T>
Node<T>::Node (const T& t) : value(T), next(NULL) {}

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
Node<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

template <class T>
LinkedList<T>::

