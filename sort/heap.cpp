#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// time complexity: O(n log(n))

unsigned int get_left_child(unsigned int index) {
  return 2 * (index + 1) - 1;
}

unsigned int get_right_child(unsigned int index) {
  return 2 * (index + 1) + 1 - 1;
}

unsigned int get_parents(unsigned int index) {
  return (index + 1) / 2 - 1;
}

template<typename T>
void down(vector<T> & v, unsigned int index, unsigned int length) {
  assert(length <= v.size());
  if (index >= length) return;
  unsigned int right_index = get_right_child(index);
  unsigned int left_index = get_left_child(index);
  if(left_index < length && v[left_index] > v[index]) {
    T tmp = v[index];
    v[index] = v[left_index];
    v[left_index] = tmp;
    down(v, left_index, length);
  }
  if(right_index < length && v[right_index] > v[index]) {
    T tmp = v[index];
    v[index] = v[right_index];
    v[right_index] = tmp;
    down(v, right_index, length);
  }
}

template<typename T>
void heap(vector<T> & v) {
  for(int i = 0 ; i < v.size() - 1 ; i++) {
    if (i == 0) {
      for(int j = v.size() - i ; j >= 0 ; j--) {
        down(v, j, v.size() - i);
      }
    } else {
      down(v, 0, v.size() - i);
    }
    T tmp = v.front();
    v.front() = v[v.size() - i - 1];
    v[v.size() - i - 1] = tmp;
  }
}

int main() {
  vector<int> a{9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
  heap(a);
  for(int i = 0 ; i < a.size() ; i++) {
    cout<<a[i]<<endl;
  }
}

