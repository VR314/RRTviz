#pragma once
#include <string>
#include <vector>

struct Point
{
  int x;
  int y;

  std::string serialize();

  static Point deserialize(std::string str);
};
