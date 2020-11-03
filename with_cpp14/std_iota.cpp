//
// Created by mqye on 2020/9/29.
//

#include "common.h"

int main(){

  std::vector<unsigned> v(10);

  std::iota(v.begin(), v.end(), 0);

  std::cout << v << std::endl;

  return 0;
}