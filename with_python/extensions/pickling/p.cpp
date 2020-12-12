//
// Created by mqye on 2020/12/7.
//

#include <iostream>
#include "p.h"

namespace py = pybind11;

typedef std::pair<float, float> TParam;
typedef std::vector<TParam>     TParamVector;

PYBIND11_MAKE_OPAQUE(TParam);
//PYBIND11_MAKE_OPAQUE(std::vector<std::pair<float, float>>);
PYBIND11_MAKE_OPAQUE(TParamVector);
using AVec = std::vector<float, std::allocator<float>>;


void PrintTParamVec(const TParamVector &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i].first << ' ' << vec[i].second << std::endl;
    }
}

PYBIND11_MODULE(pickling, m) {

    m.doc() = "pickling python plugin";

    py::bind_vector<AVec>(m, "AVec");
//    .def(py::pickle(
//      [](const AVec &p) {
//        return py::make_tuple(p);
//      },
//      [](py::tuple t) {
//        return AVec();
//      }
//    ));

    py::bind_vector<std::vector<AVec>>(m, "AVecVec");
//    .def(py::pickle(
//      [](const std::vector<AVec> &p) {
//        return py::make_tuple(p);
//      },
//      [](py::tuple t) {
//        return AVec();
//      }
//    ));

    py::class_<TParam>(m, "Param")
        .def(py::init<>())
        .def(py::init<float, float>())
        .def_readonly("first", &TParam::first)
        .def_readonly("second", &TParam::second)
        .def(py::pickle(
            [](const TParam &p) {
                return py::make_tuple(p.first, p.second);
            },
            [](py::tuple t) {
                if (t.size() != 2)
                    throw std::runtime_error("Invalid state!");
                return TParam(t[0].cast<float>(), t[1].cast<float>());
            }
        ));

    py::bind_vector<std::vector<TParam>>(m, "TParamVec")
        .def(py::pickle(
            [](const std::vector<TParam> &p) {
                return py::make_tuple(p);
            },
            [](py::tuple t) {
                if (t.size() != 2)
                    throw std::runtime_error("Invalid state!");
                return std::vector<TParam>();
            }
        ));

    m.def("PrintTParamVec", &PrintTParamVec, py::arg("param"));
}

