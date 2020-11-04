//
// Created by mqye on 2020/11/3.
//

#ifndef TEST_CPP_STANDARDS_STL_H
#define TEST_CPP_STANDARDS_STL_H
#include <iostream>
#include <algorithm>
#include <random>
#include "print.h"

void normal(std::vector<float> &vec, const int nrolls, const float mean, const float stddev);

void shuffle(std::vector<float> &vec, const int nrolls, const float mean, const float stddev);

#endif //TEST_CPP_STANDARDS_STL_H
