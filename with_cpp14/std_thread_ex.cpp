//
// Created by mqye on 2020/11/3.
//

// compile with:
//   g++ -g -std=c++11 sigsegv.cc -o sigsegv -pthread
#include <thread>
#include <vector>
#include <iostream>

void foo() {
  std::vector<int> v;
  std::cout << v.at(100) << std::endl;
}

int main() {
  std::thread t(foo);
  t.join();
}