//
// Created by mqye on 2020/11/3.
//

#include "random.h"

std::vector<float> normal(const int nrolls, const float mean, const float stddev) {
  std::default_random_engine generator;
  std::normal_distribution<float> distribution(mean, stddev);

  std::vector<float> vec;
  for (int i = 0; i < nrolls; ++i) {
    float number = distribution(generator);
    vec.push_back((float) number);
  }
  return vec;
}