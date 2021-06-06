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
  int which_child = -1;
  if (left_index < length && right_index < length) {
    // both children exist, pick the one with larger value
    if (v[left_index] > v[right_index]) which_child = left_index;
    else which_child = right_index;
  } else if (left_index < length) {
    // only has left child
    which_child = left_index;
  } else if (right_index < length) {
    // only has right child
    which_child = right_index;
  } else {
    // no children at all
    which_child = -1;
  }
  if(which_child >= 0 && v[which_child] > v[index]) {
    // need to switch with one child to maintain the max heap
    T tmp = v[index];
    v[index] = v[which_child];
    v[which_child] = tmp;
    down(v, which_child, length);
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

