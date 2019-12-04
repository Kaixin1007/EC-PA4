/*
 * ActorGraph.cpp
 * Author: Kaixin Lin
 * Date:   2019.11.27
 *
 * This file is meant to exist as a container for starter code that you can use
 * to read the input file format defined in imdb_2019.tsv. Feel free to modify
 * any/all aspects as you wish.
 */

#ifndef ACTORGRAPH_HPP
#define ACTORGRAPH_HPP
#include <iostream>
#include "city.hpp"
#include "edge.hpp"
#include "point.hpp"

// Maybe include some data structures here

using namespace std;

/**
 * TODO: add class header
 */
class ActorGraph {
  protected:
    // Maybe add class data structure(s) here

  public:
    vector<pair<string, string>> input;
    /**
     * Constuctor of the Actor graph
     */
    ActorGraph(void);

    /**
     * @name:   loadFromXYFile
     * @brief:  Load the graph from a given file of points
     */
    bool loadFromXYFile(const char* in_filename, city& c);

    /**
     * @name:   loadFromPairFile
     * @brief:  Load the graph from a given file of edges
     */
    bool loadFromPairFile(const char* in_filename, city& c);
    /**
     * @name:   readFile
     * @brief:  read input file from filename
     */
    bool readFile(const char*  filename);
    /**
     * @name:   writeFile
     * @brief: write result to the given file
     */
    void writeFile(string filename, vector<vector<point*>>& result);
};

#endif  // ACTORGRAPH_HPP
