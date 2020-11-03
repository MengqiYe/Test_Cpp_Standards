//
// Created by mqye on 2020/10/4.
//

#include <iostream>
#include <string>

int main()
{
  const int MAX_AGE = 80;
  int* a = new int;
//  int* const a = new int;

  *a = 2;
  a = (int*)&MAX_AGE;
  std::cout << *a << std::endl;

}
