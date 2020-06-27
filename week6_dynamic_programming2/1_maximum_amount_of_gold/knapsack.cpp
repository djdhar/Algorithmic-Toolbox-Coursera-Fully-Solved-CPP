#include <iostream>
#include <vector>

using std::vector;
int   optimal_weight(int W, const vector<int> &w, int n) {
  int wt = W+1;
  //write your code here
   std::vector<int> dp(n * wt);
 // long long dp[n+1][W+1];

 // dp [i][j] = dp[i * wt + j]
  for(int i=0;i<n;i++){
    for(int j=0;j<=W;j++){
      dp[i * wt + j]=0;
    }
  }
  for(int i=1;i<n;i++){
    for(int j=1;j<=W;j++){
      dp[i * wt + j]=dp[(i-1) * wt + j];
      if(j>=w[i-1]){
        dp[i * wt + j]= std::max(dp[(i-1)*wt + j-w[i-1]]+ w[i-1],dp[i * wt + j]);
      }
    }
  }
  return  dp[(n-1) * wt + (wt-1)];
}

int main() {
  //#define int long long
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w,n+1) << '\n';
}
