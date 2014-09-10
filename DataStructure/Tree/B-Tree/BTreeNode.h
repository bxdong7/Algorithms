#ifndef BTREENODE_H
#define BTREENODE_H
#include <iostream>



class BTree;


class BTreeNode;


std::ostream &operator << (std::ostream &, const BTreeNode &);

int main ();

class BTreeNode {
friend class BTree;
friend int main();
friend std::ostream& operator<< (std::ostream &, const BTreeNode &);
public:
  BTreeNode (){};
  BTreeNode (const size_t &, const bool &);
  void splitChild (const size_t &);	//split one of this node's children
  void insertIntoNonFull (const int);	//insert a key into the current node, with the assumption that the current node is not full
  ~BTreeNode ();
private:
  size_t t;	
  size_t n;	//# of keys in the node
  int *key;	//the keys
  BTreeNode **c;	//children, #=n+1
  bool leaf;	//true means it's a leaf node without children
};


#endif
