//
// Created by mqye on 2020/9/28.
//

#include "common.h"

int main(){

  torch::Tensor t = torch::ones({1, 10, 10, 1});
  t = t.reshape({-1, 5});
  std::cout << t << std::endl;
  return 0;
}