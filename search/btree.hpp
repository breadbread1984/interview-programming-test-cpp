#ifndef BTREE_HPP
#define BTREE_HPP

#include <memory>

using namespace std;

template<typename T>
class Node {
  T data;
  shared_ptr<Node<T>> left;
  shared_ptr<Node<T>> right;
public: 
  Node(T data);
  ~Node();
  void set_left(shared_ptr<Node<T>> left);
  void set_right(shared_ptr<Node<T>> right);
  shared_ptr<Node<T>> get_left();
  shared_ptr<Node<T>> get_right();
  void insert(T data);
  void print();
};

template<typename T>
Node<T>::Node(T d): data(d) {
}

template<typename T>
Node<T>::~Node() {
}

template<typename T>
void Node<T>::set_left(shared_ptr<Node<T>> left) {
  this->left = left;
}

template<typename T>
void Node<T>::set_right(shared_ptr<Node<T>> right) {
  this->right = right;
}

template<typename T>
shared_ptr<Node<T>> Node<T>::get_left() {
  return left;
}

template<typename T>
shared_ptr<Node<T>> Node<T>::get_right() {
  return right;
}

template<typename T>
void Node<T>::insert(T data) {
  if(data < this->data) {
    if (left == nullptr) {
      left = shared_ptr<Node<T>>(new Node(data));
    } else {
      left->insert(data);
    }
  } else {
    if (right == nullptr) {
      right = shared_ptr<Node<T>>(new Node(data));
    } else {
      right->insert(data);
    }
  }
}

template<typename T>
void Node<T>::print() {
  if (left != nullptr) {
    left->print();
  }
  cout<<data<<",";
  if (right != nullptr) {
    right->print();
  }
}

#endif

