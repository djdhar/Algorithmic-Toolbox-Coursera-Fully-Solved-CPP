#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool comp(string a, string b){
  string s = a+b;
  string t = b+a;
  if(s>t)
    return true;
  return false;
  /*
  if(a.size()==b.size()){
    if(a>b) return true;
    return false;
  }
  if(a.size()<b.size()){
    for(int i=0;i<a.size();i++){
      if(a[i]>b[i]){
        return true;
      }
      else if(a[i]<b[i]){
        return false;
      }
    }
    return true;
  }

  if(a.size()>b.size()){
    for(int i=0;i<b.size();i++){
      if(a[i]>b[i]){
        return true;
      }
      else if(a[i]<b[i]){
        return false;
      }
    }
    return false;
  }
  */
}
string largest_number(vector<string> a) {
  std::sort(a.begin(),a.end(),comp);
  string ret="";
  for(auto s:a)
   ret+=s;
  return ret;
  /*
  int a[10]={0};
  for(auto s:aa){
    for(int i=0;i<s.length();i++){
      a[s[i]-'0']++;
    }
  }
  string ret="";
  for(int i=9;i>=0;i--){
    int t = a[i];
    while(t--){
      ret.push_back(char(i+'0'));
    }
  }
  return ret;
  */
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
