#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <sstream>
#include <string>

using namespace std;

template<typename T>
void radix(vector<T> & v) {
  set<string> tmp;
  for (auto & a:v) {
    stringstream sstr;
    sstr << setfill('0') << setw(5) << a;
    string s;
    sstr >> s;
    tmp.insert(s);
  }
  v.clear();
  for (auto & a:tmp) {
    stringstream sstr;
    sstr << a;
    T b;
    sstr >> b;
    v.push_back(b);
  }
}

int main() {
  vector<int> a{53, 3, 542, 748, 14, 214, 154, 63, 616};
  radix(a);
  for(auto & v: a) {
    cout<<v<<endl;
  }
}

