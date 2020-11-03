//
// Created by mqye on 2020/9/30.
//

#include "common.h"

int main() {
  std::vector<float> heap({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
  std::vector<float> heap_squashed({9, 8, 6, 7, 4, 5, 2, 0, 3, 1});

  std::cout << "Initial vector : " << heap << std::endl;
  std::cout << "Squashed heap like vector : " << heap_squashed << std::endl;
  std::make_heap(begin(heap), end(heap));
  std::cout << "Made heap : " << heap << std::endl;

  heap.push_back(8.1);
  std::cout << "Current heap : " << heap << std::endl;
  std::push_heap(begin(heap), end(heap));
  std::cout << "Current heap : " << heap << std::endl;

  std::pop_heap(begin(heap), end(heap));
  std::cout << "Current heap : " << heap << std::endl;

  heap.pop_back();
  std::cout << "Current heap : " << heap << std::endl;


  return 0;
}