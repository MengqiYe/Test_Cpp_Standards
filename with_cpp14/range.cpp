//
// Created by mqye on 2020/9/28.
//
#include "common.h"

int main(){
  torch::Tensor t = torch::ones({1, 10, 10, 1});
  torch::range_out(t, 0, 99, 1);
//  torch::range_out(t, 0, 299, 1);
  std::cout << t.sizes() << std::endl;
//  std::cout << t << std::endl;
  for (int i = 0; i < 10; ++i) {
    std::cout << t[0][i] << std::endl;
  }

  return 0;
}