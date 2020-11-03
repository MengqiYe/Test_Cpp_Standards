//
// Created by mqye on 2020/10/1.
//

#include "common.h"

bool myfunction(int i, int j) { return (i < j); }

int main() {
  std::vector<int> myvector;

  // set some values:
  for (int i = 1; i < 10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9
  std::cout << myvector << std::endl;

  std::random_shuffle(myvector.begin(), myvector.end());
  std::cout << myvector << std::endl;

  // using default comparison (operator <):
  std::nth_element(myvector.begin(), myvector.begin() + 5, myvector.end());
  std::cout << myvector << std::endl;

  // using function as comp
  std::nth_element(myvector.begin(), myvector.begin() + 5, myvector.end(), myfunction);
  std::cout << myvector << std::endl;

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}