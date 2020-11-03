//
// Created by mqye on 2020/10/4.
//

#include <iostream>

template<typename T>
class Bucky {
  T first, second;
public:
  Bucky(T a, T b) {
    first = a;
    second = b;
  }

  T bigger();

};

template<typename T>
T Bucky<T>::bigger(){}

int main() {

}