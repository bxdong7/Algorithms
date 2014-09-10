#include <iostream>
#include <stdexcept>

#include "BTree.h"

using namespace std;



BTree::BTree () {
  t = DEFAULT;
  root = new BTreeNode(t, true);
}


BTree::BTree (const size_t &size) {
  t = size;
  root = new BTreeNode(t, true);
} 


void BTree::insert (const int k) {
  //if root is full
  if (root->n == (2*t-1)) {
    //split root
    BTreeNode *p = new BTreeNode (t, false);
    p->c[0] = root;
    root = p;
    //cout << "root->n" << root->n << endl;
    root->splitChild(0);
  }
  //do insertion on root
  root->insertIntoNonFull (k);
}


BTree::~BTree () {
  delete root;
}


ostream & operator<< (ostream &os, const BTree &tree) {
  os << *(tree.root) << endl;
  return os;
}

