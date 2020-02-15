#ifndef SOLUTION_H
#define SOLUTION_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>

// Person class is defined for demonstration


class Solution {
public:
  std::vector<int> FilterOdd(const std::vector<int> &);
  std::vector<int> MapISq(const std::vector<int> &);
  int AccumulateVect(const std::vector<int> &);
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

private:
std::vector<int> data;

};

#endif