#include "BinaryTree.h"

using std::cout;
using std::endl;

BinaryTree:: BinaryTree() {
  root  = NULL; //root is null
}

BinaryTree:: ~BinaryTree() {
  recursiveDestroy(root); //destroys tree recursively
}

void BinaryTree:: recursiveDestroy(Node *ptr) {
  if (ptr != NULL) { //uses recursive to delete each node
    recursiveDestroy(ptr->left); //goes bottom to up
    recursiveDestroy(ptr->right);
    delete ptr; //deltes node
  }
}

Node*  BinaryTree::recursiveInsert(Node *ptr, ItemType key) {
    if ( ptr == NULL) { 
      ptr = new Node; //new node initialized
      ptr -> key = key;
    } else if (key.compareTo(ptr -> key) == LESS) {
      ptr -> left = recursiveInsert( ptr -> left, key); //ptr is set to new pointer and called recursively
    } else {
      ptr -> right = recursiveInsert( ptr -> right, key); //called recursively on the left side
    }
    return ptr; //ptr is retured
}

void BinaryTree::insert(ItemType key) {
  bool duplicate = false; //checks for duplicate items
  recursiveRetrieve(key, duplicate, root); //checks to see if item is in tree already
  if (duplicate) {
    
    cout << "Item already in tree." <<endl; //if item already exits
    return; //returns funciton
  }
  
  if (root == NULL) { //if list is empty
    root = new Node(); //new root
    root -> key = key; //new data
    size++; //adds to size
    return;
  }
  recursiveInsert(root,key); //if not new node, adds recursivly
  size++; //increments size
  return;
}

void BinaryTree::inOrder() const {

  recursiveInOrder(root); //prints inorder recursively
  cout <<endl; 

}

void BinaryTree::preOrder() const {
  recursivePreOrder(root); //prints preoder
  cout << endl;
}

void BinaryTree::postOrder() const {
  recursivePostOrder(root); //prints postorder
  cout << endl;
}

void BinaryTree::recursiveInOrder(Node* ptr) const {

  if (ptr == NULL) { //if root is null
    return;
  }

  recursiveInOrder(ptr -> left); //goes left
  
  cout << ptr -> key.getValue() << " "; //root
  
  recursiveInOrder(ptr -> right); //right
}


void BinaryTree::recursivePreOrder(Node* ptr) const {

    if (ptr == NULL) {
        return;
    }

    cout << ptr -> key.getValue() << " "; //goes root
    
    recursivePreOrder(ptr -> left); //left

    recursivePreOrder(ptr -> right); //and then right

}

void BinaryTree::recursivePostOrder(Node* ptr) const {

    if (ptr == NULL) {
        return;
    }

    recursivePostOrder( ptr -> left); //goes left

    recursivePostOrder( ptr -> right); //right

    cout << ptr -> key.getValue() << " "; //then root


}

void BinaryTree::retrieve(ItemType &item, bool &found) const {

  recursiveRetrieve(item,  found, root); //retrieves item
}


void BinaryTree::recursiveRetrieve(ItemType item, bool &found, Node* ptr) const {

    if (ptr == NULL) {
        return;
    }

    recursiveRetrieve(item,  found, ptr -> left); //goes through the entire list
    recursiveRetrieve(item,  found, ptr -> right); //goes through list to find
    if (ptr -> key.compareTo(item) == EQUAL) { //if equal
      found = true; //then true
    }

}

int BinaryTree::getLength()const {
  return size; //returns size
}


void BinaryTree::deleteItem(ItemType key) {
  deleteHelper(root, key); //deletes
  size--;
}

void BinaryTree::deleteHelper(Node*& node, ItemType& key) {
  bool duplicate = false; //to check if somethign is not in list
  recursiveRetrieve(key, duplicate, root);
  if (!duplicate) {
    
    cout << "Item not in tree." <<endl;
    return;
  }
  
  if(key.compareTo(node -> key) == LESS) { //checks which way it needs to go
    deleteHelper(node -> left, key); //recursive
  } else if (key.compareTo(node -> key) == GREATER) { //checks which way it needs to go
    deleteHelper(node -> right, key); //recursive
  } else {
    deleteNode(node); //find and delete node
  }
}

void BinaryTree::deleteNode(Node*& n) {
  Node* temp = n;
  //case 1: root only has 1 child
  if (n -> right == NULL) {
    n = n -> left;
    delete temp;
  } else if (n -> left == NULL) {
    n = n -> right;
    delete temp;
  } else {
    //case 2: root has 2 children
    Node* ptr = getPredecessor(n -> left); //gets predecessor
    n -> key = ptr -> key; //sets n key to ptr key to change the data of n to predecessors
    deleteHelper(n -> left, n -> key); //deltes the duplicate item
  }
}

Node* BinaryTree::getPredecessor(Node*& node) {
  while(node -> right != NULL) { //finds predecessor
    node = node -> right;
  }
  return node;
}

