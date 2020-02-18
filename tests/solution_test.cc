#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>
#include <climits>

TEST(FilterOddTest, HandlesEvenAndOdd) {
  Solution solution;
  std::vector<int> input = {1,2,3,4,5,6,7};
  std::vector<int> actual = {2,4,6};
  std::vector<int> expected = solution.FilterOdd(input);
  EXPECT_EQ(expected, actual);
}

TEST(FilterOddTest, HandlesOnlyEven) {
  Solution solution;
  std::vector<int> input = {2,4,6};
  std::vector<int> actual = {2,4,6};
  std::vector<int> expected = solution.FilterOdd(input);
  EXPECT_EQ(expected, actual);
}

TEST(FilterOddTest, HandlesOnlyOdd) {
  Solution solution;
  std::vector<int> input = {1,3,5,7};
  std::vector<int> actual = {};
  std::vector<int> expected = solution.FilterOdd(input);
  EXPECT_EQ(expected, actual);
}

TEST(FilterOddTest, HandlesEmpty) {
  Solution solution;
  std::vector<int> input = {};
  std::vector<int> actual = {};
  std::vector<int> expected = solution.FilterOdd(input);
  EXPECT_EQ(expected, actual);
}

TEST(MapTest, HandlesConsecutive) {
  Solution solution;
  std::vector<int> input = {1,2,3,4,5,6,7};
  std::vector<int> actual = {1,4,9,16,25,36,49};
  std::vector<int> expected = solution.MapISq(input);
  EXPECT_EQ(expected, actual);
}

TEST(MapTest, HandlesEmpty) {
  Solution solution;
  std::vector<int> input = {};
  std::vector<int> actual = {};
  std::vector<int> expected = solution.MapISq(input);
  EXPECT_EQ(expected, actual);
}

TEST(AccumulateTest, HandlesConsecutive) {
  Solution solution;
  std::vector<int> input = {1,2,3,4,5,6,7};
  int actual = 28;
  int expected = solution.AccumulateVect(input);
  EXPECT_EQ(expected, actual);
}

TEST(AccumulateTest, HandlesEmpty) {
  Solution solution;
  std::vector<int> input = {};
  int actual = 0;
  int expected = solution.AccumulateVect(input);
  EXPECT_EQ(expected, actual);
}

// Question 2

TEST(GetParentIndexTest, HandlesNullRoot) {
  MaxHeap maxheap;
  int actual = INT_MAX;
  int expected = maxheap.GetParentIndex(0);
  EXPECT_EQ(expected, actual);
}

TEST(GetParentIndexTest, HandlesOutOfRange) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = INT_MAX;
  int expected = maxheap.GetParentIndex(3);
  EXPECT_EQ(expected, actual);
}

TEST(GetParentIndexTest, HandlesInRange) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = 0;
  int expected = maxheap.GetParentIndex(2);
  EXPECT_EQ(expected, actual);
}

TEST(GetLeftIndexTest, HandlesRoot) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = 1;
  int expected = maxheap.GetLeftIndex(0);
  EXPECT_EQ(expected, actual);
}

TEST(GetLeftIndexTest, HandlesOutOfRange) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = INT_MAX;
  int expected = maxheap.GetLeftIndex(3);
  EXPECT_EQ(expected, actual);
}

TEST(GetLeftIndexTest, HandlesInRange) {
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
maxHeap.push(91);
  int actual = 9;
  int expected = maxHeap.GetLeftIndex(4);
  EXPECT_EQ(expected, actual);
}

TEST(GetRightIndexTest, HandlesRoot) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = 2;
  int expected = maxheap.GetRightIndex(0);
  EXPECT_EQ(expected, actual);
}

TEST(GetRightIndexTest, HandlesOutOfRange) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = INT_MAX;
  int expected = maxheap.GetRightIndex(3);
  EXPECT_EQ(expected, actual);
}

TEST(GetRightIndexTest, HandlesInRange) {
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
maxHeap.push(91);
  int actual = 10;
  int expected = maxHeap.GetRightIndex(4);
  EXPECT_EQ(expected, actual);
}

TEST(GetLargestChildIndexTest, HandlesRoot) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = 2;
  int expected = maxheap.GetLargestChildIndex(0);
  EXPECT_EQ(expected, actual);
}

TEST(GetLargestChildIndexTest, HandlesOutOfRange) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = INT_MAX;
  int expected = maxheap.GetLargestChildIndex(3);
  EXPECT_EQ(expected, actual);
}

TEST(GetLargestChildIndexTest, HandlesInRange) {
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
  int actual = 5;
  int expected = maxHeap.GetLargestChildIndex(2);
  EXPECT_EQ(expected, actual);
}

TEST(TopTest, HandlesNonEmptyHeap) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = 7;
  int expected = maxheap.top();
  EXPECT_EQ(expected, actual);
}

TEST(TopTest, HandlesEmptyHeap) {
  MaxHeap maxheap;
  int actual = INT_MAX;
  int expected = maxheap.top();
  EXPECT_EQ(expected, actual);
}

TEST(PushTest, HandlesPushLargest) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  int actual = 7;
  int expected = maxheap.top();
  EXPECT_EQ(expected, actual);
}

TEST(PushTest, HandlesPushSmallest) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  maxheap.push(1);
  int actual = 1;
  int expected = maxheap.GetLeft(1);
  EXPECT_EQ(expected, actual);
}

TEST(PopTest, HandlesPop) {
  MaxHeap maxheap;
  maxheap.push(4);
  maxheap.push(2);
  maxheap.push(7);
  maxheap.pop();
  int actual = 4;
  int expected = maxheap.top();
  EXPECT_EQ(expected, actual);
}

TEST(PushTest, HandlesPopEmpty) {
  MaxHeap maxheap;
  maxheap.pop();
  int actual = INT_MAX;
  int expected = maxheap.top();
  EXPECT_EQ(expected, actual);
}

// Question 3


// Question 4 - BFS




TEST(BFSTest, HandlesBFS) {
  BST tree3;
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
  std::vector<int> actual = {8, 3, 10, 1, 6, 14, 4, 7, 13};
  tree3.BFS(outputq4);
  std::vector<int>  expected = outputq4;
  EXPECT_EQ(expected, actual);
}

TEST(BFSTest, HandlesEmpty) {
  BST tree3;
  std::vector<int> outputq4;
  std::vector<int> actual = {};
  tree3.BFS(outputq4);
  std::vector<int>  expected = outputq4;
  EXPECT_EQ(expected, actual);
}

TEST(BFSTest, Handles1) {
  BST tree3;
  tree3.push(4);
  std::vector<int> outputq4;
  std::vector<int> actual = {4};
  tree3.BFS(outputq4);
  std::vector<int>  expected = outputq4;
  EXPECT_EQ(expected, actual);
}

// Question 5



TEST(HeapSortTest, HandlesSampleInput) {
  Solution s;
  std::vector<int> inputq5 = {5, 9, 3, 1, 7};
  s.heap_sort(inputq5);
  std::vector<int> actual = {1,3,5,7,9};
  std::vector<int>  expected = inputq5;
  EXPECT_EQ(expected, actual);
}

TEST(HeapSortTest, HandlesEmptyInput) {
  Solution s;
  std::vector<int> inputq5 = {};
  s.heap_sort(inputq5);
  std::vector<int> actual = {};
  std::vector<int>  expected = inputq5;
  EXPECT_EQ(expected, actual);
}


TEST(HeapSortTest, HandlesNegAndPosInput) {
  Solution s;
  std::vector<int> inputq5 = {5, 9, -1, 3, 1, 7, -4};
  s.heap_sort(inputq5);
  std::vector<int> actual = {-4,-1,1,3,5,7,9};
  std::vector<int>  expected = inputq5;
  EXPECT_EQ(expected, actual);
}

// Question 6


TEST(KthLargestTest, HandlesSampleInput1) {
  MaxHeap maxHeap6;
  std::vector<int> inputq6 = {0,2,1,5,6,3};
  int k = 2;
  int actual = 5;
  int expected = maxHeap6.KthLargest(inputq6, k);
  EXPECT_EQ(expected, actual);
}

TEST(KthLargestTest, HandlesSampleInput2) {
  MaxHeap maxHeap6;
  std::vector<int> inputq6 = {-2, 3,-1,2,5,6,10};
  int k = 3;
  int actual = 5;
  int expected = maxHeap6.KthLargest(inputq6, k);
  EXPECT_EQ(expected, actual);
}