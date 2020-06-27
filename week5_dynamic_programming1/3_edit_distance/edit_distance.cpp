#include <iostream>
#include <string>

using std::string;
using std::min;

int edit_distance(const string &a, const string &b) {
  //write your code here
  int dp[a.length()+1][b.length()+1];
  for(int i=0;i<=a.length();i++){
    dp[i][0]=i;
  }
  for(int i=0;i<=b.length();i++){
    dp[0][i]=i;
  }
  int m = a.length();
  int n = b.length();
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      int insertion;
      int deletion;
      int match;
      int mismatch;
      char c=a[i-1];
      char d = b[j-1];
      if(c==d){
        dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]);
      }
      else{
        dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+1);
      }
    }
  }
  return dp[a.length()][b.length()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
