/*
 * @Descripttion:define city to acheieve A* search
 * @version: 1.0
 * @Author: Kaixin Lin
 */
#include "city.hpp"
#include <math.h>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include "city.hpp"
#include "edge.hpp"
#include "point.hpp"
using namespace std;
#define c 1  // weight c of heuristic value

/**
 * @name:   calDistance
 * @brief:  get Euclidean Distance for A* search in given point
 */
double city::calDistance(point* p1, point* p2) {
    double result = 0;
    result = pow(p1->x - p2->x, 2.0) + pow(p1->y - p2->y, 2.0);
    result = sqrt(result);
    return result;
}

/**
 * @name:   aStarSearch
 * @brief:  use A* search to find the shortest path from source to target
 */
void city::aStarSearch(string source, string target) {
    if (points.find(source) == points.end() ||
        points.find(target) == points.end())
        return;
    // get root node and target node
    point* src = points.find(source)->second;
    point* dst = points.find(target)->second;

    priority_queue<point*, vector<point*>, pointComp> Toexplore;
    stack<point*> temp;
    // update root
    src->f = calDistance(src, dst);
    src->dis = 0;
    bool Found = false;
    // update the h value for all the points
    for (auto it : points) {
        it.second->h = c * calDistance(it.second, dst);
    }
    src->f = src->h;
    Toexplore.push(src);
    while (!Toexplore.empty()) {
        point* curPoint = Toexplore.top();
        Toexplore.pop();
        // find the target
        if (curPoint == dst) {
            Found = true;
            break;
        }

        if (!curPoint->isDone) {
            curPoint->isDone = true;
            // all the neighbor
            for (edge e : curPoint->edges) {
                point* another = (curPoint == e.p1) ? e.p2 : e.p1;
                unsigned int distance = e.distance + curPoint->dis;
                if (distance < another->dis) {
                    another->prePoint = curPoint;
                    another->dis = distance;
                    another->f = distance + another->h;
                    Toexplore.push(another);
                }
            }
        }
    }
    // get the result
    if (Found == true) {
        point* prev = dst;
        while (prev != src) {
            temp.push(prev);
            prev = prev->prePoint;
        }
    }
    vector<point*> vector_result;
    vector_result.push_back(src);
    while (!temp.empty()) {
        vector_result.push_back(temp.top());
        temp.pop();
    }
    results.push_back(vector_result);
}
/**
 * @name:   clear
 * @brief:  clear all the variable for next A* search
 */
void city::clear() {
    for (auto it : points) {
        it.second->h = INT_MAX;
        it.second->dis = INT_MAX;
        it.second->isDone = false;
        it.second->f = INT_MAX;
        it.second->prePoint = nullptr;
    }
}
/* deconstructor for city */
city::~city() {
    for (auto i = points.begin(); i != points.end(); ++i) {
        delete (i->second);
    }
}