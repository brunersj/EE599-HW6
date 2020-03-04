#include "src/lib/solution.h"
#include <climits>
#include <vector>
#include "gtest/gtest.h"

// Q3
TEST(NonRecursiveDFSTest, ExampleDFS) {
  std::map<int, std::set<int>> vertices{
      {0, {1, 2, 5}},
      {1, {0, 2, 3}},
      {2, {0, 1, 3}},
      {3, {1, 2, 4, 6}},
      {4, {3}},
      {5, {0}},
      {6, {3}}};

  Graph g(vertices);
  std::vector<int> actual = g.NonRecursiveDFS(0);
  std::vector<int> expected = {0, 1, 2, 3, 4, 6, 5};

  EXPECT_EQ(expected, actual);
}

TEST(NonRecursiveDFSTest, DiffRoot) {
  std::map<int, std::set<int>> vertices{
      {0, {1, 2, 5}},
      {1, {0, 2, 3}},
      {2, {0, 1, 3}},
      {3, {1, 2, 4, 6}},
      {4, {3}},
      {5, {0}},
      {6, {3}}};

  Graph g(vertices);
  std::vector<int> actual = g.NonRecursiveDFS(1);
  std::vector<int> expected = {1, 0, 2, 3, 4, 6, 5};

  EXPECT_EQ(expected, actual);
}

TEST(NonRecursiveDFSTest, EmptyAdjList) {
  std::map<int, std::set<int>> vertices{};

  Graph g(vertices);
  std::vector<int> actual = g.NonRecursiveDFS(0);
  std::vector<int> expected = {};

  EXPECT_EQ(expected, actual);
}

TEST(NonRecursiveDFSTest, InvalidRoot) {
  std::map<int, std::set<int>> vertices{
      {0, {1, 2, 5}},
      {1, {0, 2, 3}},
      {2, {0, 1, 3}},
      {3, {1, 2, 4, 6}},
      {4, {3}},
      {5, {0}},
      {6, {3}}};

  Graph g(vertices);
  std::vector<int> actual = g.NonRecursiveDFS(7);
  std::vector<int> expected = {};

  EXPECT_EQ(expected, actual);
}

// Q4

TEST(DFSAllTest, ExampleQ4) {
  std::map<int, std::set<int>> vertices{
      {0, {1, 2, 5}},
      {1, {0, 2, 3}},
      {2, {0, 1, 3}},
      {3, {1, 2, 4, 6}},
      {4, {3}},
      {5, {0}},
      {6, {3}}};

  Graph g(vertices);
  std::vector<int> actual = g.DFS_ALL();
  std::vector<int> expected = {0, 1, 2, 3, 4, 6, 5};

  EXPECT_EQ(expected, actual);
}

TEST(DFSAllTest, EmptyAdjList) {
  std::map<int, std::set<int>> vertices{};

  Graph g(vertices);
  std::vector<int> actual = g.DFS_ALL();
  std::vector<int> expected = {};

  EXPECT_EQ(expected, actual);
}

//Q5

TEST(MazeTest, ExampleQ5_PathExists) {
  std::vector<std::vector<int>> adj = {{1, 1, 0, 0, 0},
                                       {1, 0, 1, 1, 1},
                                       {1, 1, 0, 0, 1},
                                       {1, 1, 0, 0, 1},
                                       {1, 1, 1, 1, 1}};

  Maze m1(adj);

  bool actual = m1.FindMazePath(0, 0, 4, 4);
  bool expected = true;

  EXPECT_EQ(expected, actual);
}

TEST(MazeTest, ExampleQ5_PathDNE) {
  std::vector<std::vector<int>> adj = {{1, 1, 0, 0, 0},
                                       {1, 1, 1, 1, 1},
                                       {0, 1, 0, 0, 1},
                                       {1, 0, 0, 0, 0},
                                       {1, 1, 1, 1, 1}};

  Maze m1(adj);

  bool actual = m1.FindMazePath(1, 2, 4, 4);
  bool expected = false;

  EXPECT_EQ(expected, actual);
}

TEST(MazeTest, AllBlocked) {
  std::vector<std::vector<int>> adj = {{0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0}};

  Maze m1(adj);

  bool actual = m1.FindMazePath(1, 2, 4, 4);
  bool expected = false;

  EXPECT_EQ(expected, actual);
}

TEST(MazeTest, LongestPath) {
  std::vector<std::vector<int>> adj = {{1, 1, 1, 1, 1},
                                       {0, 0, 0, 0, 1},
                                       {1, 1, 1, 0, 1},
                                       {1, 0, 0, 0, 1},
                                       {1, 1, 1, 1, 1}};

  Maze m1(adj);

  bool actual = m1.FindMazePath(0, 0, 2, 2);
  bool expected = true;

  EXPECT_EQ(expected, actual);
}

// Q6
TEST(RearrangeVect, ExampleQ6) {
  std::vector<int> input6 = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  int index = 9;

  std::vector<int> actual = RearrangeVect(input6, index);
  std::vector<int> expected = {2, 3, 5, 6, 7, 9, 10, 11, 12, 14};

  EXPECT_EQ(expected, actual);
}

TEST(RearrangeVect, InvalidIndex) {
  std::vector<int> input6 = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  int index = 11;

  std::vector<int> actual = RearrangeVect(input6, index);
  std::vector<int> expected = {-1};

  EXPECT_EQ(expected, actual);
}