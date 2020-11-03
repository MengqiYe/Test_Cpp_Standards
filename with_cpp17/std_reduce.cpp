//
// Created by mqye on 2020/9/29.
//

#include "common.h"

int main() {
  // This is for C++ 17
  std::vector<float> v = {1,2,3,4};

  auto x = reduce(begin(v), end(v), 0);
  auto y = reduce(begin(v), end(v), 1, std::plus<>());
  auto z = reduce(begin(v), end(v), 1, std::multiplies<>());

  std::cout << x << std::endl << y << std::endl << z << std::endl;


  return 0;
}
