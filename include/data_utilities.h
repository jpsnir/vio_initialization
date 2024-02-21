#ifndef DATA_UTILITIES_H
#define DATA_UTILITIES_H
#include <vector>
#include <list>
#include <cassert>

using namespace std;
vector<unsigned> slice_vector(std::vector<unsigned> &src_vector, int i, int j){
  vector<unsigned> v;
  assert(src_vector.size() != 0);
  assert(i >= 0);
  assert(j <= src_vector.size() - 1);
  
  for(auto it = src_vector.begin() + i; it != src_vector.begin() + j + 1; it++ ){
    v.push_back(*it);
  }
  return v;
}

template<typename T>
void print_vector(std::vector<T> &v){
    cout << " \n " << endl;
    for (auto e: v)
        cout << e << ",";
    cout << endl;
}


// Todo : convert these functions to templated types. 

#endif