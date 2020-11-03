//
// Created by mqye on 2020/10/4.
//
#include <stdio.h>
#include <string>

// This is nontype parameter
template<unsigned N, unsigned M>
int compare(const char (&p1)[N], const char(&p2)[M]) {
  return strcmp(p1, p2);
}

int main(){
  compare("Hello", "World");
}
