#pragma once

#include "point.h"

struct Edge
{
  Point a;
  Point b;

  std::string serialize();

  static Edge deserialize(std::string str);
};