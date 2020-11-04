//
// Created by mqye on 2020/11/3.
//

#include "random.h"

void normal(std::vector<float> &vec, const int nrolls, const float mean, const float stddev) {
  std::default_random_engine generator;
  std::normal_distribution<float> distribution(mean, stddev);

  for (int i = 0; i < nrolls; ++i) {
    float number = distribution(generator);
    vec.push_back((float) number);
  }
}