// #define _CRTDBG_MAP_ALLOC
// #include <stdlib.h>
// #include <crtdbg.h>

// #ifdef _DEBUG
//     #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//     // Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
//     // allocations to be of _CLIENT_BLOCK type
// #else
//     #define DBG_NEW new
// #endif

#include "src/lib/solution.h"
#include <iostream>


using std::cout;
using std::endl;

int main() {

  Solution s;
  
// Question 1
  std::vector<int> input = {1,2,3,4,5,6,7,8,9};
  std::vector<int> output = s.FilterOdd(input);
  cout << "Question 1: " << endl;
  for (auto i : input){
    cout << i << " ";
  }
  cout << endl;
  for (auto i : output){
    cout << i << " ";
  }

  output = s.MapISq(input);
  cout << endl;
  for (auto i : output){
    cout << i << " ";
  }
  cout << endl;

int sum = s.AccumulateVect(input);
cout << "Accumulate: " << sum << endl;

// Question 2

MaxHeap maxHeap;



maxHeap.push(90);
maxHeap.push(58);
maxHeap.push(52);
maxHeap.push(31);
maxHeap.push(49);
maxHeap.push(43);
maxHeap.push(12);
maxHeap.push(22);
maxHeap.push(30);
maxHeap.push(38);
maxHeap.push(45);
maxHeap.push(17);
maxHeap.push(28);



maxHeap.pop();

cout << "Question 2:" << endl;




// Question 3
cout << "Question 3:" << endl;
input = {8,3,10,2,5,14,4,7,12};

//BST tree(input);
BST tree1, tree2, tree3;
BST tree4(input);
tree1.push(8);
tree1.push(3);
tree1.push(10);
tree1.push(2);
tree1.push(5);
tree1.push(14);
tree1.push(4);
tree1.push(7);
tree1.push(12);

tree2.push(60);
tree2.push(20);
tree2.push(80);
tree2.push(10);
tree2.push(30);
tree2.push(25);
tree2.push(50);


std::vector<int> outputq3, outputq3_2;
// tree2.PreOrder(outputq3);
tree4.BFS(outputq3_2);
tree2.BFS(outputq3);

for (auto &it : outputq3){
  cout << it << " ";
}
cout << endl;

for (auto &it : outputq3_2){
  cout << it << " ";
}
cout << endl;

// Question 4 - BFS
std::vector<int> outputq4;
tree3.push(8);
tree3.push(3);
tree3.push(10);
tree3.push(1);
tree3.push(6);
tree3.push(14);
tree3.push(4);
tree3.push(7);
tree3.push(13);



tree3.BFS(outputq4);
for (auto &it : outputq4){
  cout << it << " ";
}
cout << endl;

// Question 5:
std::vector<int> inputq5 = {5, 9, 3, 1, 7};
s.heap_sort(inputq5);
for (auto &it : inputq5){
  cout << it << " ";
}
cout << endl;

// Question 6: Find the k(th) largest element in an unsorted vector and return that value.
// use max heap and traverse through tree k times
  std::vector<int> inputq6 = {0,2,1,5,6,3};
  int k = 2;

  MaxHeap maxHeap6, maxHeap6p2;

  int outputq6 = maxHeap6.KthLargest(inputq6, k);
  cout << outputq6 << endl;

  std::vector<int> inputq6p2 = {-2, 3,-1,2,5,6,10};
  k = 3;

  outputq6 = maxHeap6p2.KthLargest(inputq6p2, k);
  for (const auto &it : inputq6p2){
    cout << it << " ";
  }
  cout << endl;
  cout << outputq6 << endl;
  // _CrtDumpMemoryLeaks();
  return EXIT_SUCCESS;
}