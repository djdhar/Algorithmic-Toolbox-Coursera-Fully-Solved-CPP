#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int get_change(int m) {
  int a[m+1];
  for(int i=0;i<=m;i++) a[i]=INT_MAX;
  a[0]=0;
  /*
  for(int i=0;i<=m;i++) cout<<a[i]<<" ";
  cout<<endl;
  */
  int coins[3] = {1,3,4};
  for(int i=0;i<3;i++){
    for(int j=0;j<=m;j++){
      if(j>=coins[i]){
        a[j]=min(a[j],a[j-coins[i]]+1);
      }
    }
    /*
    for(int i=0;i<=m;i++) cout<<a[i]<<" ";
      cout<<endl;
      */
  }
  return a[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
