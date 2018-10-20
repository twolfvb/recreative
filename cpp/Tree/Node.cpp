//
// Created by tw on 10/20/2018.
//

#include <iostream>
#include "Node.h"

template<typename T>
void Node<T>::print_tree() {
  std::cout << this->data << "\n";
  if (this->left != nullptr)
    this->left->print_tree();
  if (this->right != nullptr)
    this->right->print_tree();
}