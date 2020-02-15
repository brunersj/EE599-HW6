#include "solution.h"

std::vector<int> Solution::FilterOdd(const std::vector<int> &input){
  std::vector<int> evenOnly (input.size());
    // copy only even numbers
  auto count_even = std::copy_if (input.begin(), input.end(), evenOnly.begin(), [](int i){return !(i%2);} );
  evenOnly.resize(std::distance(evenOnly.begin(),count_even)); 
return evenOnly;
}

std::vector<int> Solution::MapISq(const std::vector<int> &in){
  std::vector<int> output (in.size());
  std::transform(in.begin(), in.end(), output.begin(), [](int i){return i*i;} );
  return output;
}

int Solution::AccumulateVect(const std::vector<int> &in){
  int sum = std::accumulate(in.begin(), in.end(), 0);
  return sum;

}