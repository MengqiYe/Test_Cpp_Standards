//
// Created by mqye on 2020/11/3.
//

#include "random.h"

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<float, std::allocator<float>>);
PYBIND11_MAKE_OPAQUE(
  std::vector<std::vector<float, std::allocator<float>>,
    std::allocator<std::vector<float, std::allocator<float>>>>
);

PYBIND11_MODULE(stl, m) {

  m.doc() = "stl python plugin";

  m.def("normal", &normal, "vec", "nrolls", "mean", "stddev");

}