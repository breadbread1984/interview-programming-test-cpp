#include <iostream>
#include <vector>
#include "btree.hpp"

using namespace std;

int main() {
  vector<int> a{53, 3, 542, 748, 14, 214, 154, 63, 616};
  shared_ptr<Node<int> > root(new Node<int>(53));
  for(int i = 1 ; i < a.size() ; i++) {
    root->insert(a[i]);
  }
  root->print();
}

