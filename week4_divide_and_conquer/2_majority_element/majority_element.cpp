#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  std::sort(a.begin(),a.end());
  int cnt=1;
  int num=a[0];
  int max_cnt=1;
  for(int i=1;i<right;i++){
    if(a[i]==a[i-1]) cnt++;
    else cnt=1;
    max_cnt = std:: max(max_cnt,cnt);
    if(max_cnt>(a.size()/2))
      return a[i];
  }
  return -1;
 /* if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
  */
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
