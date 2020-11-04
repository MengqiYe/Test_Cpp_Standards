//
// Created by mqye on 2020/11/4.
//
#include <limits>
#include <iostream>
#include <boost/format.hpp>
#include "utils.h"

bool hasNaN(std::vector<float> &vec){
  for (int i = 0; i < vec.size(); ++i) {
    if(vec[i] != vec[i]){
      return true;
    }
  }
  return false;
}

bool hasInf(std::vector<float> &vec){
  for (int i = 0; i < vec.size(); ++i) {
    if (vec[i] == std::numeric_limits<float>::infinity() |
    vec[i] == -std::numeric_limits<float>::infinity()){
      return true;
    }
  }
  return false;
}

int main() {
  float max = std::numeric_limits<float>::max();
  float min = std::numeric_limits<float>::min();
  float quiet_nan = std::numeric_limits<float>::quiet_NaN();
  float signaling_nan = std::numeric_limits<float>::signaling_NaN();
  std::cout << boost::format("max : %f") % max << ' ' << max << std::endl
            << boost::format("min : %f") % min << ' ' << min << std::endl
            << boost::format("quiet_nan : %f") % quiet_nan << ' ' << quiet_nan << std::endl
            << boost::format("signaling_nan : %f") % signaling_nan << ' ' << signaling_nan << std::endl
            << std::endl;


  std::vector<float> vec = {
    .1, .2, .3, quiet_nan, .5, signaling_nan, .6
  };

  std::cout << vec << std::endl << hasNaN(vec) << std::endl << hasInf(vec);

  return 0;
}