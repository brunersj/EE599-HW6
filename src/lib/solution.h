#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <climits>
#include <queue>

// Person class is defined for demonstration


class Solution {
public:
  std::vector<int> FilterOdd(const std::vector<int> &);
  std::vector<int> MapISq(const std::vector<int> &);
  int AccumulateVect(const std::vector<int> &);
  void heap_sort(std::vector<int>& input); // question 5
private:

};

class MaxHeap {
public:
MaxHeap(); // default constructor

int GetParentIndex(int i); // *GT*
int GetLeftIndex(int i); // *GT*
int GetRightIndex(int i); // *GT*
int GetLargestChildIndex(int i); // *GT*

int GetLeft(int i);
int GetRight(int i);
int GetParent(int i);

int top(); // GT
void push(int v); // GT
void pop(); // GT
void TrickleUp(int i);
void TrickleDown(int i);
int KthLargest(std::vector<int>& input, int k); // question 6


private:
std::vector<int> data_;

};


struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BST {
public:
BST();

// Inserts elements of initial_values
// one by one into the Tree
BST(std::vector<int> initial_values);
~BST();

void push(int key); // **GT** Inserts a key inside Tree
bool find(int key); // **GT** Returns true of key is in the tree
bool erase(int key); // **GT** Removes the key from the tree. If not successful, returns false.
void PreOrder(std::vector<int>& result);
void BFS(std::vector<int>& result);

private:
void BFS_Helper(TreeNode* a, std::vector<int>& result, std::queue<TreeNode*> children);
void PreOrder_Helper(TreeNode* a, std::vector<int>& result);
void PreOrderDelete(TreeNode* a);
void push_helper(TreeNode* parent, int key);
bool find_helper(TreeNode* parent, int key);
bool erase_helper(TreeNode* parent, int key, TreeNode* prev);
TreeNode *root_;
};

#endif