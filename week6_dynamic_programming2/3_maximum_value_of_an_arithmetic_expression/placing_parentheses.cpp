#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include<climits>
using namespace std;


using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

long long get_maximum_value(const string &exp) {
  //write your code here
  #define ll long long
  ll size = exp.length();
  ll n = (size+1)/2;

  ll m[n][n];
  ll M[n][n];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      m[i][j]=0;
      M[i][j]=0;
    }
  }
  for(int i=0;i<n;i++){
    M[i][i]=(ll)stoi(exp.substr(2*i,1));
    m[i][i]=(ll)stoi(exp.substr(2*i,1));
  }
  int i=1; int j=0;
  while(i<n && j<n){
    int x=i;
    int y=j;
    while(i<n && j<n){
      ll maxi=LONG_MIN;
      ll mini=LONG_MAX;
      //cout<<i<<j<<endl;
      for(int k=i;k<j;k++){
        ll p = eval(M[i][k],M[k+1][j], exp[2 * k + 1]);
        ll q = eval(M[i][k],m[k+1][j], exp[2 * k + 1]);
        ll r = eval(m[i][k],M[k+1][j], exp[2 * k + 1]);
        ll s = eval(m[i][k],m[k+1][j], exp[2 * k + 1]);
        maxi=max(max(max(max(p,q),r),s),maxi);
        mini=min(min(min(min(p,q),r),s),mini);
      }
      M[i][j]=maxi; m[i][j]=mini;
      i++; j++;
    }
    
    i=0;
    j=y+1;
  }
  return M[0][n-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
