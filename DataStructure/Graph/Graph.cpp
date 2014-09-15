#include <iostream>
#include <random>
#include <queue>
#include <climits>
#include "Graph.h"

using namespace std;


default_random_engine Graph::generator;

Graph::Graph () {

}

Graph::Graph (const int &_n) {
  n = _n;

  m = new int*[n];
  for (int i=0; i<n; i++)
    m[i] = new int[n]();

  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      if (i == j)
        m[i][j] = 1;
      else
        m[i][j] = 0;
    }
  }

}

void Graph::randomInit () {
  int edges;	//required # of edges besides m[i][j]
  int count;	//# of edges
  std::uniform_int_distribution<int> distribution;	//the random generator to generate a random count

  distribution = uniform_int_distribution<int>(1, n*(n-1));
  
  edges = distribution (Graph::generator);

  if (edges%2 == 1)
    edges++;

   count = 0;
   while (count < edges) {
     if (addRandomEdge ())
       count += 2;
   }
}

void Graph::randomInit (const double &density) {
  int edges;	//required # of edges besides m[i][j], edges=density*n*(n-1)
  int count;	//# of edges

  
  edges = static_cast<int>(density*n*(n-1));

  if (edges%2 == 1)
    edges++;

   count = 0;
   while (count < edges) {
     if (addRandomEdge ())
       count += 2;
   }
}

int *Graph::BFS (const int &s) {
  int *color, *depth, *parent;
  queue<int> Q;
  int u, v;

  //initialize vertex's color 
  color = new int[n];
  for (int i=0; i<n; i++)
    color[i] = White;

  //initialize vertex's depth
  depth = new int[n];
  for (int i=0; i<n; i++)
    depth[i] = INT_MAX;

  //initialize vertex's parent
  parent = new int[n];
  for (int i=0; i<n; i++)
    parent[i] = NIL;

  //enqueue s
  color[s] = Gray;
  parent[s] = NIL;
  depth[s] = 0;
  Q.push (s);

  //while Q is not empty
  while (!Q.empty()) {
    //u = Dequeue(Q)
    u = Q.front();
    Q.pop ();

    //foreach v in Adj(u)
    for (int i=0; i<u; i++) {
      if (i != u) {
        if (m[u][i] == 1) {
	  v = i;
          //if v.color is White
	  if (color[v] == White) {
	    //v.color=Gray
	    color[v] = Gray;
	    //v.parent = u
	    parent[v] = u;
	    //v.d = u.d+1
	    depth[v] = depth[u]+1;
	    //enqueue(v)
	    Q.push (v);
	  }
	}
      }
    }
    //v.color = Black
    color[u] = Black;
  }

  delete[] color;
  delete[] depth;
  return parent;
}

void Graph::printPath (const int *parent, const int &s, const int &v) {
  if (v == s)
    cout << s;
  else {
    if (parent[v] == NIL)
      cout << "no path from " << s << " to " << v << endl;
    else {
      printPath(parent, s, parent[v]);
      cout << "->" << v;
    }
  }
}

Graph::~Graph () {
  for (int i=0; i<n; i++)
    delete[] m[i];

  delete[] m;
}

bool Graph::addRandomEdge () {
  int u, v;
  uniform_int_distribution<int> distribution;	//the random generator to generate a random count

  distribution = uniform_int_distribution<int>(0, n-1);
  
  u = distribution (Graph::generator);
  v = distribution (Graph::generator);

  if (u == v)
    return false;
  else {
    if (m[u][v] == 0) {
      m[u][v] = 1;
      m[v][u] = 1;
      return true;
    }
    else
      return false;
  }
}

ostream& operator<< (ostream &os, const Graph &g) {
  for (int i=0; i<g.n; i++) {
    for (int j=0; j<g.n; j++)
      os << g.m[i][j] << " ";
    os << endl;
  }
  return os;
}
