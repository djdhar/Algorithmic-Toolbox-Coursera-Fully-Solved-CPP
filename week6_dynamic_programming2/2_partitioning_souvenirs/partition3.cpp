#include <iostream>
#include <vector>

using std::vector;

int   partition3(int W, const vector<int> &w, int n) {
  int wt = W+1;
  int cnt=0;
  n++;
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
      if(dp[i * wt + j]==W)
        cnt++;

    }
  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<=W;j++){
      std::cout<<dp[i * wt + j]<<" ";
    }
    std::cout<<"\n";
  }
  */
  if(cnt<3) return 0;
  return 1;
}

int partition3(vector<int> &A) {
  //write your code here
  return 0;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> A(n);
  long long sum=0;
  for (size_t i = 0; i < A.size(); ++i) {
    std::cin >> A[i];
    sum+=A[i];
  }
  if(n<3 || sum%3!=0)
    {
      std::cout << 0<< '\n'; return 0;
    }
  std::cout << partition3(sum/3,A,n) << '\n';
}
