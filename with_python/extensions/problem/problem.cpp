//
// Created by mqye on 2020/11/12.
//

#include <pybind11/pybind11.h>
#include <pybind11/stl_bind.h>
#include <pybind11/stl.h>
#include "problem.h"
#include <string>

namespace py = pybind11;

PYBIND11_MODULE(problem, m) {
  py::class_<Pet>(m, "Pet")
    .def(py::init<std::string, std::string>())
    .def("name", &Pet::name)
    .def("species", &Pet::species);

  py::class_<Pet_Decoder>(m, "Pet_Decoder")
    .def(py::init<const Pet &>())
    .def("name", &Pet_Decoder::pet)
    .def("decode", &Pet_Decoder::decode);
}