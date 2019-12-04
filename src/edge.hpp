/*
 * @Descripttion:define Edge to store connect point
 * @version: 1.0
 * @Author: Kaixin Lin
 */
#ifndef EDGE_HPP
#define EDGE_HPP
#include <string>
#include "point.hpp"
using namespace std;
class point;
/**
 * @name: edge
 * @msg:  the class of edge for A* search
 */
class edge {
  public:
  /* Constructor that initialize a edge */
    edge(point* p1, point* p2, unsigned int distance)
        : p1(p1), p2(p2), distance(distance) {}

    point* p1;
    point* p2;
    double distance;
};

#endif  // EDGE_HPP