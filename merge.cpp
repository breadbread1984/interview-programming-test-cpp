#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(n log(n))

template<typename T>
void merge(vector<T> & v) {
  if(v.size() < 2) {
    return;
  } else if(v.size() == 2) {
    if(v[0] > v[1]) {
      T tmp = v[0];
      v[0] = v[1];
      v[1] = tmp;
    }
    return;
  } else {
    vector<T> left(v.begin(), v.begin() + v.size() / 2);
    vector<T> right(v.begin() + v.size() / 2, v.end());
    merge(left);
    merge(right);
    vector<T> merged;
    int i = 0, j = 0;
    for(; i < left.size() && j < right.size() ;) {
      if (left[i] < right[j]) {
	merged.push_back(left[i++]);
      } else {
	merged.push_back(right[j++]);
      }
    }
    if (i < left.size()) merged.insert(merged.end(), left.begin() + i , left.end());
    if (j < right.size()) merged.insert(merged.end(), right.begin() + j, right.end());
    v = merged;
  }
}

int main() {
  vector<int> a{9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
  merge(a);
  for(int i = 0 ; i < a.size() ; i++) {
    cout<<a[i]<<endl;
  }
}
