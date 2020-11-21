//
// Created by tw on 10/19/2018.
//

#ifndef CPP_NODE_H
#define CPP_NODE_H
template<class T>
class TreeNode {
 public:

  TreeNode<T> *parent, *left, *right;
  T data;

  TreeNode() : parent(nullptr), left(nullptr), right(nullptr) {
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }

  TreeNode(T data) : data(data), parent(nullptr), left(nullptr), right(nullptr) {}

  TreeNode(T data, TreeNode<T> *parent, TreeNode<T> *left, TreeNode<T> *right) :
      data(data), parent(parent), left(left), right(right) {}

  TreeNode(T data, TreeNode<T> *left, TreeNode<T> *right) :
      data(data), parent(nullptr), left(left), right(right) {}

  void print_tree();
  void print_without_recursion();
  int max_height();
  bool is_balanced();
};
#endif //CPP_NODE_H
