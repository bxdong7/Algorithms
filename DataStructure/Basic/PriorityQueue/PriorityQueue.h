#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <memory>
#include <stdexcept>
#define DEFAULT 10

/*
  PriorityQueue
  idea: implement the priorityqueue with max-heap-like array
  	the element in the array is the weight/priority of the task
  complexity: 
  	add a task/element: O(logn) 
	fetch the largest pritority: O(1)
	build the priority queue: O(nlogn)
	raise the priority of an element: O(logn)
*/
template <class T> 
class PriorityQueue {
public:
  PriorityQueue ();
  template <size_t N> PriorityQueue (T (&)[N]);	//template copy constructor to copy array of any size
  void insert (const T&);
  T fetch ();	//get the task with largest pritory and delete it from the queue
  const T& maximal () const;	//get the largest priority
  void increasePriority (T *, const T&);	//increase the i-th element's priority by a number
  size_t size () const;	//return the size of the queue
  ~PriorityQueue ();
private:
  void maxHeapify (const int &index);	//maxheapify the element at index, index starts from 0 to size-1
  int getIndex (const T*) const;	//get the index of pointer, starting from first_element
  T* getP (const int&) const;	//get the pointer of the index 
  T* LEFT (const int &) const;	
  T* RIGHT (const int &) const;
  T* PARENT (const int &) const;
  static std::allocator<T> alloc;	//the memory allocator for this class
  T* first_element;
  T* first_free;
  T* end;	//symbolize the end of the pointers, last_free = end-1
};

#include "PriorityQueue.cpp"
#endif 
