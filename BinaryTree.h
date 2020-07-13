#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "ItemType.cpp"


struct Node {
  ItemType key;
  Node *left;
  Node *right;
};

class BinaryTree {
private:
  Node *root;
public:
  BinaryTree(); //tree is initialized
  ~BinaryTree(); //all node pointers are freed
  void insert(ItemTypekey); //insert node
  void deleteItem(ItemTypekey); //removes node from list
  void retrieve(ItemType&item,bool&found) const; //found
  void preOrder() const; //print out pre-order
  void inOrder() const; //print our in order
  void postOrder() const; //print out post order
  inst getLength() const; //print out length
  void getSameLevelNonsiblings(ItemType &key); //gets same level node value
};
#endif
