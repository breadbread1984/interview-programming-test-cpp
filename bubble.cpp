#include <iostream>
#include <vector>

using namespace std;

// time complexity: O(n^2)

template<typename T>
void bubble(vector<T> & v) {
  for (int i = 0 ; i < v.size() - 1 ; i++) {
    for (int j = 0 ; j < v.size() - i - 1 ; j++) {
      if (v[j]>v[j+1]) {
	T a = v[j];
	v[j] = v[j+1];
	v[j+1] = a;
      }
    }
  }
}

int main() {
  vector<int> a = {1,5,3,10,8,4,8,7,2};
  bubble(a);
  for(int i = 0 ; i < a.size() ; i++) {
    cout<<a[i]<<endl;
  }
}
