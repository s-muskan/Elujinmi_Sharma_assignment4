#include "BinaryTree.h"

using std::cout;
using std::endl;

BinaryTree:: BinaryTree() {
    root  = NULL;
}

BinaryTree:: ~BinaryTree() {

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
