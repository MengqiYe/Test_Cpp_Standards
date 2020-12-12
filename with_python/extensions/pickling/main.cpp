//
// Created by mqye on 2020/12/7.
//

#include "p.h"

namespace py = pybind11;

int main() {
  std::vector<float> float_vector;
  float_vector.push_back(.1);
  float_vector.push_back(.2);
  float_vector.push_back(.3);

  auto a_tuple = py::make_tuple(float_vector);

}