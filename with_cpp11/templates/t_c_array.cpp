//
// Created by mqye on 2020/10/4.
//
#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
private:
  T m_Array[N];
public:
  int GetSize() const { return N; }
};

int main(){
  Array<std::string, 5> array;
  std::cout << array.GetSize() << std::endl;
}