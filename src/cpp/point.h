#pragma once
#include <string>
#include <vector>

struct Point
{
  int id;
  unsigned int x;
  unsigned int y;
  Point *parent;
  std::vector<Point *> children;

  std::string serialize();

  static Point deserialize(std::string str);
};
