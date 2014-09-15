#ifndef __GRAPH_H__
#define __GRAPH_H__
#include <iostream>
#include <random>

#define White 0
#define Gray 1
#define Black 2
#define NIL -1

class Graph;

std::ostream& operator<< (std::ostream &, const Graph &);

class Graph {
friend std::ostream& operator<< (std::ostream &, const Graph &);
public:
  Graph ();
  Graph (const int &);
  void randomInit ();	//randomly generate a graph
  void randomInit (const double &);	//randomly generate a graph with a certain edge density 
  int *BFS (const int &s);	//conduct bfs search for vertex s, s ranges from 0 to n-1
  int *DFS ();	
  void DFSVisit (int *, int *, const int &);	//DFS visit a vertex, update the parent array
  void printPath (const int *parent, const int &s, const int &v);	//print the path from s to v
  ~Graph ();
private:
  bool addRandomEdge ();	//add an random edge, if successful, return true
  int **m;	//the adjacency matrix
  int n;	//# of vertices
  int time;	// time used for DFS search
  int *d;	//discovery time of each vertex
  int *f;	//finish time of each vertex
  static std::default_random_engine generator;	
};

#endif
