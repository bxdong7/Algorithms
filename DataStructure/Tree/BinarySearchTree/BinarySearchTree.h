#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

/*
  Binary Search Tree
  Support many dynamic set operations, like MINIMUM, MAXIMUM, PREDECESSOR, SUCCESSOR, INSERT, DELETE
  Also supports many tree walk algorithms, like PREORDER, INORDER, POSTORDER
  Complexity: 
    MINIMUM, MAXIMUM, PREDECESSOR, SUCCESSOR, INSERT, DELETE: O(h), h is O(lgn) if the tree is randomly built
    PREORDER, INORDER, POSTORDER: O(n)
*/

template <class T> TreeNode;
template <class T> BST;

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
  void remove (const T&);	//if there are multiple such values, only remove one of them
  void remove (const TreeNode<T> &);
  TreeNode* search (const T&);	//if there are multiple such values, only return one
  const TreeNode* search (const T&) const;
  T predecessor (const T&);
  TreeNode* predecessor (const T&);
  T successor (const T&);
  TreeNode* successor (const T&);
  void preOrder () const;
  void inOrder () const;
  void postOrder () const;
  T max () const;
  T min () const;
  ~BST ();
private:
  TreeNode<T> *root;
};

#include "BinarySearchTree.cpp"
#endif
