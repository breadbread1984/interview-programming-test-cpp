#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

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

template<typename T>
void bucket(vector<T> & v) {
  int k = static_cast<int>(sqrt(static_cast<float>(v.size())));
  map<int,vector<T> > buckets;
  for(auto & a : v) {
    buckets[static_cast<int>(a / k)].push_back(a);
  }
  v.clear();
  for(auto & p : buckets) {
    qsort(p.second, 0, p.second.size() - 1);
    v.insert(v.end(),p.second.begin(),p.second.end());
  }
}

int main() {
  vector<int> a{1,5,3,10,8,4,8,7,2};
  bucket(a);
  for(auto & v: a) {
    cout<<v<<endl;
  }
}

