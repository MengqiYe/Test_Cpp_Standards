//
// Created by mqye on 2020/9/24.
//
#include "utils.h"

void print(cv::Mat mat, int prec) {
  for (int h = 0; h < mat.rows; ++h) {
    for (int w = 0; w < mat.cols; ++w) {
      std::cout << boost::format("hi : %d, wi : %d ") % h % w << "[";
      for (int c = 0; c < mat.channels(); ++c) {
        int index = h * mat.cols * mat.channels() + w * mat.channels() + c;
        std::cout << boost::format("%3d, ") % (int)(mat.data[index]);
        if (c == mat.channels() - 1){
          std::cout << "]" << std::endl;
        }
      }
    }
  }
}

void print_format(cv::Mat mat, int prec) {
  cv::Ptr<cv::Formatter> fmt = cv::Formatter::get(cv::Formatter::FMT_DEFAULT);
  fmt->set64fPrecision(prec);
  fmt->set32fPrecision(prec);
  std::cout << fmt->format(mat) << std::endl;
}

void print_tensor(torch::Tensor tensor){

}