#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<int,vector<int>> cut(int left) {
  if (left == 0) {
    return make_tuple(1, vector<int>());
  } else {
    int max_value = 0;
    vector<int> max_cuts;
    for (int i = 0 ; i < left ; i++) {
      int segment = i + 1;
      int left_value;
      vector<int> left_cuts;
      tie(left_value, left_cuts) = cut(left - segment);
      if (segment * left_value > max_value) {
	max_value = segment * left_value;
	max_cuts = left_cuts;
	max_cuts.insert(max_cuts.begin(), segment);
      }
    }
    return make_tuple(max_value,max_cuts);
  }
}

int main()
{
  cout<<"input number:";
  int value;
  cin>>value;
  vector<int> cuts;
  tie(value, cuts) = cut(value);
  for (auto & c: cuts) {
    cout<<c<<",";
  }
  cout<<endl;
}

