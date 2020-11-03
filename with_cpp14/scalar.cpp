//
// Created by mqye on 2020/9/28.
//

#include "common.h"

using namespace torch;

int main(){
  torch::Scalar s = torch::Scalar(0);
  torch::Tensor t = torch::zeros({2,2}, torch::kFloat32);

  t[s] = torch::ones({1, 2}, torch::kFloat32);

  return 0;
}