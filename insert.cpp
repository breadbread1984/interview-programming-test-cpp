#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(n^2)

template<typename T>
void insert(vector<T> & v) {
  for(int i = 1 ; i < v.size() ; i++) {
    int j;
    for(j = i - 1 ; j >= 0 && v[i] < v[j] ; j--);
    T tmp = v[i];
    v.erase(v.begin() + i);
    v.insert(v.begin() + j + 1, tmp);
  }
}

int main() {
  vector<int> a = {1,5,3,10,8,4,8,7,2};
  insert(a);
  for(int i = 0 ; i < a.size() ; i++) {
    cout<<a[i]<<endl;
  }
}

