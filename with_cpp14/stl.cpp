//
// Created by mqye on 2020/9/25.
//
#include <opencv2/opencv.hpp>
#include "torch/script.h"


void case_basic_reshape(){
  float data[] = {1, 2, 3, 4, 5, 6, 7};
  torch::Tensor temp_tensor = torch::from_blob(data, {2,3});
  std::cout << temp_tensor << std::endl;
}

void case_load_cvimg(const char* filename){
  auto img_ = cv::imread(filename, cv::IMREAD_COLOR);
  cv::Mat img(10, 10, CV_8UC3);
  cv::resize(img_, img, img.size(), 0, 0, cv::INTER_AREA);
  auto input_ = torch::tensor(at::ArrayRef<uint8_t>(img.data, img.rows * img.cols * 3)).view({img.rows, img.cols, 3});

  std::cout << input_ << std::endl;
}

int main(int argc, const char* argv[]) {
//  case_basic_reshape();
  case_load_cvimg(argv[1]);
}