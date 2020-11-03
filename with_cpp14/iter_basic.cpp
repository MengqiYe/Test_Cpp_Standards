//
// Created by mqye on 2020/9/27.
//
#include "torch/script.h"
#include <ATen/native/TensorIterator.h>

using namespace torch;

int main() {
  TensorIteratorConfig config;

  float data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  torch::Tensor temp_input_tensor = torch::from_blob(data, {3, 3}, torch::kFloat32);

  torch::TensorOptions output_option;
  torch::Tensor temp_output_tensor = torch::zeros({3, 3}, torch::kFloat32);

  config.add_output(temp_output_tensor);
  config.add_input(temp_input_tensor);
  config.resize_outputs(false);
  config.promote_inputs_to_common_dtype(true);

  TensorIterator iter = TensorIterator(config);

  auto loop = [&](char **data, const int64_t *strides, int64_t n) {
    auto *out_data_bytes = data[0];
    auto *in_data_bytes = data[1];

    // assume float data type for this example.
    for (int i = 0; i < n; i++) {
      *reinterpret_cast<float *>(out_data_bytes) = *reinterpret_cast<float *>(in_data_bytes) * 2;

      float float_in = *reinterpret_cast<float *>(in_data_bytes);
      float float_out = *reinterpret_cast<float *>(out_data_bytes);

      std::cout << float_in << std::endl;
      std::cout << float_out << std::endl ;

      out_data_bytes += strides[0];
      in_data_bytes += strides[1];
    }
  };

// loop_t = c10::function_ref<void(char** data, const int64_t* strides, int64_t size)>;
// loop2d_t = c10::function_ref<void(char** data, const int64_t* strides, int64_t size0, int64_t size1)>;
  iter.for_each(loop, 32768);
}