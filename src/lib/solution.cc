#include "solution.h"

// O(n)
std::vector<int> Graph::NonRecursiveDFS(int root) {
  if (v_.empty()) {
    std::cerr << "Error: Adjacency List empty" << std::endl;
    return {};
  }
  if (v_.find(root) == v_.end()) {
    std::cerr << "Error: Root not in map" << std::endl;
    return {};
  }
  std::vector<int> dfsVect;
  // use stack to mimick recursive property
  std::stack<int> nodes_stack;
  // if node indecies are not consecutive starting from 0 -> need to map
  // nodes_stack to consecutive index with root 0 std::map<int,int> nodeMap;

  std::vector<bool> spt(v_.size(), false);
  // for(int i=0; i < v_.size(); i++){
  //   spt[i] = false;
  // }
  // spt[root] = true;
  nodes_stack.push(root);

  while (!nodes_stack.empty()) {
    int stackTop = nodes_stack.top();
    nodes_stack.pop();

    if (!spt[stackTop]) {
      spt[stackTop] = true;
      dfsVect.push_back(stackTop);
    }
    // prints incorrect order - right node first because of stack
    // for(const int& child : v_[stackTop] ){
    //   if (!spt[child]){

    //     nodes_stack.push(child);
    //   }

    // reverse order of set in map
    for (auto it = v_[stackTop].rbegin(); it != v_[stackTop].rend(); ++it) {
      if (!spt[*it]) {
        nodes_stack.push(*it);
      }
    }
  }
  return dfsVect;
}

// O(n)
std::vector<int> Graph::DFS_ALL() {
  if (v_.empty()) {
    return {};
  }
  std::vector<int> dfsVect;
  // use stack to mimick recursive property
  std::stack<int> nodes_stack;

  std::vector<bool> spt(v_.size(), false);
  nodes_stack.push(0);

  while (!nodes_stack.empty()) {
    int stackTop = nodes_stack.top();
    nodes_stack.pop();

    if (!spt[stackTop]) {
      spt[stackTop] = true;
      dfsVect.push_back(stackTop);
    }

    // reverse order of set in map
    for (auto it = v_[stackTop].rbegin(); it != v_[stackTop].rend(); ++it) {
      if (!spt[*it]) {
        nodes_stack.push(*it);
      }
    }
    // if stack is empty and not all nodes_stack have been visited
    if (nodes_stack.empty()) {
      // std::vector<bool>::iterator it = std::find(spt.begin(),spt.end(),
      // false); if( it != spt.end()){
      //   nodes_stack.push(*it);
      // }

      // ** implement find function **
      for (int i = 0; i < spt.size(); i++) {
        if (!spt[i]) {  // visit nodes not visited
          nodes_stack.push(i);
        }
      }
    }
  }
  return dfsVect;
}

// Using DFS and overwriting 2d matrix cell with "2" on visited cells
// O(m+n) = O(row*col)=O(n^2)
bool Maze::FindMazePath(int start_row, int start_col, int end_row, int end_col) {
  // check if goal is reachable and goal and start are in range
  if (start_row > adj_.size() || start_col > adj_.size() || end_row > adj_.size() || end_col > adj_.size() || adj_[start_row][start_col] == 0 || adj_[end_row][end_col] == 0) {
    return false;
  }
  // set current node as visited
  adj_[start_row][start_col] = 2;
  // check for goal
  if (start_row == end_row && start_col == end_col) {
    return true;
  }

  // move up
  if (start_row > 0) {
    if (adj_[start_row - 1][start_col] == 1) {
      if (FindMazePath(start_row - 1, start_col, end_row, end_col)) {
        return true;
      }
    }
  }

  // move down
  if (start_row < adj_.size() - 1) {
    if (adj_[start_row + 1][start_col] == 1) {
      if (FindMazePath(start_row + 1, start_col, end_row, end_col)) {
        return true;
      }
    }
  }

  // move left
  if (start_col > 0) {
    if (adj_[start_row][start_col - 1] == 1) {
      if (FindMazePath(start_row, start_col - 1, end_row, end_col)) {
        return true;
      }
    }
  }

  // move right
  if (start_col < adj_.size() - 1) {
    if (adj_[start_row][start_col + 1] == 1) {
      if (FindMazePath(start_row, start_col + 1, end_row, end_col)) {
        return true;
      }
    }
  }

  adj_[start_row][start_col] = 1;

  return false;
}

// using code from hw 5
BST::BST() {
  root_ = nullptr;
}

//O(logn)
BST::BST(std::vector<int> initial_values) {
  root_ = nullptr;

  for (const auto& it : initial_values) {
    push(it);
  }
}

//O(1)
void BST::push(int key) {
  if (root_ == nullptr) {
    root_ = new TreeNode(key);
  } else {
    push_helper(root_, key);
  }
}

//O(logn)
void BST::push_helper(TreeNode* parent, int key) {
  if (key < parent->val) {
    if (parent->left == nullptr) {
      parent->left = new TreeNode(key);
    } else {
      push_helper(parent->left, key);
    }
  } else if (key > parent->val) {
    if (parent->right == nullptr) {
      parent->right = new TreeNode(key);
    } else {
      push_helper(parent->right, key);
    }
  }
  // dont add if key == parent->val (no duplicates in BST)
}

//O(1)
bool BST::find(int key) {
  bool result = find_helper(root_, key);
  return result;
}

//O(logn)
bool BST::find_helper(TreeNode* parent, int key) {
  if (parent == nullptr) {
    return false;
  }
  if (parent->val == key) {
    return true;
  }
  if (key < parent->val) {
    return find_helper(parent->left, key);
  } else {
    return find_helper(parent->right, key);
  }
}

//O(1)
bool BST::erase(int key) {
  return erase_helper(root_, key, nullptr);
}

//O(logn)
bool BST::erase_helper(TreeNode* parent, int key, TreeNode* prev) {
  if (parent == nullptr) {
    return false;
  }
  if (parent->val == key) {
    // erasing node with two children
    if ((parent->left != nullptr && parent->right != nullptr)) {
      // swap with in order predessor

      delete root_;
      root_ = parent;
    }
    // erasing leaf node
    else if (parent->left == nullptr && parent->right == nullptr) {
      if (prev->left == parent) {
        delete prev->left;
        prev->left = nullptr;
        // delete parent;
        // parent = nullptr;
      } else if (prev->right == parent) {
        delete prev->right;
        prev->right = nullptr;
        // delete parent;
        // parent = nullptr;
      }
    }
    // parent with one left child - set parent = child
    else if (parent->left != nullptr && parent->right == nullptr) {
      if (prev->left == parent) {
        prev->left = parent->left;
        delete parent;
        parent = nullptr;
      } else if (prev->right == parent) {
        prev->right = parent->left;
        delete parent;
        parent = nullptr;
      }
    }
    // parent with one right child - set parent = child
    else if (parent->left == nullptr && parent->right != nullptr) {
      if (prev->left == parent) {
        prev->left = parent->right;
        delete parent;
        parent = nullptr;
      } else if (prev->right == parent) {
        prev->right = parent->right;
        delete parent;
        parent = nullptr;
      }
    }
    return true;
  }
  if (key < parent->val) {
    return erase_helper(parent->left, key, parent);
  } else {
    return erase_helper(parent->right, key, parent);
  }
}

// O(n)
void BST::PreOrderDelete(TreeNode* a) {
  if (a != nullptr) {
    PreOrderDelete(a->left);
    PreOrderDelete(a->right);
    delete a;
    a = nullptr;
  }
}

// O(1)
void BST::PreOrder(std::vector<int>& result) {
  PreOrder_Helper(root_, result);
}

// O(n)
void BST::PreOrder_Helper(TreeNode* a, std::vector<int>& result) {
  if (a != nullptr) {
    result.push_back(a->val);
    PreOrder_Helper(a->left, result);
    PreOrder_Helper(a->right, result);
  }
}

// O(1)
void BST::InOrder_Recursive(std::vector<int>& result) {
  InOrder_Recursive_Helper(root_, result);
}

// O(n)
void BST::InOrder_Recursive_Helper(TreeNode* a, std::vector<int>& result) {
  if (a != nullptr) {
    InOrder_Recursive_Helper(a->left, result);
    result.push_back(a->val);
    InOrder_Recursive_Helper(a->right, result);
  }
}

BST::~BST() {
  PreOrderDelete(root_);
}

// O(n)
std::vector<int> RearrangeVect(const std::vector<int>& v, int index) {
  BST bst;
  std::vector<int> output;
  if (index < 0 || index > v.size()) {
    std::cerr << "Error: Index out of range" << std::endl;
    output.push_back(-1);
    return output;
  }
  // push element at index to be root so all items on left will be smaller
  bst.push(v[index]);
  for (int i = 0; i < v.size(); i++) {
    if (i == index) {
      continue;
    } else {
      bst.push(v[i]);
    }
  }

  bst.InOrder_Recursive(output);
  return output;
}