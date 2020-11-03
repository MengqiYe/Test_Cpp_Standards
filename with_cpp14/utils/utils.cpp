//
// Created by mqye on 2020/9/25.
//

#include "utils.h"
#include "boost/format.hpp"
#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc.hpp>

torch::Tensor toTensor(cv::Mat &img) // img must be CV_32F
{
  at::Tensor img_t = torch::empty({1, img.rows, img.cols, img.channels()});
  //stride=width*channels
  memcpy(img_t.data_ptr(), img.data, img_t.numel() * sizeof(float));
  //上述步骤，tensor的排列是{1,224,224,3}，是batch,w,h,channel
  //我们要重新排列成{1,3,224,224}，即batch,channel,w,h
  img_t = img_t.permute({0, 3, 1, 2});
  return img_t.clone();
};