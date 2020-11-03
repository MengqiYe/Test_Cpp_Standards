//
// Created by mqye on 2020/9/28.
//

#include "common.h"
using namespace torch;

int main(int argc, char* argv[]) {


  // Equivalent to
  // std::vector<std::pair<double, unsigned>> fitness;
  Tensor fitness = torch::empty({10, 2}, torch::kFloat32);

  fitness[0] = torch::tensor({0 + 1, 0}, torch::kFloat32);
  fitness[1] = torch::tensor({1 + 1, 1}, torch::kFloat32);
  fitness[2] = torch::tensor({8 + 1, 8 }, torch::kFloat32);
  fitness[3] = torch::tensor({3 + 1, 3 }, torch::kFloat32);
  fitness[4] = torch::tensor({2 + 1, 2 }, torch::kFloat32);
  fitness[5] = torch::tensor({5 + 1, 5 }, torch::kFloat32);
  fitness[6] = torch::tensor({3 + 1, 3 }, torch::kFloat32);
  fitness[7] = torch::tensor({1 + 1, 1 }, torch::kFloat32);
  fitness[9] = torch::tensor({9 + 1, 9 }, torch::kFloat32);
  std::cout << "Before sort" << std::endl << fitness << std::endl;

  std::tuple<Tensor, Tensor> ret;
  if(argc > 1){
    int x = atoi(argv[1]);
//    std::cout << x << std::endl;
    ret = fitness.sort(x);
  }
  else{
    ret = fitness.sort(0);
  }

  std::cout << "After sort" << std::endl << std::get<0>(ret) << std::endl << std::get<1>(ret) << std::endl;

  return 0;
}