#pragma once
#include <vector>
#include "point.h"
#include "obstacle.h"

// positive direction: up and right

struct Space
{
  int id;
  unsigned int width;
  unsigned int height;

  Point start;
  Point end;

  std::vector<Point> points;
  std::vector<Obstacle> obstacles;

  std::string serialize();

  static Space deserialize(std::string str);
};