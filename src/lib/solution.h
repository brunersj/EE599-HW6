#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

class Graph {
 public:
  Graph(std::map<int, std::set<int>>& vertices) : v_(vertices) {}
  std::map<int, std::set<int>> v_;
  std::vector<int> NonRecursiveDFS(int root);
  std::vector<int> DFS_ALL();
};

class Maze {
 public:
  Maze(std::vector<std::vector<int>>& adj) : adj_(adj) {}
  std::vector<std::vector<int>> adj_;
  bool FindMazePath(int start_row, int start_col, int end_row, int end_col);
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// code from HW 5
class BST {
 public:
  BST();

  // Inserts elements of initial_values
  // one by one into the Tree
  BST(std::vector<int> initial_values);
  ~BST();

  void push(int key);   // **GT** Inserts a key inside Tree
  bool find(int key);   // **GT** Returns true of key is in the tree
  bool erase(int key);  // **GT** Removes the key from the tree. If not successful, returns false.
  void PreOrder(std::vector<int>& result);
  void InOrder_Recursive(std::vector<int>& result);

 private:
  void BFS_Helper(TreeNode* a, std::vector<int>& result, std::queue<TreeNode*> children);
  void PreOrder_Helper(TreeNode* a, std::vector<int>& result);
  void InOrder_Recursive_Helper(TreeNode* a, std::vector<int>& result);
  void PreOrderDelete(TreeNode* a);
  void push_helper(TreeNode* parent, int key);
  bool find_helper(TreeNode* parent, int key);
  bool erase_helper(TreeNode* parent, int key, TreeNode* prev);
  TreeNode* root_;
};

std::vector<int> RearrangeVect(const std::vector<int>& v, int i);

#endif