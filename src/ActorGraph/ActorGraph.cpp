/*
 * ActorGraph.cpp
 * Author: Kaixin Lin
 * Date:   2019.11.27
 *
 * This file is meant to exist as a container for starter code that you can use
 * to read the input file format defined in imdb_2019.tsv. Feel free to modify
 * any/all aspects as you wish.
 */

#include "ActorGraph.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "city.hpp"
#include "edge.hpp"
#include "point.hpp"
using namespace std;

/**
 * Constructor of the Actor graph
 */
ActorGraph::ActorGraph(void) {}

/**
 * @name:   loadFromXYFile
 * @brief:  Load the graph from a given file of points
 */
bool ActorGraph::loadFromXYFile(const char* in_filename, city& c) {
    // Initialize the file stream
    ifstream infile(in_filename);

    // keep reading lines until the end of file is reached
    while (infile) {
        string s;
        // get the next line
        if (!getline(infile, s)) break;
        istringstream ss(s);
        vector<string> record;
        while (ss) {
            string str;

            // get the next string before hitting a tab character and put it in
            // 'str'
            if (!getline(ss, str, ' ')) break;
            record.push_back(str);
        }

        if (record.size() != 3) {
            // we should have exactly 3 columns
            continue;
        }

        string name(record[0]);
        int x = stoi(record[1]);
        int y = stoi(record[2]);
        if (c.points.find(name) == c.points.end()) {
            point* p = new point(name, x, y);
            c.points.insert(make_pair(name, p));
        }
        point* curPoint = c.points.find(name)->second;
    }
    if (!infile.eof()) {
        cerr << "Failed to read " << in_filename << "!\n";
        return false;
    }
    infile.close();

    return true;
}

/**
 * @name:   loadFromPairFile
 * @brief:  Load the graph from a given file of edges
 */
bool ActorGraph::loadFromPairFile(const char* in_filename,
                                  city& c) {  // Initialize the file stream
    ifstream infile(in_filename);

    // keep reading lines until the end of file is reached
    while (infile) {
        string s;
        // get the next line
        if (!getline(infile, s)) break;
        istringstream ss(s);
        vector<string> record;
        while (ss) {
            string str;

            // get the next string before hitting a tab character and put it in
            // 'str'
            if (!getline(ss, str, ' ')) break;
            record.push_back(str);
        }

        if (record.size() != 2) {
            // we should have exactly 2 columns
            continue;
        }

        string p1(record[0]);
        string p2(record[1]);
        point* curP1 = c.points.find(p1)->second;
        point* curP2 = c.points.find(p2)->second;

        double dis = c.calDistance(curP1, curP2);

        edge e(curP1, curP2, dis);

        curP1->edges.push_back(e);
        curP2->edges.push_back(e);
    }
    if (!infile.eof()) {
        cerr << "Failed to read " << in_filename << "!\n";
        return false;
    }
    infile.close();

    return true;
}

/**
 * @name:   readFile
 * @brief:  read input file from filename
 */
bool ActorGraph::readFile(const char* filename) {
    ifstream infile(filename);
    while (infile) {
        string s;
        // get the next line
        if (!getline(infile, s)) break;

        istringstream ss(s);
        vector<string> record;
        while (ss) {
            string str;
            // get the next string before hitting a tab character and put it in
            // 'str'
            if (!getline(ss, str, ' ')) break;
            record.push_back(str);
        }

        if (record.size() != 2) {
            // we should have exactly 2 columns
            continue;
        }
        string city1(record[0]);
        string city2(record[1]);
        input.push_back(make_pair(city1, city2));
    }
    if (!infile.eof()) {
        cerr << "Failed to read " << filename << "!\n";
        return false;
    }
    infile.close();

    return true;
}

/**
 * @name:   writeFile
 * @brief: write result to the given file
 */
void ActorGraph::writeFile(string filename, vector<vector<point*>>& result) {
    ofstream out;
    out.open(filename, ios::binary);
    for (auto it : result) {
        for (int i = 0; i < it.size(); i++) {
            out << "(" << it[i]->name << ")";
            if (i != it.size() - 1) out << "-->";
        }
        out << endl;
    }
    out.close();
}