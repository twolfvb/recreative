#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main() {
  cout << "lalalalaa" << '\n';
  []() {};
  auto h = [](double x, double y) noexcept ->double {return sqrt(x*x + y*y); };
  auto squared = [](double x) { return x*x; };
  auto my_print = [](int val) {cout << val << '\n'; };
  std::vector<int> v {3, 42, 123456, -5, 256};
  for_each(v.begin(), v.end(), [](int val) { cout << val << '\n'; });
  for_each(v.begin(), v.end(), my_print);

  return 0;
}