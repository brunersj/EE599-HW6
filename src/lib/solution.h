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
#include <stack>



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
void InOrder_Recursive(std::vector<int>& result);
void InOrder_NonRecursive(std::vector<int>& result);
void BFS(std::vector<int>& result);
int Height(void);
int Height(TreeNode* current);

private:
void BFS_Helper(TreeNode* a, std::vector<int>& result, std::queue<TreeNode*> children);
void PreOrder_Helper(TreeNode* a, std::vector<int>& result);
void InOrder_Recursive_Helper(TreeNode* a, std::vector<int>& result);
void PreOrderDelete(TreeNode* a);
void push_helper(TreeNode* parent, int key);
bool find_helper(TreeNode* parent, int key);
bool erase_helper(TreeNode* parent, int key, TreeNode* prev);
TreeNode *root_;
};

#endif