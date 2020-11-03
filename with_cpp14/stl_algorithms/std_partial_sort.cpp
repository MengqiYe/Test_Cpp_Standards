//
// Created by mqye on 2020/10/1.
//
#include "common.h"

bool myfunction(int i, int j) { return (i < j); }

int main() {
  int myints[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  std::vector<int> myvector(myints, myints + 9);
  std::cout << myvector << std::endl;

  // using default comparison (operator <):
  std::partial_sort(myvector.begin(), myvector.begin() + 5, myvector.end());
  std::cout << myvector << std::endl;

  // using function as comp
  std::partial_sort(myvector.begin(), myvector.begin() + 5, myvector.end(), myfunction);
  std::cout << myvector << std::endl;

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}