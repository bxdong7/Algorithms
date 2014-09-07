#include <memory>
#include <iostream>
#include <stdexcept>

#include "PriorityQueue.h"

using namespace std;

template <class T>
allocator<T> PriorityQueue<T>::alloc;

template <class T>
PriorityQueue<T>::PriorityQueue () {
  //only allocate space
  first_free = PriorityQueue<T>::alloc.allocate(DEFAULT);
  end = first_free + DEFAULT;
  first_element = NULL;
}

template <class T> template <size_t N>
PriorityQueue<T>::PriorityQueue(T (&param)[N]) {
  //allocate space first
  first_free = PriorityQueue<T>::alloc.allocate(DEFAULT);
  end = first_free + DEFAULT;
  first_element = NULL;
  
  //push all the elements in
  for (size_t i=0; i<N; i++) 
    this->insert(param[i]);
}

template <class T>
void PriorityQueue<T>::insert (const T &v) {
  size_t size;
  const T *p;
  T *new_first_element, *new_first_free, *new_end;

  //if first_free == end, allocate more space, and copy existing elements to the new position
  if (first_free == end) {
    //check the size of current queue
    size = this->size();
    //allocate a space whose size is twice
    new_first_free = PriorityQueue<T>::alloc.allocate(2*size);
    new_first_element = new_first_free;
    new_end = new_first_free + 2*size;
    //copy existing element
    for (p=first_element; p<first_free; p++) {
      PriorityQueue<T>::alloc.construct (new_first_free, *p);
      new_first_free++; 
    }
    //update first_element, first_free and end
    first_element = new_first_element;
    first_free = new_first_free;
    end = new_end;
  }

  //construct the new element, update first_free
  PriorityQueue<T>::alloc.construct(first_free, v);
  first_free++;

  //if first_element==NULL, assign value to first_element
  if (first_element == NULL)
    first_element = first_free-1;
  else 
    this->increasePriority(first_free-1, v);
}

template <class T>
const T &PriorityQueue<T>::maximal () const {
  if (first_element != NULL) 
    return *first_element;
  else
    throw runtime_error("no element in the queue");
}

template <class T>
T PriorityQueue<T>::fetch () {
  T t;
  T *head;

  if (first_element == NULL)
    throw runtime_error("no element in the queue");

  t = *first_element;
  head = first_element;

  if (first_free == first_element+1)
    first_element = NULL;
  else {
    first_element++;
    maxHeapify (0);
  }

  PriorityQueue<T>::alloc.destroy(head);
  //PriorityQueue<T>::alloc.deallocate(head, 1);

  return t;
}

template <class T>
void PriorityQueue<T>::increasePriority (T *t, const T &v) {
  T *p;
  T tmp;

  if (*t <= v) {
    *t = v;
    
    p = PARENT(getIndex(t));
    
    while ((p!=NULL) && (*p<*t)) {
      tmp = *t;
      *t = *p;
      *p = tmp;

      t = p;
      p = PARENT(getIndex(t));
    }
  }
}

template <class T>
size_t PriorityQueue<T>::size () const {
  if (first_element == NULL)
    return 0;
  else 
    return first_free-first_element;
}

template <class T>
PriorityQueue<T>::~PriorityQueue () {
  T *p;

  if (first_element != NULL) {
    p = first_element;
    while (p < first_free) {
      PriorityQueue<T>::alloc.destroy(p);
      p++;
    }
    //PriorityQueue<T>::alloc.deallocate(first_element, end-first_element);
    //PriorityQueue<T>::alloc.deallocate(first_element, 10);
  }
  else {
    PriorityQueue<T>::alloc.deallocate(first_free, end-first_free);
  }
}

template <class T>
void PriorityQueue<T>::maxHeapify (const int &index) {
  T *left, *right, *t, *max;
  
  t = getP (index);

  if (t != NULL) {
    left = LEFT(index);
    right = RIGHT(index);
    
    max = t;
    if ((left!=NULL) && (*left>*max))
      max = left;
    if ((right!=NULL) && (*right>*max))
      max = right;

    if (max != t) {
      T v = *max;
      *max = *t;
      *t = v;

      int i = getIndex(max);
      maxHeapify (i);
    }
  }
}

template <class T>
int PriorityQueue<T>::getIndex (const T *p) const {
  const T *t;
  int index;
  if (first_element == NULL)
    throw runtime_error("no element in the queue");

  t = first_element;
  index = 0;
  while ((t!=first_free) && (t!=p)) {
    t++;
    index++;
  }

  if (t==p) 
    return index;
  else
    return -1;

}

template <class T>
T *PriorityQueue<T>::getP (const int &index) const {
  int i;
  T *p;

  if (first_element == NULL)
    throw runtime_error("no element in the queue");
  
  p = first_element;
  i = 0;

  while ((p!=first_free) && (i<index)) {
    i++;
    p++;
  }

  if (p != first_free)
    return p;
  else
    throw range_error("index out of range");
}

template <class T>
T *PriorityQueue<T>::LEFT (const int &index) const {
  size_t i;
  size_t size;

  size = this->size();
  i = 2*static_cast<size_t>(index) + 1;
  
  if (i<size)
    return first_element+i;
  else
    return NULL;
}

template <class T> 
T *PriorityQueue<T>::RIGHT (const int &index) const {
  size_t i;
  size_t size;

  size = this->size();
  i = 2*static_cast<size_t>(index) + 2;
  
  if (i<size)
    return first_element+i;
  else
    return NULL;
}

template <class T>
T *PriorityQueue<T>::PARENT (const int &index) const {
  size_t i;

  i = static_cast<size_t>(index-1) / 2;
  
  if (index > 0)
    return first_element+i;
  else
    return NULL;
}

