#include <iostream>
#include "Graph.h"
using namespace std;


int main () {
  cout << "test graph begin" << endl;
  int *p;
  Graph g (5);
  g.randomInit (0.6);
  cout << g << endl;

  cout << "test BFS begin" << endl;
  p = g.BFS(1);
  for (int i=0; i<5; i++)
    cout << p[i] << ", "; 
  cout << endl;
  g.printPath (p, 1, 4);
  cout << endl;
  g.printPath (p, 1, 2);
  cout << endl;
  delete[] p;
  cout << "test BFS end" << endl;

  cout << "test DFS begin" << endl;
  p = g.DFS();
  for (int i=0; i<5; i++)
    cout << p[i] << ", "; 
  cout << endl;
  g.printPath (p, 1, 4);
  cout << endl;
  g.printPath (p, 1, 2);
  cout << endl;
  delete[] p;
  cout << "test DFS end" << endl;

  cout << "test graph end" << endl;
}
