#include <iostream>
#include <vector>
using namespace std;
#include<bits/stdc++.h>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b, vector<int> &res) {
  //write your code here
  int dp[a.size()+1][b.size()+1];
  for(int i=0;i<=a.size();i++){
    for(int j=0;j<=b.size();j++){
      dp[i][j]=0;
    }
  }

  for(int i=1;i<=a.size();i++){
    for(int j=1;j<=b.size();j++){
      dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
      if(a[i-1]==b[j-1]){
        dp[i][j]=std::max(dp[i-1][j-1]+1,dp[i][j]);
      }
     
    }
  }

  int i = a.size();
  int j = b.size();
  while(i>=1 || j>=1){
    if(dp[i][j]==dp[i-1][j-1]+1){
      res.push_back(a[i-1]); i--;j--;
    }
    else if(dp[i][j]==dp[i-1][j]){
      i--;
    }
    else if(dp[i][j]==dp[i][j-1]){
      j--;
    }
  }
  std::reverse(res.begin(),res.end());
  return dp[a.size()][b.size()];
}


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  int dp[a.size()+1][b.size()+1][c.size()+1];
  for(int i=0;i<=a.size();i++){
    for(int j=0;j<=b.size();j++){
      for(int k=0;k<=c.size();k++){
       dp[i][j][k]=0; 
      }
    }
  }
  for(int i=1;i<=a.size();i++){
    for(int j=1;j<=b.size();j++){
      for(int k=1;k<=c.size();k++){
            dp[i][j][k]=max(std::max(dp[i-1][j][k],dp[i][j-1][k]),dp[i][j][k-1] );
            int dj=0;
            //dj = max(std::max(dp[i-1][j-1][k],dp[i][j-1][k-1]),dp[i-1][j][k-1] );
            dp[i][j][k] = max(dp[i][j][k],dj);
            if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
              dp[i][j][k]=max(dp[i-1][j-1][k-1]+1,dp[i][j][k]) ;
            }
      }
    }
  }

  return dp[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
