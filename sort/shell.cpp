#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// time complexity: O(n^2)

template<typename T>
void shell(vector<T> & v) {
  for(int i = 1 ; v.size() / pow(2,i) > 0 ; i++) {
    int gap = v.size() / pow(2,i);
    for(int j = gap ; j < v.size() ; j ++) {
      int k;
      for(k = j - gap ; k >= 0 && v[k] > v[j] ; k -= gap);
      T tmp = v[j];
      v.erase(v.begin() + j);
      v.insert(v.begin() + k + gap, tmp);
    }
  }
}

int main() {
  vector<int> a{9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
  shell(a);
  for(int i = 0 ; i < a.size() ; i++) {
    cout<<a[i]<<endl;
  }
}

