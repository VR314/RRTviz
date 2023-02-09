#include <iostream>
#include <fstream>
#include <string>

#include "point.h"
#include "space.h"

// TODO:
//  - Serialization/Deserialization and File I/O
//  - Refine graph structure
//  - Throw together a mini testing framework (learn callback functions, assertions and cerr, etc.)

void testObstacleSerializationAndDeserialization()
{
  std::string s = "OBS 100 3 1 2 3 1 2 1";
  Obstacle o(s);
  assert(s == o.serialize());
  std::cout << "Serialization & Deserialization for Obstacles works!" << std::endl;
}

void runAllTests()
{
  testObstacleSerializationAndDeserialization();
}

int main()
{
  FILE *file = fopen("../common/input.txt", "r");

  std::cout << "This is a test C++ file" << std::endl;
  Point start{3, 4};
  Point end{4, 5};
  Space s{100, 10, 10, start, end};
  std::cout << s.start.x << ", " << s.start.y << std::endl;
  return 0;
}