//
// Created by mqye on 2020/9/29.
//

#include "common.h"
#include "matplotlibcpp.h"
#include <random>

template<typename T>
void normal(std::vector<T> &vec, const int nrolls, const float mean, const float stddev) {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(5.0, 2.0);

  for (int i = 0; i < nrolls; ++i) {
    double number = distribution(generator);
    vec.push_back((T) number);
  }
}

namespace plt = matplotlibcpp;

int main() {
  const int nrolls = 100;  // number of experiments
  const int nstars = 100;    // maximum number of stars to distribute
  const float mu = 5.0;
  const float sigma = 2.0;
  const float pi = 3.14;

  std::vector<int> vec;
  normal(vec, nrolls, mu, sigma);

  std::cout << "normal_distribution (5.0,2.0):" << std::endl;
  std::cout << vec << std::endl;

  plt::hist(vec, 10);

  std::vector<int> bins(10);
  std::iota(begin(bins), end(bins), 0);
  std::vector<int> counts(10, 0);
  std::vector<int>::const_iterator pos;
  for (pos = vec.begin(); pos != vec.end(); ++pos) {
    counts[*pos]++;
  }
  int max_count = *std::max_element(begin(counts), end(counts));
  std::cout << boost::format("max_count : %d ") % max_count << std::endl;
  std::vector<float> vec_y(bins.size());
//  plot(bins, 1 / (sigma * np.sqrt(2 * np.pi)) * np.exp(- (bins - mu) ** 2 / (2 * sigma ** 2)), linewidth=2, color='r')
  auto func = [pi, mu, sigma, max_count](int x) -> float {
    float p1 = -std::pow(((float) x - mu), 2);
    float p2 = 2 * std::pow(sigma, 2);
    float p3 = (sigma * std::sqrt(2 * pi));
    float rst = 1 / p3 * std::exp(p1 / p2) * max_count * 5;
//    std::cout << boost::format("p1 : %f, p2 : %f, p3 : %f, rst : %f ") % p1 % p2 % p3 % rst << std::endl;
    return rst;
  };
  std::transform(bins.begin(), bins.end(), vec_y.begin(), func);

  std::cout << "Bins :" << bins << std::endl;
  std::cout << "Counts :" << counts << std::endl;
  std::cout << "Y :" << vec_y << std::endl;

  plt::plot(bins, vec_y, "r");
  plt::show();

  return 0;
}