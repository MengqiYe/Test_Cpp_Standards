//
// Created by mqye on 2020/12/7.
//

#include <iostream>
#include "p.h"

namespace py = pybind11;

typedef std::pair<float, float> ChromosomeParam;
typedef std::vector<ChromosomeParam> ChromosomeParamVector;

PYBIND11_MAKE_OPAQUE(ChromosomeParam);
//PYBIND11_MAKE_OPAQUE(std::vector<std::pair<float, float>>);
PYBIND11_MAKE_OPAQUE(ChromosomeParamVector);
using Chromosome = std::vector<float, std::allocator<float>>;


void PrintChromosomeParamVector(const ChromosomeParamVector &vec) {
  for (int i = 0; i < vec.size(); ++i) {
    std::cout << vec[i].first << ' ' << vec[i].second << std::endl;
  }
}

PYBIND11_MODULE(pickling, m) {

  m.doc() = "pickling python plugin";

  py::bind_vector<Chromosome>(m, "Chromosome")
    .def(py::pickle(
      [](const Chromosome &p) {
        return py::make_tuple(p);
      },
      [](py::tuple t) {
        return Chromosome();
      }
    ));
  py::bind_vector<std::vector<Chromosome>>(m, "ChromosomeVector")
    .def(py::pickle(
      [](const std::vector<Chromosome> &p) {
        return py::make_tuple(p);
      },
      [](py::tuple t) {
        return Chromosome();
      }
    ));

  py::class_<ChromosomeParam>(m, "ChromosomeParam")
    .def(py::init<>())
    .def(py::init<float, float>())
    .def_readonly("first", &ChromosomeParam::first)
    .def_readonly("second", &ChromosomeParam::second)
    .def(py::pickle(
      [](const ChromosomeParam &p) {
        return py::make_tuple(p.first, p.second);
      },
      [](py::tuple t) {
        if (t.size() != 2)
          throw std::runtime_error("Invalid state!");
        return ChromosomeParam(t[0].cast<float>(), t[1].cast<float>());
      }
    ));

  py::bind_vector<std::vector<ChromosomeParam>>(m, "ChromosomeParamVector")
    .def(py::pickle(
      [](const std::vector<ChromosomeParam> &p) {
        return py::make_tuple(p);
      },
      [](py::tuple t) {
        if (t.size() != 2)
          throw std::runtime_error("Invalid state!");
        return std::vector<ChromosomeParam>();
      }
    ));

  m.def("PrintChromosomeParamVector", &PrintChromosomeParamVector, py::arg("chromosomes_param"));
}

