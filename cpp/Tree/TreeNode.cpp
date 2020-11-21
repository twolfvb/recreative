//
// Created by tw on 10/20/2018.
//

#include <iostream>
#include <stack>
#include <vector>
#include "TreeNode.h"
using namespace std;
template<typename T>
void TreeNode<T>::print_tree() {
  cout << this->data << "\n";
  if (this->left != nullptr)
    this->left->print_tree();
  if (this->right != nullptr)
    this->right->print_tree();
}

template<typename T>
void TreeNode<T>::print_without_recursion() {
  stack<TreeNode<T>> s;
  TreeNode<T> elem;
  s.push(*this);
  while (!s.empty()) {
    TreeNode<T> elem = s.top();
    s.pop();
    std::cout << elem.data << "\n";
    if (elem.right != nullptr) // right first because of pop order
      s.push(*(elem.right));
    if (elem.left != nullptr)
      s.push(*(elem.left));
  }
}

template<typename T>
int TreeNode<T>::max_height() {
  int retval = 1;
  int left_height = 0;
  if (this->left != nullptr) {
    left_height = this->left->max_height() + 1;
  }
  int right_height = 0;
  if (this->right != nullptr) {
    right_height = this->right->max_height() + 1;
  }
  if (right_height > retval) {
    retval = right_height;
  }
  if (left_height > retval) {
    retval = left_height;
  }
  return retval;
}

template<typename T>
bool TreeNode<T>::is_balanced() {
  int lhs = 0;
  int rhs = 0;
  if (this->left != nullptr)
    lhs = this->left->max_height();
  if (this->right != nullptr)
    rhs = this->right->max_height();
  if (abs(lhs-rhs) <= 1){
    if (this->left != nullptr){
      if (!this->left->is_balanced())
        return false;
    }
    if (this->right != nullptr) {
      if (!this->right->is_balanced())
        return false;
    }
  }
  return true;
}