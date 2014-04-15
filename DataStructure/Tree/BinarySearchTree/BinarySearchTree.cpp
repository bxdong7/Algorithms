#include <iostream>
#include <stdexcept>
#include "BinarySearchTree.h"


template <class T>
TreeNode<T>::TreeNode () : p(NULL), left(NULL), right(NULL) {}

template <class T>
TreeNode<T>::TreeNode (const T &t) : v(t), p(NULL), left(NULL), right(NULL) {} 
  
template <class T>
TreeNode<T>::TreeNode (const TreeNode<T> &t) {
  copy (&t, NULL);
}

template <class T>
void TreeNode<T>::copy (const TreeNode<T> *n, TreeNode<T> *cp) {
  v = n->v;
  p = cp;
  if (n->left != NULL) {
    left = new TreeNode<T> ();
    left->copy (n->left, this);
  }
  else
    left = NULL;
  
  if (n->right != NULL) {
    right = new TreeNode<T> ();
    right->copy (n->right);
  }
  else
    right = NULL;
}

template <class T>
TreeNode<T>::~TreeNode<T> () {
  if (left != NULL) {
    delete left;
    left = NULL;
  }
  if (right != NULL) {
    delete right;
    right = NULL;
  }
}

template <class T>
std::ostream& operator<< (std::ostream &os, const TreeNode<T> &t) {
  os << t.v << std::endl;
  if (t.left != NULL)
    os << *(t.left);
  os << " : ";
  if (t.right != NULL)
    os << *(t.right);
  return os;
}


template <class T>
BST<T>::BST() : root(NULL) {}

template <class T>
BST<T>::BST (const BST<T> &t) {
  if (root != NULL)
    delete root;

  root = new TreeNode<T> (t.root);
}

template <class T>
void BST<T>::insert (const T &v) {
  const TreeNode<T> *n = root;	//the node help to find a NULL node
  TreeNode<T> *p = NULL;	//parent of n
  while (n != NULL) {
    if (v <= n->v) {
      p = const_cast<TreeNode<T>*>(n);
      n = n->left;
    }
    else {
      p = const_cast<TreeNode<T>*>(n);
      n = n->right;
    }
  }
  TreeNode<T> *c = new TreeNode<T> (v);	//current treenode
  c->p = const_cast<TreeNode<T>*>(p);
  if (p!=NULL) {
    if (v <= p->v) 
      p->left = c;
    else
      p->right = c;
  }
  else 
    root = c;
}

template <class T>
void BST<T>::insert (const TreeNode<T> &n) {
  insert (n.v);
}

template <class T>
void BST<T>::remove (const T &v) throw (std::runtime_error) {
  //find the node with the value 
  TreeNode<T> *n = search (v);
  if (n == NULL) {
    throw std::runtime_error("the deleted value does not exist in the BST");
  }
  //if both left and right are NULL, just delete n
  if ((n->left==NULL) && (n->right==NULL)) {
    if (n->p == NULL) {
      delete root;
      root = NULL;
    }
    else {
      if (n == n->p->left)
        n->p->left = NULL;
      else 
        n->p->right = NULL;
      delete n;
      n = NULL;
    }
  }
  //if n->right == NULL, lift n->left
  else {
    if (n->right == NULL) 
      TRANSPOSE (n, n->right);
  
    //else lift the minimum node on the right
    else {
      TreeNode<T> *r = MINIMUM(n->right);
      ////std::cout << "r: " << r->v << std::endl;
      TRANSPOSE (n, r);
    }
  }
}

template <class T>
void BST<T>::remove (TreeNode<T> &n) throw (std::runtime_error) {
  try{
    remove (n.v);
  }
  catch (const std::runtime_error &e) {
    throw;
  }
}

template <class T>
TreeNode<T>* BST<T>::search (const T &v) {
  TreeNode<T> *c = root;
  while ((c->v!=v) && (c!=NULL)) {
    if (v < c->v) 
      c = c->left;
    else
      c = c->right;
  }
  return c;
}

template <class T>
const TreeNode<T>* BST<T>::search (const T &v) const {
  const TreeNode<T> *c = root;
  while ((c->v!=v) && (c!=NULL)) {
    if (v < c->v) 
      c = c->left;
    else
      c = c->right;
  }
  return c;
}

template <class T>
T BST<T>::predecessor (const T &v) {
  const TreeNode<T> *n = search (v);
  if (n == NULL) 
    throw std::runtime_error ("the searched value does not exsit in the tree");

  //if the node has a left child, it's the predecessor
  if (n->left != NULL) 
    return n->left->v;

  //else find the ancestor such that the node is on the ancestor's RHS, find the minimum value rooted at the ancestor
  else {
    const TreeNode<T> *c = n;	//current node
    const TreeNode<T> *p = n->p;	//the parent of n
    while ((p!=NULL) && (p->right!=c)) {
      c = p;
      p = p->p;
    }

    if (p == NULL) {
      throw std::runtime_error ("the value is the minimum in the tree, node predecessor");
    }
    else {
      return MINIMUM(p)->v;
    }
  }
}

template <class T>
const TreeNode<T>* BST<T>::predecessor (const T &v) const {
  const TreeNode<T> *n = search (v);
  if (n == NULL) 
   throw std::runtime_error ("the searched value does not exsit in the tree");

  //if the node has a left child, it's the predecessor
  if (n->left != NULL) 
    return n->left->v;

  //else find the ancestor such that the node is on the ancestor's RHS, find the minimum value rooted at the ancestor
  else {
    const TreeNode<T> *c = n;	//current node
    const TreeNode<T> *p = n->p;	//the parent of n
    while ((p!=NULL) && (p->right!=c)) {
      c = p;
      p = p->p;
    }

    if (p == NULL) {
      throw std::runtime_error ("the value is the minimum in the tree, node predecessor");
    }
    else {
      return MINIMUM(p);
    }
  }
}

template <class T>
T BST<T>::successor (const T &v) {
  const TreeNode<T> *n = search (v);
  if (n == NULL)
    throw std::runtime_error ("the searched value does not exsit in the tree");

  //if the node has a right child, it's the successor
  if (n->right != NULL)
    return n->right->v;

  else {
    const TreeNode<T> *c = n;	//current node
    const TreeNode<T> *p = n->p;	//the parent of n
    while ((p!=NULL) && (p->left!=c)) {
      c = p;
      p = p->p;
    }

    if (p == NULL) {
      throw std::runtime_error ("the value is the maximum in the tree, node predecessor");
    }
    else {
      return MAXIMUM(p)->v;
    }
  }
}

template <class T>
const TreeNode<T>* BST<T>::successor (const T &v) const {
  const TreeNode<T> *n = search (v);
  if (n == NULL)
    throw std::runtime_error ("the searched value does not exsit in the tree");

  //if the node has a right child, it's the successor
  if (n->right != NULL)
    return n->right->v;

  else {
    const TreeNode<T> *c = n;	//current node
    const TreeNode<T> *p = n->p;	//the parent of n
    while ((p!=NULL) && (p->left!=c)) {
      c = p;
      p = p->p;
    }

    if (p == NULL) {
      throw std::runtime_error ("the value is the maximum in the tree, node predecessor");
    }
    else {
      return MAXIMUM(p);
    }
  }
}

template <class T>
void BST<T>::preOrder () const {
  PRE (root);
}

template <class T>
void BST<T>::inOrder () const {
  IN (root);
}

template <class T>
void BST<T>::postOrder () const {
  POST (root);
}

template <class T>
T BST<T>::max () const {
  return MAXIMUM(root)->v;
}

template <class T>
T BST<T>::min () const {
  return MINIMUM(root)->v;
}

template <class T>
const TreeNode<T>* BST<T>::MAXIMUM (const TreeNode<T> *n) const {
  return const_cast<const TreeNode<T>*>(this->MAXIMUM(n));
}

template <class T>
TreeNode<T>* BST<T>::MAXIMUM (TreeNode<T> *n) {
  if (n == NULL) 
    throw std::runtime_error ("the node is an empty node");

  while (n->right != NULL)
    n = n->right;

  return n;
}

template <class T>
const TreeNode<T>* BST<T>::MINIMUM (const TreeNode<T> *n) const {
  return const_cast<TreeNode<T>*>(this->MINIMUM(n));
}

template <class T>
TreeNode<T>* BST<T>::MINIMUM (TreeNode<T> *n) {
  if (n == NULL) { 
    //std::cout << "null" << std::endl;
    throw std::runtime_error ("the node is an empty node");
  }
    //std::cout << " mini not null" << std::endl;
  while (n->left != NULL)
    n = n->left;
  
  return n;
}

template <class T>
void BST<T>::PRE (const TreeNode<T> *n) const {
  if (n != NULL) {
    std::cout << n->v << "  ";
    PRE (n->left);
    PRE (n->right);
  }
}

template <class T>
void BST<T>::IN (const TreeNode<T> *n) const {
  if (n != NULL) {
    IN (n->left);
    std::cout << n->v << "  ";
    IN (n->right);
  }
}

template <class T>
void BST<T>::POST (const TreeNode<T> *n) const {
  if (n != NULL) {
    POST (n->left);
    POST (n->right);
    std::cout << n->v << "  ";
  }
}

template <class T>
void BST<T>::TRANSPOSE (TreeNode<T> *n1, TreeNode<T> *n2) throw (std::invalid_argument) {
  if ((n1==NULL) || (n2==NULL))
    throw std::invalid_argument ("Invalid argument: at least one node is NULL");

  //if n2 is n1's left node, delete n1 like a linked list
  if (n2 == n1->left) {
    if (n1->p == NULL) {
      root = n2;  
    }
    else {
      n2->p = n1->p;
      if (n1 == n1->p->left)
        n1->p->left = n2;
      else
        n1->p->right = n2;
    }
  }
  else {
    //if n2 is n1's right node, delete n1 like a linked list
    if (n2 == n1->right) {
      if (n1->p == NULL)
        root = n2;
      else {
        n2->p = n1->p;
        if (n1 == n1->p->left)
          n1->p->left = n2;
        else
          n1->p->right = n2;
      }
      n2->left = n1->left;
      if (n2->left != NULL)
        n2->left->p = n2;
	//std::cout << "here" << std::endl;
    }
    //else n2 is the minimal value on n1's right hand side
    else {
      if (n1->p == NULL) {
        root = n2;
      }
      else {
        if (n1 == n1->p->left)
          n1->p->left = n2;
        else 
          n1->p->right = n2;
      }
      n2->p->left = n2->right;
      if (n2->right != NULL)
        n2->right->p = n2->p;
      n2->p = n1->p;
      n2->left = n1->left;
      if (n2->left != NULL)
        n2->left->p = n2;
      n2->right = n1->right;
      if (n2->right != NULL)
        n2->right->p = n2->p;
    }
  }
  //delete n1
  n1->left = NULL;
  n1->right = NULL;
  n1->p = NULL;
  //std::cout << "there" << std::endl;
  delete n1;
  n1 = NULL;
}

template <class T>
BST<T>::~BST () {
  if (root != NULL) {
    delete root;
    root = NULL;
  }
}


template <class T>
std::ostream& operator<< (std::ostream &os, const BST<T> &t) {
  if (t.root != NULL)
    os << *(t.root);

  return os;
}
