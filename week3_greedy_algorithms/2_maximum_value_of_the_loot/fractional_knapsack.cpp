#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<pair<double,pair<int,int>>> vtr;
  for(int i=0;i<weights.size();i++){
    vtr.push_back(make_pair((double)values[i]/(double)weights[i], make_pair(values[i],weights[i])));
  }
  sort(vtr.begin(),vtr.end());
  reverse(vtr.begin(),vtr.end());
  /*
  for(auto l:vtr){
    cout<<l.first<<" ";
  }
  cout<<endl;
  */

  double val=0;
  for(int i=0;i<vtr.size();i++){
    if(capacity-vtr[i].second.second>=0)
    {
      val+=vtr[i].second.first;
      capacity-=vtr[i].second.second;
    }
    else{
      val+= capacity*vtr[i].first;
      break;
    }
  }
  // write your code here

  return val;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
