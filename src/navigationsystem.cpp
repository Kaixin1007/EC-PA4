/*
 * @Descripttion: use A* algorithm to output shortest paths between pairs of
 * locations
 * @version: 1.0
 * @Author: Kaixin Lin
 */
#include <string>
#include <vector>
#include "ActorGraph.hpp"
#include "city.hpp"
#include "cxxopts.hpp"
#include "edge.hpp"
#include "point.hpp"
using namespace std;

/* Main program that runs the linkpredictor */
int main(int argc, char** argv) {
    cxxopts::Options options("./navigationsystem", "navigationsystem files");
    options.positional_help(
        "./source_file ./source_Pair_file ./path_to_input_file "
        "./path_to_output_file");
    string sourceFileName, sourceFilePairName, inFileName, outFileName;
    options.allow_unrecognised_options().add_options()(
        "source", "", cxxopts::value<string>(sourceFileName))(
        "source1", "", cxxopts::value<string>(sourceFilePairName))(
        "input", "", cxxopts::value<string>(inFileName))(
        "output", "", cxxopts::value<string>(outFileName));
    options.parse_positional({"source", "source1", "input", "output"});
    auto userOptions = options.parse(argc, argv);
    ActorGraph ag;
    city c;
    // load file
    ag.loadFromXYFile(sourceFileName.c_str(), c);
    ag.loadFromPairFile(sourceFilePairName.c_str(), c);
    ag.readFile(inFileName.c_str());
    // use A* search
    for (auto it : ag.input) {
        c.aStarSearch(it.first, it.second);
        c.clear();
    }
    // write result to the file
    ag.writeFile(outFileName, c.results);
    return 0;
}