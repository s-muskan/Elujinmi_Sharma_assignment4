#include "BinaryTree.h"

using std::cout;
using std::endl;

BinaryTree:: BinaryTree() {
    root  = NULL;
}

BinaryTree:: ~BinaryTree() {
  recursiveDestroy(root);
}

void BinaryTree:: recursiveDestroy(Node *ptr) {
  if (ptr != NULL) {
    recursiveDestroy(ptr->left);
    recursiveDestroy(ptr->right);
    delete ptr;
  }
}

Node*  BinaryTree::recursiveInsert(Node *ptr, ItemType key) {
    if ( ptr == NULL) {
        ptr = new Node;
        ptr -> key = key;
    } else if (key.compareTo(ptr -> key) == LESS) {
        ptr -> left = recursiveInsert( ptr -> left, key);
    } else {
        ptr -> right = recursiveInsert( ptr -> right, key);
    }
    return ptr;
}

void BinaryTree::insert(ItemType key) {
    bool duplicate = false;
     recursiveRetrieve(key, duplicate, root);
     if (duplicate) {

         cout << "Item already in tree." <<endl;
         return;
     }

 if (root == NULL) {
        root = new Node();
        root -> key = key;
        size++;
        return;
    }
 recursiveInsert(root,key);
 size++;
 return;
}

void BinaryTree::inOrder() const {

    recursiveInOrder(root);
    cout <<endl;

}

void BinaryTree::preOrder() const {

    recursivePreOrder(root);
    cout << endl;
}

void BinaryTree::postOrder() const {

    recursivePostOrder(root);
    cout << endl;
}

void BinaryTree::recursiveInOrder(Node* ptr) const {

    if (ptr == NULL) {
        return;
    }

    recursiveInOrder(ptr -> left);

    cout << ptr -> key.getValue() << " ";

    recursiveInOrder(ptr -> right);
}


void BinaryTree::recursivePreOrder(Node* ptr) const {

    if (ptr == NULL) {
        return;
    }

    cout << ptr -> key.getValue() << " ";

    recursivePreOrder(ptr -> left);

    recursivePreOrder(ptr -> right);

}

void BinaryTree::recursivePostOrder(Node* ptr) const {

    if (ptr == NULL) {
        return;
    }

    recursivePostOrder( ptr -> left);

    recursivePostOrder( ptr -> right);

    cout << ptr -> key.getValue() << " ";


}

void BinaryTree::retrieve(ItemType &item, bool &found) const {

    recursiveRetrieve(item,  found, root);
}


void BinaryTree::recursiveRetrieve(ItemType item, bool &found, Node* ptr) const {

    if (ptr == NULL) {
        return;
    }

    recursiveRetrieve(item,  found, ptr -> left);
    recursiveRetrieve(item,  found, ptr -> right);
    if (ptr -> key.compareTo(item) == EQUAL) {
        found = true;
    }

}

int BinaryTree::getLength()const {
    return size;
}


void BinaryTree::deleteItem(ItemType key) {
  recursiveDelete(root, key);
}


Node* BinaryTree::recursiveDelete(Node* ptr, ItemType key) {

    if (ptr == NULL) {
        return ptr;
    }

    if (key.compareTo(ptr -> key) == LESS) {
      ptr -> left = recursiveDelete(ptr -> left, key);
    } else if (key.compareTo(ptr -> key) == GREATER) {
      ptr -> right = recursiveDelete(ptr -> right, key);
    } else {
      if (ptr -> left == NULL && ptr -> right == NULL) {
	size--;
	delete(ptr);
      } else if (ptr -> right == NULL) {
	Node *temp = ptr;
	ptr = ptr -> left;
	size--;
	delete temp;
      } else if (ptr -> left == NULL) {
	Node *temp = ptr;
	ptr = ptr -> right;
	size--;
	delete temp;
      } else {
	Node *min = findP(ptr->left);
	
	ptr -> key = min -> key;
	
	recursiveDelete(ptr -> left, min -> key);
      }
    }
    return ptr;
}

Node* BinaryTree:: findP(Node* node) {
  Node* min = node;
  while (min != NULL && min->left != NULL) {
    min = min -> left;
  }
  return min;
}
