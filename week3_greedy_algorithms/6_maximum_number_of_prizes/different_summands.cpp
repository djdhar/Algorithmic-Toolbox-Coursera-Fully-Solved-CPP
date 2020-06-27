#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  long long sum=0;
  for(int i=1;;i++){
    sum+=i;
    if(sum<=n){
      summands.push_back(i);
    }
    else{
      sum=sum-i;
      summands[summands.size()-1]+=(n-sum);
      break;
    }
  }
  //write your code here
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
