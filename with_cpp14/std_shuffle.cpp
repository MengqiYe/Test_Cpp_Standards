//
// Created by mqye on 2020/9/29.
//
#include "common.h"

//template <class RandomAccessIterator, class URNG>
//void shuffle (RandomAccessIterator first, RandomAccessIterator last, URNG&& g)
//{
//  for (auto i=(last-first)-1; i>0; --i) {
//    std::uniform_int_distribution<decltype(i)> d(0,i);
//    swap (first[i], first[d(g)]);
//  }
//}

// shuffle algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

int main () {
  std::array<int,5> foo {1,2,3,4,5};

  // obtain a time-based seed:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

  shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));

  std::cout << "shuffled elements:";
  for (int& x: foo) std::cout << ' ' << x;
  std::cout << '\n';

  return 0;
}