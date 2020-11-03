//
// Created by mqye on 2020/9/29.
//

#include "common.h"

int main(){
  std::vector<float> v = {1,2,3,4};

  auto x = accumulate(begin(v), end(v), 0);
  auto y = accumulate(begin(v), end(v), 1, std::multiplies<>());

  std::cout << x << std::endl << y << std::endl;

  return 0;
}