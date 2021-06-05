#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// time complexity: O(n^2)

template<typename T>
void select(vector<T> & v) {
  for (int i = 0 ; i < v.size() - 1 ; i++) {
    int min_index = 0;
    int min_value = numeric_limits<int>::max();
    for (int j = i ; j < v.size() ; j++) {
      if(v[j] < min_value) {
	min_value = v[j];
	min_index = j;
      }
    }
    v.erase(v.begin() + min_index);
    v.insert(v.begin() + i, min_value);
  }
}

int main() {
  vector<int> a{9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
  select(a);
  for(int i = 0 ; i < a.size() ; i++) {
    cout<<a[i]<<endl;
  }
}
