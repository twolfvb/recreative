#include <iostream>
#include "Hand.h"
#include <string>

using std::string;

int main() {
    Paper paper;
    Stone stone;
    Spock spock;
    Lizard lizard;
    int result = stone.play(paper);
    string result_string = std::to_string(static_cast<long long>(result));
    std::cout << "stone plays with paper and the result is " + result_string << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}