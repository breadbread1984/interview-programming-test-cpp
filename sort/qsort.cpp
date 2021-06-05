#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// time complexity: O(n log(n))

template<typename T>
void qsort(vector<T> & v, int start, int end) {
  if (start < 0 || start >= v.size()) return;
  if (end < 0 || end >= v.size()) return;
  if (start >= end) return;
  int left = start, right = end;
  T pivot = v[left];
  while(left < right) {
    for (; v[right] >= pivot && left < right ; right--);
    if (left < right) {v[left] = v[right];}
    for (; v[left] <= pivot && left < right ; left++);
    if (left < right) {v[right] = v[left];}
  }
  v[left] = pivot;
  qsort(v, start, left-1);
  qsort(v, left+1, end);
}

int main() {
  vector<int> a{1,5,3,10,8,4,8,7,2};
  qsort(a,0,a.size() - 1);
  for(auto & v: a) {
    cout<<v<<endl;
  }
}

