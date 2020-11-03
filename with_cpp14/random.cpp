//
// Created by mqye on 2020/10/6.
//
#include <iostream>
#include <vector>
#include <random>
#include "boost/format.hpp"
#include <ATen/native/TensorIterator.h>



int main() {
  int seed = 2700001;
  int num_nodes = 58;

  std::mt19937 rng(seed);
  std::vector<double> keys(num_nodes);
  for (auto &key : keys)
    key = std::generate_canonical<double, std::numeric_limits<double>::digits>(rng);

  std::cout << keys << std::endl;
}