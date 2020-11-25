/**/

#include <iostream>
#include <string>
#include "TreeNode.cpp"

using std::string;

int Node_playground() {
  TreeNode<int> list[10] = {
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  };
  TreeNode<int> *root = new TreeNode<int>(1);
  int height;
  std::cout << "printing max height" << endl;
  height = root->max_height();
  std::cout << height << std::endl;
  root->left = &list[2];
  root->right = &list[5];
  std::cout << "printing max height" << endl;
  height = root->max_height();
  std::cout << height << std::endl;
  root->left->left = &list[3];
  root->left->right = &list[4];
  root->right->left = &list[6];
  std::cout << "printing max height" << endl;
  height = root->max_height();
  std::cout << height << std::endl;
  root->right->right = &list[7];
  root->right->right->right = &list[8];
  std::cout << "printing max height" << endl;
  height = root->max_height();
  std::cout << height << std::endl;
  std::cout << "Printing tree:" << std::endl;
  root->print_without_recursion();
  root->print_tree();
  std::cout << "Hello, World!" << std::endl;
  return 0;
}