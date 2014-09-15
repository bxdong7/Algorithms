#include <iostream>
#include "Graph.h"
using namespace std;


int main () {
  cout << "test graph begin" << endl;
  Graph g (5);
  g.randomInit (0.6);
  cout << g << endl;
  int *p = g.BFS(1);
  g.printPath (p, 1, 4);
  g.printPath (p, 1, 2);
  delete[] p;
  cout << "test graph end" << endl;
}
