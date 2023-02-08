#include <iostream>
#include <string>

#include "point.h"
#include "space.h"

// TODO:
//  - Serialization/Deserialization and File I/O
//  - Refine graph structure

int main()
{
  std::cout << "This is a test C++ file" << std::endl;
  Point start{3, 4};
  Point end{4, 5};
  Space s{10, 10, start, end};
  std::cout << s.start.x << ", " << s.start.y << std::endl;
  return 0;
}