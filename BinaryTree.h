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
    int size;
  BinaryTree(); //tree is initialized
  ~BinaryTree(); //all node pointers are freed
  void insert(ItemType key); //insert node
  void deleteItem(ItemType key); //removes node from list
  void retrieve(ItemType&item,bool&found) const; //found
  void preOrder() const; //print out pre-order
  void inOrder() const; //print our in order
  void postOrder() const; //print out post order
  int getLength() const; //print out length
  void getSameLevelNonsiblings(ItemType &key); //gets same level node value
  Node*  recursiveInsert(Node *ptr, ItemType key);
    void recursiveInOrder(Node* ptr) const;
    void recursivePreOrder(Node* ptr) const;
    void recursivePostOrder(Node* ptr) const;
};
#endif
