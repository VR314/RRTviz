#pragma once

#include "point.h"
#include <vector>
#include <sstream>
#include <assert.h>

class Obstacle
{
public:
  int id;
  std::vector<Point> points;

  /// @brief Deserialization constructor /
  /// FORMAT: "OBS <int: id> <int: num_points> <int x1> <int x2> ... <int x_n> <int y1> <int y2> ... <int y_n>"
  /// @param str
  Obstacle(std::string str)
  {
    std::stringstream ss(str);

    std::string type;
    ss >> type;
    assert(type == "OBS");

    int num_points;
    ss >> id;
    ss >> num_points;
    assert(num_points >= 3); // not a polygon if < 3

    for (int i = 0; i < num_points; i++)
    {
      unsigned int temp;
      ss >> temp;
      x_vals.push_back(temp);
    }

    for (int i = 0; i < num_points; i++)
    {
      unsigned int temp;
      ss >> temp;
      y_vals.push_back(temp);
    }

    for (int i = 0; i < num_points; i++)
    {
      Point temp{x_vals[i], y_vals[i]};
      points.push_back(temp);
    }
  }

  std::string serialize()
  {
    std::stringstream ss;
    ss << "OBS " << id << " " << points.size() << " ";
    for (unsigned int &x : x_vals)
    {
      ss << x;
      ss << " ";
    }

    for (unsigned int &y : y_vals)
    {
      ss << y;
      ss << " ";
    }

    return ss.str();
  }

  bool isPointInObstacle(Point p);

private:
  /// helpful with pnpoly polygon testing: https://wrfranklin.org/Research/Short_Notes/pnpoly.html
  std::vector<unsigned int> x_vals, y_vals;
};