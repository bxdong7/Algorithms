#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <memory>
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
  PriorityQueue ();
  template <size_t N> PriorityQueue (T (&)[N]);	//template copy constructor to copy array of any size
  void add (const T&);
  T fetch ();	//get the task with largest pritory and delete it from the queue
  cosnt T& maximal () const;	//get the largest priority
  void increasePriority (long, const T&);	//increase the i-th element's priority by a number
  const size_t &size () const;	//return the size of the queue
  ~PriorityQueue ();
private:
  static std::allocator<T> alloc;	//the memory allocator for this class
  T* first_element;
  T* first_free;
  T* end;
};


#endif 
