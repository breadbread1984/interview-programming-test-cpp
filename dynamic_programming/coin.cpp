#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

using namespace std;

tuple<int,vector<int>> money(int left_money) {
  if (left_money == 0) {
    return make_tuple(0, vector<int>());
  } else {
    static const vector<int> coins{1,2,5};
    int min_coin_num = numeric_limits<int>::max();
    vector<int> min_coin_combination;
    for(auto & coin: coins) {
      if(left_money < coin) continue;
      int coin_number;
      vector<int> coin_combination;
      tie(coin_number, coin_combination) = money(left_money - coin);
      if (1 + coin_number < min_coin_num) {
	min_coin_num = 1 + coin_number;
	min_coin_combination = coin_combination;
	min_coin_combination.insert(min_coin_combination.begin(), coin);
      }
    }
    return make_tuple(min_coin_num, min_coin_combination);
  }
}

int main()
{
  cout<<"input number:";
  int value;
  cin>>value;
  vector<int> cuts;
  tie(value, cuts) = money(value);
  for (auto & c: cuts) {
    cout<<c<<",";
  }
  cout<<endl;
}
