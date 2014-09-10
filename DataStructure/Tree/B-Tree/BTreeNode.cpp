#include <iostream>
#include <sstream>
#include <stdexcept>

#include "BTreeNode.h"

using namespace std;


BTreeNode::BTreeNode (const size_t &_t, const bool &_leaf) {
  t = _t;
  key = new int[2*t-1];
  n = 0;
  leaf = _leaf; 
  if (!leaf) {
    c = new BTreeNode*[2*t];
  }
  else
    c = NULL;
}


void BTreeNode::splitChild (const size_t &i) {
  BTreeNode *y;	//the new-ly created node
  int k;	//the key value in the mid of the i-th child
  ostringstream oss;

  if (leaf)
    throw runtime_error("no child in the node");
  
  if (i > n) {
    oss << "node " << key[0] << endl; 
    oss << i << " out of " << n;
    throw runtime_error("children index out of range: "+oss.str());
  }

  BTreeNode *x = c[i];
  
  //create a new node y
  y = new BTreeNode (t, x->leaf);

  //copy some the second half of key and children into y
  for (size_t j=t; j<x->n; j++)
    y->key[j-t] = x->key[j];
  y->n = t-1;

  if (!x->leaf) {
    for (size_t j=t; j<=x->n; j++) {
      y->c[j-t] = x->c[j];
      x->c[j] = NULL;  
    }
  }

  x->n = t-1;
  y->n = t-1;
  
  //get the key in the mid, insert the key into the current node
  k = x->key[t-1];
  if (n > 0) {
    for (size_t j=n-1; j>=i; j--) 
      key[j+1] = key[j];
  }
  key[i] = k;
 
  for (int j=static_cast<int>(n); j>static_cast<int>(i); j--)
    c[j+1] = c[j];
  c[i+1] = y;

  n++;
}


//the assumption is that the current node is not full

void BTreeNode::insertIntoNonFull (const int k) {
  size_t j;
  
  //if the current node is a leaf node
  if (leaf) {
    //move the keys larger than t in the node one block back
    j = n-1;
    while ((j>=0) && (key[j]>k)) {
      key[j+1] = key[j];
      j--;
    }
    //insert t
    key[j+1] = k;
    n++;
  }
  //else
  else {
    //find which child node of the current node should be further inspected 
    j = 0;
    while ((j<n) && (key[j]<k)) 
      j++;
    
    BTreeNode *child = c[j];
    //if the child is full
    if (child->n == 2*t-1) {
      //split the child node
      splitChild (j);
      
      //compare k with the new key to know which child to insert
      if (k > key[j])
        j++;
    }

    child->insertIntoNonFull (k);
  }
}


BTreeNode::~BTreeNode () {
  if (!leaf) {
    for (size_t i=0; i<=n; i++) 
      delete c[i];

    delete[] c;
  }

  delete key;
}


ostream &operator<< (std::ostream &os, const BTreeNode &node) {
  for (size_t i=0; i<node.n; i++)
    os << node.key[i] << ", ";
  os << endl;
  
  if (!node.leaf) {
    for (size_t i=0; i<=node.n; i++)
      os << *(node.c[i]);
  }
  return os;
}
