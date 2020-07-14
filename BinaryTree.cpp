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

 if (root == NULL) {
        root = new Node();
        root -> key = key;
        return;
    }
 recursiveInsert(root,key);
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

    cout << ptr -> key.getValue();


}
