/**
 * @file functions.hpp
 * @author Daniel Rahme
 * @date 2019-04-29
 * @brief Library with function(s).
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

namespace func
{
  // Function declarations
  unsigned int square(const int x);

  // Templates
  template<typename T>
  void print_hello(T name)
  {
    std::cout << "Hello " << name << "!\n";
  }
}

#endif
