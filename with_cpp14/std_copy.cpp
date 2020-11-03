//
// Created by mqye on 2020/9/28.
//
#include "common.h"

template<class T>
void print_vector(std::vector<T> v) {
  for (typename std::vector<T>::const_iterator i = v.begin(); i != v.end(); ++i)
    std::cout << *i << ' ';
  std::cout << std::endl;
}

int main() {
  std::vector<double> v1(10, 1);
  std::vector<double> v2(10, 2);

  std::cout << v1 << std::endl << v2 << std::endl;
  std::copy(v1.begin(), v1.end(), v2.begin());
//  std::cout << v1 << std::endl << v2 << std::endl;

  print_vector(v1);
  print_vector(v2);

  return 0;
}
