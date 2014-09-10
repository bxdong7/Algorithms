#ifndef BTREE_H
#define BTREE_H
#include <iostream>

#include "BTreeNode.h"

#define DEFAULT 10

/*
 *BTree is a balanced tree. All leaf nodes have the same depth, but the internal node may have different node of children.
 Each internal node contains >=t but <=2t children
 Insertion complexity: O(t * lg_t n), where n is # of keys in the tree
*/

std::ostream &operator << (std::ostream &, const BTree &);

int main ();


class BTree {
friend std::ostream &operator<<  (std::ostream &, const BTree &);
friend int main ();
public:
  size_t t;	//all nodes of this tree must contain at most 2t-1 keys, all nodes except root must contain at least t-1 keys
  BTree ();
  BTree (const size_t &);
  void insert (const int);
  ~BTree ();
private:
  BTreeNode *root;	
};


#endif

