//
// Created by mqye on 2020/9/29.
//

#include "common.h"
#include "matplotlibcpp.h"
#include <vector>

namespace plt = matplotlibcpp;

int main() {
  std::vector<double> y = {1, 3, 2, 4};
  plt::plot(y);
  plt::savefig("minimal.pdf");
  plt::show();
}