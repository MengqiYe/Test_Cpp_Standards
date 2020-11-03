//
// Created by mqye on 2020/9/29.
//
#include "common.h"

int main(){
  std::vector<unsigned> v(10, 2);
  std::cout << v << std::endl;

  auto func = [](unsigned i) -> std::size_t { return 1; };
  std::transform(v.begin(), v.end(), v.begin(), func);
  std::cout << v << std::endl;

  return 0;
}