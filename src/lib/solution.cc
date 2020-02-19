#include "solution.h"

// O(n)
std::vector<int> Solution::FilterOdd(const std::vector<int> &input){
  std::vector<int> evenOnly (input.size());
    // copy only even numbers
  auto count_even = std::copy_if (input.begin(), input.end(), evenOnly.begin(), [](int i){return !(i%2);} );
  evenOnly.resize(std::distance(evenOnly.begin(),count_even)); 
return evenOnly;
}

// O(n)
std::vector<int> Solution::MapISq(const std::vector<int> &in){
  std::vector<int> output (in.size());
  std::transform(in.begin(), in.end(), output.begin(), [](int i){return i*i;} );
  return output;
}

// O(n)
int Solution::AccumulateVect(const std::vector<int> &in){
  int sum = std::accumulate(in.begin(), in.end(), 0);
  return sum;

}

MaxHeap::MaxHeap(){

}

// O(1)
int MaxHeap::GetParentIndex(int i){
  if(i <= 0 || i >= data_.size()){
    return INT_MAX;
  }
  else{
    return (i-1)/2;
  }

}

// O(1)
int MaxHeap::GetLeftIndex(int i){
  if ((2 * i) + 1 >= data_.size()) {
    return INT_MAX;
  }
  else {
    return (2 * i) + 1;
  }

}

// O(1)
int MaxHeap::GetRightIndex(int i){
  if ((2 * i) + 2 >= data_.size()) {
    return INT_MAX;
  }
  else{
    return (2 * i) + 2;
  }

}

// O(1)
int MaxHeap::GetLargestChildIndex(int i){
  
  if(GetLeft(i) != INT_MAX && GetRight(i) != INT_MAX){
    if (GetLeft(i) > GetRight(i)){
      return  GetLeftIndex(i);
    }
    else {
      return GetRightIndex(i);
    }
  }
  else if(GetLeft(i) == INT_MAX && GetRight(i) != INT_MAX){
    return GetRightIndex(i);
  }
  else if(GetLeft(i) != INT_MAX && GetRight(i) == INT_MAX){
    return GetLeftIndex(i);
  }
  else if(GetLeft(i) == INT_MAX && GetRight(i) == INT_MAX){
    return INT_MAX;
  }
}

// O(1)
int MaxHeap::GetLeft(int i){
   if ((2 * i) + 1 >= data_.size()) {
    return INT_MAX;
  }
  else {
    return data_[(2 * i) + 1];
  }
}

// O(1)
int MaxHeap::GetRight(int i){
  if ((2 * i) + 2 >= data_.size()) {
    return INT_MAX;
  }
  else{
    return data_[(2 * i) + 2];
  }
}

// O(1)
int MaxHeap::GetParent(int i){
    if(i == 0){
    return INT_MAX;
  }
  else{
    return data_[(i-1)/2];
  }
}

// O(1)
int MaxHeap::top(){
  if (data_.size() == 0) {
    return INT_MAX;
  } 
  else {
    return data_[0];
  }
}

// O(logn)
void MaxHeap::push(int v){
  data_.push_back(v);
  TrickleUp(data_.size() -1);
}

//O(logn)
void MaxHeap::pop(){
  if(top() != INT_MAX){
  data_.erase(data_.begin());
  TrickleDown(0);
  }
}

//O(logn)
void MaxHeap::TrickleUp(int i){
  // Fix the min heap property if it is violated
  while (i != 0 && GetParent(i) < data_[i]) {
    std::swap(data_[i], data_[GetParentIndex(i)]);
    i = GetParentIndex(i);
  }
}

//O(logn)
void MaxHeap::TrickleDown(int parent){
  int left = GetLeftIndex(parent);
  int right = GetRightIndex(parent);
  if (left == data_.size()-1 && data_[parent] < data_[left]){
    std::swap(data_[parent], data_[left]);
    return;
  }
  if (right == data_.size()-1 && data_[parent] < data_[right]){
    std::swap(data_[parent], data_[right]);
    return;
  }
  if (data_[left] > data_[right] && data_[parent] < data_[left]){
    std::swap(data_[parent],data_[left]);
    TrickleDown(left);
  }
  else if(data_[parent] < data_[right]){
    std::swap(data_[parent], data_[right]);
    TrickleDown(right);
  }

}


BST::BST(){
  root_ = nullptr;
}

//O(logn)
BST::BST(std::vector<int> initial_values){
    root_ = nullptr;

    for(const auto &it : initial_values) {
      push(it); 
    }
}

//O(1)
void BST::push(int key){

  if (root_ == nullptr) {
    root_ = new TreeNode(key);
  } 
  else {
  push_helper(root_, key);
  }
}


//O(logn)
void BST::push_helper(TreeNode* parent, int key){
  
  
  if (key < parent->val) {
    if (parent->left == nullptr){
      parent->left = new TreeNode(key);
    }
    else{
      push_helper(parent->left, key);
    }
  } 
  else if (key > parent->val) {
    if(parent->right == nullptr){
      parent->right = new TreeNode(key);
    }
    else{
      push_helper(parent->right, key);
    }
  }
  // dont add if key == parent->val (no duplicates in BST)
}

//O(1)
bool BST::find(int key){
  bool result = find_helper(root_, key);
  return result;

}

//O(logn)
bool BST::find_helper(TreeNode* parent, int key){

  if (parent == nullptr) {
  return false;
  }
  if (parent->val == key) {
  return true;
  }
  if (key < parent->val) {
    return find_helper(parent->left, key);  
  } 
  else {
    return find_helper(parent->right, key);
  }
}

//O(1)
bool BST::erase(int key){
  return erase_helper(root_, key, nullptr);
}

//O(logn)
bool BST::erase_helper(TreeNode* parent, int key, TreeNode* prev){
  if (parent == nullptr) {
  return false;
  }
  if (parent->val == key) {
    // erasing node with two children
    if((parent->left != nullptr && parent->right != nullptr)){ 
      // swap with in order predessor

      delete root_;
      root_ = parent;
    }
    // erasing leaf node
    else if(parent->left == nullptr && parent->right == nullptr) {
      if(prev->left == parent){
        delete prev->left;
        prev->left = nullptr;
        // delete parent;
        // parent = nullptr;
      }
      else if(prev->right == parent){
        delete prev->right;
        prev->right = nullptr;
        // delete parent;
        // parent = nullptr;
      }
    }
    // parent with one left child - set parent = child
    else if (parent->left != nullptr && parent->right == nullptr){
      if(prev->left == parent){
        prev->left = parent->left;
        delete parent;
        parent = nullptr;
      }
      else if(prev->right == parent){
        prev->right = parent->left;
        delete parent;
        parent = nullptr;
      }
    }
    // parent with one right child - set parent = child
    else if (parent->left == nullptr && parent->right != nullptr){
      if(prev->left == parent){
        prev->left = parent->right;
        delete parent;
        parent = nullptr;
      }
      else if(prev->right == parent){
        prev->right = parent->right;
        delete parent;
        parent = nullptr;
      }
    }
    return true;
  }
  if (key < parent->val) {
    return erase_helper(parent->left, key, parent);  
  } 
  else {
    return erase_helper(parent->right, key, parent);
  }
}

// O(n)
void BST::PreOrderDelete(TreeNode* a){

    if(a != nullptr){

    PreOrderDelete(a->left);
    PreOrderDelete(a->right);
    delete a;
    a = nullptr;
    }
}

// O(1)
void BST::PreOrder(std::vector<int>& result){
  PreOrder_Helper(root_, result);
}

// O(n)
void BST::PreOrder_Helper(TreeNode* a, std::vector<int>& result){

    if(a != nullptr){
    result.push_back(a->val);
    PreOrder_Helper(a->left, result);
    PreOrder_Helper(a->right,result);
    }
}

// O(1)
void BST::BFS(std::vector<int>& result){
  if(root_ != nullptr){
    std::queue<TreeNode*> children;
    BFS_Helper(root_, result, children);
  }
  
}

// O(n)
void BST::BFS_Helper(TreeNode* a, std::vector<int>& result, std::queue<TreeNode*> children){
  TreeNode* next;
  
    next = nullptr;
    if (a->left != nullptr){
      children.push(a->left);
    }
    if (a->right != nullptr){
      children.push(a->right);
    }
    
    result.push_back(a->val);
    if(!children.empty()){
      next = children.front();
      children.pop();
    }
    else{
      return;
    }
    
    BFS_Helper(next, result, children);
  
}

BST::~BST(){
  PreOrderDelete(root_);
}

// Question 5:
void Solution::heap_sort(std::vector<int>& input){
  std::priority_queue <int, std::vector<int>, std::greater<int> > min_heap; 
  for(const auto &it : input){
    min_heap.push(it);
  }
  for(auto it = input.begin(); it < input.end(); it++){
    *it = min_heap.top();
    min_heap.pop();
  }
}

// Question 6:

int MaxHeap::KthLargest(std::vector<int>& input, int k){
  std::make_heap(input.begin(), input.end());
  int kth = 0;
  for (const auto &it : input){
    push(it);
  }
  if(k==1){
    return top();
  }
  else if (k-1 > data_.size() || k-1 < 0){
    return INT_MAX;
  }
  else{
    
    return  data_[k-2] < data_[k-1]? data_[k-2] : data_[k-1];

  }
  
}