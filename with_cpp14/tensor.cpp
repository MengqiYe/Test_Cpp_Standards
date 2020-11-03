//
// Created by mqye on 2020/9/29.
//

#include "common.h"

int main(){

  torch::Tensor x = torch::tensor({1, 3, 4, 2, 0, 5, 9}, torch::kInt32);
  int *x_ptr = x.data<int>();
  std::sort(x_ptr + 1, x_ptr + 4, std::less<int>()); // sorting {3, 4, 2}
  std::cout << x << std::endl; // prints 1 2 3 4 0 5 9
  return 0;

}