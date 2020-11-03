//
// Created by mqye on 2020/9/24.
//

#ifndef BRKGA_MP_IPR_UTILS_H
#define BRKGA_MP_IPR_UTILS_H

#include "common.h"

void print(cv::Mat mat, int prec);

void print_format(cv::Mat mat, int prec);

torch::Tensor toTensor(cv::Mat &img); // img must be CV_32F
#endif //BRKGA_MP_IPR_UTILS_H
