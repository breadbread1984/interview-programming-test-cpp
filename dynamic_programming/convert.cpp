#include<iostream>
#include<vector>
#include<tuple>
#include<string>
#include<set>
#include<algorithm>

using namespace std;

typedef enum {ADD,DEL,UPDATE} action;
typedef tuple<int,action> step;

tuple<int,int> match(const string & target, const string & current) {
  set<char> a(target.begin(), target.end());
  set<char> b(current.begin(), current.end());
  set<char> c;
  set_intersection(a.begin(),a.end(),b.begin(),b.end(),c.begin());
  int count = 0;
  for (int i = 0 ; i < target.size() && i < current.size() ; i++) {
    if(target[i] == current[i]) count++;
  }
  return make_tuple(c.size(),count);
}

int distance(const string & target, const string & current) {
  int presented, matched;
  tie(presented, matched) = match(target, current);
  set<char> c(target.begin(),target.end());
  int diff1 = c.size() - presented;
  int diff2 = target.size() - matched;
  return diff1 + diff2;
}

vector<step> convert(const vector<step> & steps, string current, string target) {
  if (current == target) {
    return steps;
  } else {
    
  }
}
