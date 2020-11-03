//
// Created by mqye on 2020/11/3.
//

#ifndef PYTHON_BRKGA_PRINT_H
#define PYTHON_BRKGA_PRINT_H

#include "iostream"
#include "vector"

namespace utils {
  template<class Iter>
  inline void PrintSequence(std::ostream &out, Iter begin, Iter end) {
    // Output at most 100 elements -- appropriate if used for logging.
    for (int i = 0; begin != end && i < 100; ++i, ++begin) {
      if (i > 0)
        out << ' ';
      out << *begin;
    }
    if (begin != end) {
      out << " ...";
    }
    else
    {
      out << std::endl;
    }
  }
}

namespace std {
#define INSTANTIATE_FOR_CONTAINER(container)               \
  template <class... Types>                                \
  std::ostream& operator<<(                                \
      std::ostream& out, const container<Types...>& seq) { \
    utils::PrintSequence(out, seq.begin(), seq.end());     \
    return out;                                            \
  }

  INSTANTIATE_FOR_CONTAINER(std::vector)

#define INSTANTIATE_FOR_PAIR(container)                    \
  template <class... Types>                                \
  std::ostream& operator<<(                                \
      std::ostream& out, const container<Types...>& p) {   \
    out << p.first << ' ' << p.second << std::endl;        \
    return out;                                            \
  }
  INSTANTIATE_FOR_PAIR(std::pair)
}

#endif //PYTHON_BRKGA_PRINT_H
