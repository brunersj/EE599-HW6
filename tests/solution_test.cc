#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
#include <climits>


// Question 1

TEST(BST_Height, HandlesNonEmpty) {
  BST bst;
  bst.push(8);
  bst.push(3);
  bst.push(10);
  bst.push(2);
  bst.push(5);
  bst.push(14);
  bst.push(4);
  bst.push(7);
  bst.push(12);


  
  int actual = 3;
  int expected = bst.Height();

  EXPECT_EQ(expected, actual);
}


TEST(BST_Height, HandlesEmpty) {
  BST bst;



  
  int actual = 0;
  int expected = bst.Height();

  EXPECT_EQ(expected, actual);
}

// Question 2

TEST(BST_InOrder_Nonrecursive, HandlesNonEmpty) {
  BST bst;
  bst.push(8);
  bst.push(3);
  bst.push(10);
  bst.push(2);
  bst.push(5);
  bst.push(14);
  bst.push(4);
  bst.push(7);
  bst.push(12);


  
  std::vector<int> actual = {2, 3, 4, 5, 7, 8, 10, 12, 14};
  std::vector<int> expected;
  bst.InOrder_NonRecursive(expected);

  EXPECT_EQ(expected, actual);
}

TEST(BST_InOrder_Nonrecursive, HandlesEmpty) {
  BST bst;



  
  std::vector<int> actual = {};
  std::vector<int> expected;
  bst.InOrder_NonRecursive(expected);

  EXPECT_EQ(expected, actual);
}

TEST(BST_InOrder_Recursive, HandlesNonEmpty) {
  BST bst;
  bst.push(8);
  bst.push(3);
  bst.push(10);
  bst.push(2);
  bst.push(5);
  bst.push(14);
  bst.push(4);
  bst.push(7);
  bst.push(12);


  
  std::vector<int> actual = {2, 3, 4, 5, 7, 8, 10, 12, 14};
  std::vector<int> expected;
  bst.InOrder_Recursive(expected);

  EXPECT_EQ(expected, actual);
}

TEST(BST_InOrder_Recursive, HandlesEmpty) {
  BST bst;


  
  std::vector<int> actual = {};
  std::vector<int> expected;
  bst.InOrder_Recursive(expected);

  EXPECT_EQ(expected, actual);
}