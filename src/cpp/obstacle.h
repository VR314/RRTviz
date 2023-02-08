#pragma once

#include "point.h"

// TODO: expand from rectangles to n-sided polygons
struct Obstacle
{
  Point top_left;
  Point bottom_right;

  bool isPointInObstacle(Point p);

  std::string serialize();

  static Obstacle deserialize(std::string str);
};