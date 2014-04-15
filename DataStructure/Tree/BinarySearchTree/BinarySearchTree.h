#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <stdexcept>

/*
  Binary Search Tree
  Support many dynamic set operations, like MINIMUM, MAXIMUM, PREDECESSOR, SUCCESSOR, INSERT, DELETE
  Also supports many tree walk algorithms, like PREORDER, INORDER, POSTORDER
  Complexity: 
    MINIMUM, MAXIMUM, PREDECESSOR, SUCCESSOR, INSERT, DELETE: O(h), h is O(lgn) if the tree is randomly built
    PREORDER, INORDER, POSTORDER: O(n)
*/

template <class T> class TreeNode;
template <class T> class BST;

template <class T>
std::ostream& operator<< (std::ostream&, const TreeNode<T>&);

template <class T>
std::ostream& operator<< (std::ostream&, const BST<T>&);


template <class T>
class TreeNode {
friend class BST <T>;
friend std::ostream& operator<< <T> (std::ostream&, const TreeNode<T>&);
friend std::ostream& operator<< <T> (std::ostream&, const BST<T>&); 
private:
  T v;
  TreeNode<T> *p;
  TreeNode<T> *left;
  TreeNode<T> *right;
  TreeNode ();
  TreeNode (const T &);
  TreeNode (const TreeNode<T> &);
  void copy (const TreeNode<T> *n, TreeNode<T> *cp);
  ~TreeNode ();
};


template <class T>
class BST {
friend std::ostream& operator<< <T> (std::ostream&, const BST<T>&); 
public:
  BST ();
  BST (const BST<T> &);
  void insert (const T&);
  void insert (const TreeNode<T> &);
  void remove (const T&) throw (std::runtime_error);	//if there are multiple such values, only remove one of them. Throw error when the value does not exist
  void remove (TreeNode<T> &) throw (std::runtime_error);
  TreeNode<T>* search (const T&);	//if there are multiple such values, only return one
  const TreeNode<T>* search (const T&) const;
  T predecessor (const T&);
  const TreeNode<T>* predecessor (const T&) const;
  T successor (const T&);
  const TreeNode<T>* successor (const T&) const;
  void preOrder () const;
  void inOrder () const;
  void postOrder () const;
  T max () const;
  T min () const;
  ~BST ();
private:
  TreeNode<T> *root;
  TreeNode<T>* MAXIMUM (TreeNode<T> *);
  const TreeNode<T>* MAXIMUM (const TreeNode<T> *) const;
  TreeNode<T>* MINIMUM (TreeNode<T> *);
  const TreeNode<T>* MINIMUM (const TreeNode<T> *) const;
  void PRE (const TreeNode<T> *n) const;
  void IN (const TreeNode<T> *n) const;
  void POST (const TreeNode<T> *n) const;
  void TRANSPOSE (TreeNode<T> *n1, TreeNode<T> *n2) throw (std::invalid_argument); 
//  void TRANSPOSE (TreeNode<T> *n1, TreeNode<T> *n2) throw (std::invalid_argument);	//replace n1 with n2 in the tree	
};

#include "BinarySearchTree.cpp"
#endif
