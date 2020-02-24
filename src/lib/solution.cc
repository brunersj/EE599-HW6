#include "solution.h"


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
void BST::InOrder_Recursive(std::vector<int>& result){
  
  InOrder_Recursive_Helper(root_, result);



}

// O(n)
void BST::InOrder_Recursive_Helper(TreeNode* a, std::vector<int>& result){

    if(a != nullptr){
    InOrder_Recursive_Helper(a->left, result);
    result.push_back(a->val);
    InOrder_Recursive_Helper(a->right,result);
    }
}

// O(n)
void BST::InOrder_NonRecursive(std::vector<int>& result){
  


  // while current != null and stack not empty 
  if(root_ != nullptr){
  std::stack<TreeNode*> treeStack;
  //treeStack.push(root_);
  TreeNode* current = root_;

  // do
  // {
  //   // traverse left and push to stack until left = null
  //   while(current != nullptr){
  //     treeStack.push(current);
  //     current = current->left;
  //   }
  //   // add top to result vector and pop
  //   result.push_back(treeStack.top()->val);
  //   // push right from new top node and continue to push left until left = null
  //   current = treeStack.top();
  //   if(current->right != nullptr){
  //     current = current->right;
  //   }
  //   else if(!treeStack.empty()){
  //     treeStack.pop();
  //     if(treeStack.empty() == true){
  //       return;
  //     }
  //     current = treeStack.top();
  //     result.push_back(current->val);
  //     treeStack.pop();
      
  //     current = current->right;
  //   }
  // } while(current != nullptr || !treeStack.empty());


  while(current != nullptr || !treeStack.empty()){
    // traverse left and push to stack until left = null
    while(current != nullptr){
      treeStack.push(current);
      current = current->left;
    }
   
  //  add top to result vector and pop
    current = treeStack.top();
    treeStack.pop();
    result.push_back(current->val);
    // push right from new top node and continue to push left until left = null     
    current = current->right;
  }
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

int BST::Height(){
  if (root_ == nullptr){
    return 0;
  }
  else{
    return Height(root_) -1;
  }
}

int BST::Height(TreeNode* current){
  if (current == nullptr){
    return 0;
  }
 
  // height = number of edges
  // calculate the height at each node recursively
  int leftHeight = Height(current->left) + 1; // +1 for the current edge
  int rightHeight = Height(current->right) + 1;
  
  // return the largest height
  if(leftHeight > rightHeight){
    return leftHeight;
  }
  else{
    return rightHeight;
  }

  }


BST::~BST(){
  PreOrderDelete(root_);
}
