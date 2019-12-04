/*
 * @Descripttion:define Point to store place's informtion
 * @version: 1.0
 * @Author: Kaixin Lin
 */
#ifndef POINT_HPP
#define POINT_HPP
#include <climits>
#include <string>
#include <vector>
#include "edge.hpp"
using namespace std;
class edge;
/**
 * @name: point
 * @msg:  the class of point for A* search
 */
class point {
  public:
    string name;
    int x;
    int y;

    vector<edge> edges;
    point* prePoint;
    int dis;
    bool isDone;
    double f, h;
    /* Constructor that initialize a point */
    point(string name, int x, int y)
        : name(name), x(x), y(y), f(0), dis(INT_MAX) {}
};
/* Comparator of Point for A* search.In priority queue,
 * Edge with less h function value has higher priority
 */
struct pointComp {
    bool operator()(point*& lhs, point*& rhs) const { return lhs->f > rhs->f; }
};
#endif  // POINT_HPP
