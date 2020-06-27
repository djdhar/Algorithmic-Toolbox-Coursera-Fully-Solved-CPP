#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>

using std::vector;
using namespace std;

int optsol(int n){
  if(n<1)
    return INT_MAX/2;
  if(n==1)
    return 1;
  int x=INT_MAX/2,y=INT_MAX/2, z= INT_MAX/2;
  if(n%2==0){
    x=n/2;
  }
  if(n%3==0){
    y=n/3;
  }
  if(n>1){
    z=n-1;
  }
  return min(min(optsol(x),optsol(y)),optsol(z))+1;
}
vector<int> optimal_sequence(int n) {
  int A[n+1];
  vector<int> sqn;
  sqn.push_back(n);
  A[0]=0;
  for(int i=1;i<=n;i++){
    A[i]=A[i-1]+1;
    if(i%2==0){
      A[i]=min(A[i/2]+1,A[i]);
    }
    if(i%3==0){
      A[i]=min(A[i/3]+1,A[i]);
    }
  }
  for(int i=n;i>1;){
    if(A[i]==A[i-1]+1){
      sqn.push_back(i-1); i--;
    }
    else if (i%2==0 && A[i]==A[i/2]+1){
      sqn.push_back(i/2); i/=2;
    }
    else if (i%3==0 && A[i]==A[i/3]+1){
      sqn.push_back(i/3); i/=3;
    }
  }
  reverse(sqn.begin(),sqn.end());
  return sqn;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
