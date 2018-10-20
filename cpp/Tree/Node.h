//
// Created by tw on 10/19/2018.
//

#ifndef CPP_NODE_H
#define CPP_NODE_H
template<class T>
class Node {
 public:

  Node<T> *parent, *left, *right;
  T data;

  Node() : parent(nullptr), left(nullptr), right(nullptr) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }

  Node(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}

  Node(T data, Node<T> *parent, Node<T> *left, Node<T> *right) :
      data(data), parent(parent), left(left), right(right) {}

  Node(T data, Node<T> *left, Node<T> *right) :
      data(data), parent(nullptr), left(left), right(right) {}

  void print_tree();
};
#endif //CPP_NODE_H
