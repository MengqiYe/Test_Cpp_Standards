//
// Created by mqye on 2020/10/1.
//
#include "common.h"
#include "boost/format.hpp"

int main() {
  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};
  std::vector<int> v(10);
  std::vector<int>::iterator it;

  std::sort(first, first + 5);
  std::sort(second, second + 5);

  std::vector<int> v_first({5, 10, 15, 20, 25});
  std::vector<int> v_second({50, 40, 30, 20, 10});

  std::cout << boost::format("first vector : %d, second vector : %d") % v_first % v_second << std::endl;

  it = std::copy(first, first + 5, v.begin());
  std::copy(second, second + 5, it);

  std::inplace_merge(v.begin(), v.begin() + 5, v.end());

  std::cout << "The resulting vector contains:";
  for (it = v.begin(); it != v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}