#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// time complexity: O(n + k), k is the max replication number

template<typename T>
void count(vector<T> & v) {
  T max_value = numeric_limits<T>::min(), min_value = numeric_limits<T>::max();
  unsigned int max_index, min_index;
  for(unsigned int i = 0 ; i < v.size() ; i++) {
    if (v[i] < min_value) {
      min_value = v[i];
      min_index = i;
    }
    if (v[i] > max_value) {
      max_value = v[i];
      max_index = i;
    }
  }
  vector<T> tmp(max_value - min_value + 1);
  for(auto & a : v) {
    tmp[a - min_value]++;
  }
  v.clear();
  for(int i = 0 ; i < tmp.size() ; i++) {
    for(int j = 0 ; j < tmp[i] ; j++) {
      v.push_back(i + min_value);
    }
  }
}

int main() {
  vector<int> a{9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
  count(a);
  for(int i = 0 ; i < a.size() ; i++) {
    cout<<a[i]<<endl;
  }
}

