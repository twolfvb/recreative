/*#include <iostream>
#include "Hand.h"
#include <string>

using std::string;

int main() {
  Paper *paper = new Paper();
  Stone stone;
  Spock spock;
  Lizard lizard;
  int result = stone.play(*paper);
  delete paper;
  string result_string = std::to_string(static_cast<long long>(result));
  std::cout << "stone plays with paper and the result is " + result_string << std::endl;
  std::cout << "Hello, World!" << std::endl;
  return 0;
}*/

#include <iostream>
#include <string>
#include "Node.cpp"

using std::string;

int main() {
  Node<int> list[10] = {
      0, 1, 2, 3, 4, 5, 6, 7, 8, 9
  };
  Node<int> *root = new Node<int>(1);
  root->left = &list[2];
  root->right = &list[5];
  root->left->left = &list[3];
  root->left->right = &list[4];
  root->right->left = &list[6];
  root->right->right = &list[7];
  std::cout << "Printing tree:" << std::endl;
  root->print_tree();
  std::cout << "Hello, World!" << std::endl;
  return 0;
}