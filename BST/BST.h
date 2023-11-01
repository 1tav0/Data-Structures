#ifndef MY_BST_H
#define MY_BST_H

#include <assert.h>
#include <string>
#include <iostream>
#include <cstddef>
#include <iomanip>
using namespace std;

template <class bstdata>
class BST{
  private:
    struct Node{
      bstdata data;
      Node *left;
      Node *right;

      Node(bstdata newData){
        data = newData;
        left = right = NULL;
      }
    };
    Node *root;

    /***Private helper functions***/
    void insertNode(Node *root, bstdata data);
    //for public insert
    //will use recursion to insert a value into bst
    void inOrderPrint(ostream &out, Node *root) const;
    //recursively prints tree in order from smallest to largest
    void preOrderPrint(ostream &out, Node *root) const;
    //recursively prints tree in pre order
    void postOrderPrint(ostream &out, Node *root) const;
    //recursively prints tree in post order
    void copyNode(Node *copy);
    //helper recursive function for copy constructor
    void freeNode(Node *root);
    //helper functiontion for destructor
    //using recursion to free the memory in the bst
    void getSize(Node *root, int &size) const;
    //helper recursive function for size
    //calculates the size of the tree
    //stores the result in size
    int getHeight(Node *root) const;
    //helper recursive function for height function
    //returns the height of the tree
    bool searchNode(Node *root, bstdata data) const;
    //recursive helper function for search
    bstdata minimum(Node *root) const;
    //returns the minimum value in the tree
    //helper recursive function for minimum
    bstdata maximum(Node *root) const;
    //returns the maximum value in the tree
    //helper recursive function for maximum
    Node *removeNode(Node *root, bstdata data);
    //removes data frm the tree
    //helper recursive function for remove

  public:
  /***Constructors***/
    BST();
    //Instantiates a new BST
    ~BST();
    //deallocates the tree memory
    BST(const BST &bst);
    //copy constructor

  /***Access Functions***/
    bstdata getMinimum() const;
    //returns the minimum value in the BST
    //pre: !empty()
    bstdata getMaximum() const;
    //returns the maximum value in the BST
    //pre: !empty()
    bool isEmpty() const;
    //determines whether the BST is empty
    int getSize() const;
    //returns the size of the tree
    bstdata getRoot() const;
    //returns the value stored at the root of the BST
    //pre: !isEmpty()
    int getHeight() const;
    //returns the heigh of the tree
    bool search(bstdata data) const;
    //returns wether the data is found in the tree
    //pre: !isEmpty()

  /***Manipulation Functions***/
    void insert(bstdata data);
    //inserts a new element into the bst
    void remove(bstdata data);
    //removes the value from the bst
    //pre: data is found in the tree
    //pre: !isEmpty()

  /***Additional Procedures***/
    void inOrderPrint(ostream &out) const;
    //calls the private function to print out the values
    //stored in the bst
    void preOrderPrint(ostream& out) const;
    //calls the reOrderPrint function to print out the values
    //stored in the BST

    void postOrderPrint(ostream& out) const;
    //calls the postOrderPrint function to print out the values
    //stored in the BST
};


template <class bstdata>
BST<bstdata>::BST(){
  root = NULL;
}

template <class bstdata>
BST<bstdata>::~BST(){
  freeNode(root);
}

template <class bstdata>
void BST<bstdata>::freeNode(Node *root){
  if(root==NULL){
      return;
  }else{
    freeNode(root->left);
    freeNode(root->right);
    delete (root);
  }
}

/*In the copy constructor BST<bstdata>::BST(const BST &bst), you want to create a new binary search tree (this) by copying the nodes from the bst tree.

Without root = NULL;, your binary search tree (this) starts with its root member pointing to some memory location, even if it's uninitialized. This means it could be pointing to random memory or data.

When you call the copyNode(bst.root) function inside the copy constructor, it recursively tries to copy nodes from bst into the this tree.

If the root of the this tree isn't set to NULL, the copying process might encounter uninitialized memory or data in the this tree's structure (as this is a copy of bst), causing a segmentation fault because it tries to access or manipulate memory it shouldn't.

By adding root = NULL;, you explicitly initialize the root of the new tree (this) to be an empty tree with no nodes. This ensures that the copying process starts with a clean slate and doesn't try to reference or modify any uninitialized or random memory locations.*/
template <class bstdata>
BST<bstdata>::BST(const BST &bst){
  root = NULL; //Create an empty tree
  copyNode(bst.root);
}

template <class bstdata>
void BST<bstdata>::copyNode(Node *node){
  if(node == NULL){
    return;
  }else{
    insert(node->data);
    copyNode(node->left);
    copyNode(node->right);
  }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream &out, Node *root) const{
  if(root == NULL){
    return;
  }else{
    inOrderPrint(out, root->left);
    out << root->data << " ";
    inOrderPrint(out, root->right);
  }
}

template <class bstdata>
void BST<bstdata>::inOrderPrint(ostream &out) const{
  inOrderPrint(out, root);
  cout << endl;
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream &out, Node *root) const{
  if(root == NULL){
    return;
  }else{
    out << root->data << " ";
    preOrderPrint(out, root->left);
    preOrderPrint(out, root->right);
  }
}

template <class bstdata>
void BST<bstdata>::preOrderPrint(ostream &out) const{
  preOrderPrint(out, root);
  cout << endl;
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream &out, Node *root) const{
  if(root == NULL){
    return;
  }else{
    postOrderPrint(out, root->left);
    postOrderPrint(out, root->right);
    out << root->data << " ";
  }
}

template <class bstdata>
void BST<bstdata>::postOrderPrint(ostream &out) const{
  postOrderPrint(out, root);
  cout << endl;
}

template <class bstdata>
void BST<bstdata>::insertNode(Node *root, bstdata data){
  if(data == root->data){
    return;
  }else{
    if(data < root->data){
      if(root->left == NULL){
        root->left = new Node(data);
      }else{
        insertNode(root->left, data);
      }
    }else{
      if(root->right == NULL){
        root->right = new Node(data);
      }else{
        insertNode(root->right,data);
      }
    }
  }
}

template <class bstdata>
void BST<bstdata>::insert(bstdata data){
  if(root == NULL){
    root = new Node(data);
  }else{
    insertNode(root, data);
  }
}

template <class bstdata>
bool BST<bstdata>::searchNode(Node *root, bstdata data) const{
  if(root->data == data){
    return true;
  }else if(data < root->data){
    if(root->left == NULL){
      return false;
    }else{
      return searchNode(root->left, data);
    }
  }else{
    if(root->right == NULL){
      return false;
    }else{
      return searchNode(root->right,data);
    }
  }
}

template <class bstdata>
bool BST<bstdata>::search(bstdata data) const{
  if(root->data == data){
    return true;
  }else{
    return searchNode(root, data);
  }
  
}

template <class bstdata>
bstdata BST<bstdata>::minimum(Node *root) const{
  if(root->left != NULL){
    return minimum(root->left);
  }else{
    return root->data;
  }
}

template <class bstdata>
bstdata BST<bstdata>::getMinimum() const{
  assert(!isEmpty());
  return minimum(root);
}

template <class bstdata>
bstdata BST<bstdata>::maximum(Node *root) const{
  if(root->right != NULL){
    return maximum(root->right);
  }
  else{
    return root->data;
  }
}

template <class bstdata>
bstdata BST<bstdata>::getMaximum() const{
  assert(!isEmpty());
  return maximum(root);
}

template <class bstdata>
typename BST<bstdata>::Node* BST<bstdata>::removeNode(Node *root, bstdata data){
  if(root==NULL){
    return root;
  }else if(data < root->data){
    root->left = removeNode(root->left, data);
  }else if(data > root->data){
    root->right = removeNode(root->right, data);
  }else{
    if(root->left == NULL && root->right == NULL){
      delete (root);
      root = NULL;
    }else if(root->right == NULL){
      Node *temp = root;
      root = root->left;
      delete (temp);
    }
    else if(root->left == NULL){
      Node *temp = root;
      root = root->right;
      delete (temp);
    }else{
      //if both childs exist we choose right side to promote bst property of root value being higher than left child values
      //we dont delete root because we need to still keep the left child that exist if we delete it we loost it too therefor we just replace its data
      root->data = minimum(root->right);
      root->right = removeNode(root->right, minimum(root->right));
    }
  }
  return root;
}

template <class bstdata>
void BST<bstdata>::remove(bstdata data){
  assert(!isEmpty());
  removeNode(root, data);
}

template <class bstdata>
bstdata BST<bstdata>::getRoot() const{
  assert(!isEmpty());
  return root->data;
}

template <class bstdata>
bool BST<bstdata>::isEmpty() const{
  if(root == NULL){
    return true;
  }else{
    return false;
  }
}

template <class bstdata>
void BST<bstdata>::getSize(Node *root, int &size) const{
  if(root != NULL){
    if(root->left){
      getSize(root->left, ++size);
    }
    if(root->right){
      getSize(root->right, ++size);
    }
  }
}

template <class bstdata>
int BST<bstdata>::getSize() const{
  int size = 0;
  if(!isEmpty()){
    getSize(root, ++size);
  }
  return size;
}

template <class bstdata>
int BST<bstdata>::getHeight(Node *root) const {
  if(root == NULL){
    return 0;
  }else if(getHeight(root->right) > getHeight(root->left)){
    return 1 + getHeight(root->right);
  }else{
    return 1 + getHeight(root->left);
  }
}

template <class bstdata>
int BST<bstdata>:: getHeight() const{
  return getHeight(root);
}
#endif