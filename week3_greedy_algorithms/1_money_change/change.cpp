#include <iostream>

int get_change(int m) {
  //write your code here
  if(m==0)
    return 0;
  int p=0;
  while(m/10){
    p+=m/10;
    m=m%10;
  }
  while(m/5){
    p+=m/5;
    m=m%5;
  }
  p+=m;
  return p;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
