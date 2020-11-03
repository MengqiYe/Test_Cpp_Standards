//
// Created by mqye on 2020/9/28.
//

#ifndef TEST_CPP14_COMMON_H
#define TEST_CPP14_COMMON_H

#include <torch/torch.h>
#include <ATen/native/TensorIterator.h>
#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <vector>
#include <string>

void readMatImg(const char* filename, std::vector<cv::Mat>& img_t, int inputsize = 224);
void prepareImgTensor(std::vector<torch::Tensor>& img_tensor, std::vector<cv::Mat>& img_t, int index);
std::vector< std::tuple<int , float > > getInferenceResults(torch::Tensor& out_tensor);

#endif //TEST_CPP14_COMMON_H
