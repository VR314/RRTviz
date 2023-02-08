#pragma once
#include <vector>
#include "point.h"
#include "obstacle.h"
// TODO: implement graph data structure (model as adjacency list? adjacency matrix? pointers inside Points?)
// positive direction: up and right

struct Space
{
  int width;
  int height;

  Point start;
  Point end;

  std::vector<Point> points;
  std::vector<Obstacle> obstacles;

  std::string serialize();

  static Space deserialize(std::string str);
};