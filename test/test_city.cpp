#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "ActorGraph.hpp"
#include "city.hpp"
#include "edge.hpp"
#include "point.hpp"
using namespace std;
using namespace testing;

TEST(TEST_CITY, SIMPLE_TEST) {
    ActorGraph ag;
    city c;

    ag.loadFromXYFile("../test/data/ucsdxy.txt", c);
    ag.loadFromPairFile("../test/data/ucsdpairs.txt", c);
    ag.readFile("../test/data/test.txt");
    ASSERT_EQ(ag.input.size(), 2);
    ASSERT_EQ(c.points.size(), 32);
    c.aStarSearch("Revelle", "MainGym");
    ASSERT_EQ(c.results[0][0]->name, "Revelle");
    c.clear();
    ASSERT_EQ(c.results[0][0]->isDone, false);
    ag.writeFile("../test/data/res.tsv", c.results);
    // cout << c.results[1] << endl;
    cout << endl;
}