//
// Created by mqye on 2020/9/29.
//

#include "common.h"

int main() {
  std::string s = "Hello world! This is a string.";
  std::vector<int> n{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  std::cout << s << "\n";
  std::replace(begin(s), end(s), 's', 'B');
  std::cout << s << "\n";

  std::for_each(begin(n), end(n), [](int i) { std::cout << i << " "; }); std::cout << std::endl;
  std::replace_if(begin(n), end(n), [](int i) -> bool { return i >= 7; }, 6);
  std::for_each(begin(n), end(n), [](int i) { std::cout << i << " "; }); std::cout << std::endl;

  return 0;
}