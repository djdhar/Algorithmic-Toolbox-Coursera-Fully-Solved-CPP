#include <iostream>
#include <vector>
#include <cstdlib>
#include<bits/stdc++.h>
using namespace std;

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

pair<int,int> partition3(vector<int> &a, int low, int high) 
{ 
  int i,j;
    if (high - low <= 1) 
    { 
        if (a[high] < a[low]) 
            swap(a[high], a[low]); 
        i = low; 
        j = high; 
        return make_pair(i,j); 
    } 
  
    int mid = low; 
    int pivot = a[high]; 
    while (mid <= high) 
    { 
        if (a[mid]<pivot) 
            swap(a[low++], a[mid++]); 
        else if (a[mid]==pivot) 
            mid++; 
        else if (a[mid]>pivot) 
            swap(a[mid], a[high--]); 
    } 
 
    i = low-1; 
    j = mid; //or high-1 
    return make_pair(i,j);
} 

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  /*
  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  */
  //int m;
  pair<int,int> p = partition3(a, l, r);

  randomized_quick_sort(a, l, p.first);
  randomized_quick_sort(a, p.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
