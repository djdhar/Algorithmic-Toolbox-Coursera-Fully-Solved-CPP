#include <iostream>
#include <vector>

using std::vector;
long long merge (vector<int> &a, vector<int> &b, size_t left,size_t ave, size_t right){
  int i = left;
  int j = ave+1;
  long long inv=0;
  int c=left;
  while(i<=ave && j<=right){
    if(a[i]<=a[j]){
      b[c]=a[i];
      i++;
      c++;
    }
    else if(a[i]>a[j]){
      b[c]=a[j];
      j++;
      c++;
      inv+=ave-i+1;
    }
  }
  while(i<=ave){
      b[c]=a[i];
      i++;
      c++;
     // inv++;
  }
  while(j<=right){
      b[c]=a[j];
      j++;
      c++;
      
  }
  for(int g=left;g<=right;g++){
    a[g]=b[g];
  }

  return inv;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (left>=right) return number_of_inversions;
  size_t ave = (left+right) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  //write your code here
  number_of_inversions+= merge(a,b,left,ave,right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
