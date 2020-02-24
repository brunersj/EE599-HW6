
#include "src/lib/solution.h"
#include <iostream>


using std::cout;
using std::endl;

int main() {


std::vector<int> input;


input = {8,3,10,2,5,14,4,7,12};

//BST tree(input);
std::vector<int> outputq1, outputq1_2, outputq3, outputq3_2;
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

// tree1.erase(14);
// tree1.InOrder_NonRecursive(outputq1);


// for (auto &it : outputq1){
//   cout << it << " ";
// }
// cout << endl;

// tree1.InOrder_Recursive(outputq1_2);
// for (auto &it : outputq1_2){
//   cout << it << " ";
// }
// cout << endl;

tree2.push(60);
tree2.push(20);
tree2.push(80);
tree2.push(10);
tree2.push(30);
tree2.push(25);
tree2.push(50);

// Question 1
cout << "Tree Height: " << tree2.Height() << endl;


// tree2.PreOrder(outputq3);
// tree4.InOrder_Recursive(outputq3_2);
tree2.InOrder_Recursive(outputq3);
cout << "Recursive Inorder: ";
for (auto &it : outputq3){
  cout << it << " ";
}
cout << endl;

tree2.InOrder_NonRecursive(outputq3_2);
cout << "Non Recursive Inorder: ";
for (auto &it : outputq3_2){
  cout << it << " ";
}
cout << endl;

// for (auto &it : outputq3_2){
//   cout << it << " ";
// }
// cout << endl;

// Question 4 - BFS
std::vector<int> outputq4;
tree3.push(3);
tree3.push(2);
tree3.push(20);
tree3.push(15);
tree3.push(27);




// tree3.InOrder_NonRecursive(outputq4);

// for (auto &it : outputq4){
//   cout << it << " ";
// }
// cout << endl;



  return EXIT_SUCCESS;
}