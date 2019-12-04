/*
 * @Descripttion:define city to acheieve A* search
 * @version: 1.0
 * @Author: Kaixin Lin
 */
#ifndef CITY_HPP
#define CITY_HPP
#include <string>
#include <unordered_map>
#include <vector>
#include "edge.hpp"
#include "point.hpp"
using namespace std;
/**
 * @name: edge
 * @msg:  the class of city for A* search and store all the points and result
 */
class city {
  public:
    unordered_map<string, point*> points;
    vector<vector<point*>> results;
    /**
     * @name:   calDistance
     * @brief:  get Euclidean Distance for A* search in given point
     */
    double calDistance(point* p1, point* p2);

    /**
     * @name:   aStarSearch
     * @brief:  use A* search to find the shortest path from source to target
     */
    void aStarSearch(string source, string target);

    /**
     * @name:   clear
     * @brief:  clear all the variable for next A* search
     */
    void clear();
};
#endif  // CITY_HPP