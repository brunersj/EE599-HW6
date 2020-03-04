
#include <iostream>
#include "src/lib/solution.h"

using std::cout;
using std::endl;

int main() {
  /*
  Question 1:

  ● A tree is an undirected graph.
  ● A tree is a connected graph.
  ● A tree is a acyclic graph.
  ● In a tree, there is a path from each vertex to all other vertices.
  ● A simple graph is a graph that does not have self loops.

  */

  /*
  Question 2:

          ilovecoding
          /          \
        ilovec       oding
        /    \       /    \
      ilo    vec    odi    ng
      / \    / \    / \    / \
     il  o  ve  c  od  i  n   g
     /\  |  /\  |  /\  |  |   |
    i  l o v  e c o d  i  n   g
     \ / \ /   \/  \/  \  /   |
      il  ov   ce  do   in    g
       \  /     \  /     \   /
        ilov    cdeo      gin
          \      /         |
          cdeiloov        gin
              \           /
               cdegiilnoov

  */

  // Question 3:

  // std::map<int, std::set<int>> vertices{
  // {1, {2, 3}},
  // {2, {1, 3, 4, 5}},
  // {3, {1, 2, 4}},
  // {4, {2, 3, 4}}
  // };

  std::map<int, std::set<int>> vertices{
      {0, {1, 2, 5}},
      {1, {0, 2, 3}},
      {2, {0, 1, 3}},
      {3, {1, 2, 4, 6}},
      {4, {3}},
      {5, {0}},
      {6, {3}}};

  Graph g(vertices);
  std::vector<int> output = g.NonRecursiveDFS(0);
  cout << "Question 3:\nDFS output: ";
  for (auto i : output) {
    cout << i << " ";
  }
  cout << endl;

  // Question 4:
  // run dfs from root - see what nodes are not visited and run dfs from that
  // node.
  cout << "Question 4:" << endl;

  // directed graph
  std::map<int, std::set<int>> vertices1{
      {0, {1}},
      {1, {2, 3}},
      {2, {0}},
      {3, {2, 4, 6}},
      {4, {}},
      {5, {6}},
      {6, {}}};

  Graph g1(vertices1);
  output.clear();
  output = g1.DFS_ALL();
  cout << "DFS All Output: ";
  for (auto i : output) {
    cout << i << " ";
  }
  cout << endl;

  // Question 5

  cout << "Question 5:" << endl;

  // 1 = free cell, 0 = blocked, 2 = visited
  std::vector<std::vector<int>> adj1 = {{1, 1, 0, 0, 0},
                                        {1, 0, 1, 1, 1},
                                        {1, 1, 0, 0, 1},
                                        {1, 1, 0, 0, 1},
                                        {1, 1, 1, 1, 1}};

  Maze m1(adj1);

  for (int i = 0; i < adj1.size(); i++) {
    for (int j = 0; j < adj1.size(); j++) {
      if (i == 0 && j == 0) {
        cout << "s ";
      } else if (i == 4 && j == 4) {
        cout << "e ";
      } else
        cout << m1.adj_[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Find Maze Path: " << m1.FindMazePath(0, 0, 4, 4) << endl;

  // 2's in the adj_ matrix reveal the path traversed
  for (int i = 0; i < adj1.size(); i++) {
    for (int j = 0; j < adj1.size(); j++) {
      if (i == 0 && j == 0) {
        cout << "s ";
      } else if (i == 4 && j == 4) {
        cout << "e ";
      } else
        cout << m1.adj_[i][j] << " ";
    }
    cout << endl;
  }
  // Question 6 - store vector into BST with element at index i as root
  /*
Input: v= [9, 7, 5, 11, 12, 2, 14, 3, 10, 6], i=9.
Output: [5, 2, 3, 6, 12, 7, 14, 9, 10, 11]
*/
  cout << "Question 6:" << endl;
  std::vector<int> input6 = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
  int index = 9;
  cout << "Input v: ";
  for (auto i : input6) {
    cout << i << " ";
  }
  cout << ", i=" << index << endl;
  output.clear();
  output = RearrangeVect(input6, index);
  cout << "Rearrange Vect Output: ";
  for (auto i : output) {
    cout << i << " ";
  }
  cout << endl;

  return EXIT_SUCCESS;
}