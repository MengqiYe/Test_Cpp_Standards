//
// Created by mqye on 2020/9/29.
//

# include "common.h"

#include <iostream>
#include <string>
#include <random>

int main() {
  std::mt19937 rng(0);
  double mean = std::generate_canonical<double, std::numeric_limits<double>::digits>(rng);
  double stddev = std::generate_canonical<double, std::numeric_limits<double>::digits>(rng);
  std::cout << boost::format("mean : %f, stddev : %f") % mean % stddev << std::endl;

  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mean, stddev);

  const int try_count = 50;
  const int vec_size = 100;
  const int nrolls = 1000;  // number of experiments
  const int nstars = 100;    // maximum number of stars to distribute

  int records[try_count][vec_size] = {};
  for (int i = 0; i < try_count; ++i) {
    for (int j = 0; j < vec_size; ++j) {
      double number = distribution(generator);
      records[i][j] = number;
    }
  }

  for (int j = 0; j < vec_size; ++j) {
    std::cout << boost::format("id : %d, values : ") % j;
    for (int i = 0; i < try_count; ++i) {
      std::cout << records[i][j] << ' ';
    }
    std::cout << std::endl;
  }


  return 0;
}