#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int bs(const vector<int> &a, int l, int r, int x){
  if(l>r) return -1;
  int m=(l+r)/2;
  if(a[m]==x){
    return m;
  }
  if(a[m]>x){
    return bs(a,l,m-1,x);
  }
  else return bs(a,m+1,r,x);
}
int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  return bs(a,left,right-1,x);
  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
