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
#include <map>
#include <vector>

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



// Question 3
  // _CrtDumpMemoryLeaks();
  return EXIT_SUCCESS;
}