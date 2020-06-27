#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

using std::vector;
using std::string;
using std::pair;
using std::min;

bool comp(pair<int,int> a, pair<int,int> b){
  return a.second<b.second;
}

bool mycomp(pair<int,int> a, pair<int,int> b){
  if(a.second<b.second){
    return true;
  }
  if(a.second>b.second){
    return false;
  }
  if(a.second==b.second){
    return a.first<b.first;
  }
}

double closest(vector<pair<int,int>>& points, vector<pair<int,int>>& dj, int l, int r){
  if(r-l+1<=3){
   // cout<<l<<" "<<r<<endl;
    double dist = 100000000005.0;
    for(int i=l;i<=r;i++){
      for(int j=i+1;j<=r;j++){
        
        if(i!=j){
          double foo = sqrt((double)((points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second)));
          dist = min(dist, foo);
          //cout<<foo<<endl;
        }
      }
    }
    return dist;
  }
  int m= (l+r)/2;
  double d = min(closest(points,dj,l,m),closest(points,dj,m+1,r));

  vector<pair<int,int>> strip;
  for(int i=0;i<dj.size();i++){
    if(abs(dj[i].first-points[m].first)<=d){
      strip.push_back(dj[i]);
    }
  }
 // sort(strip.begin(), strip.end(),comp);
  for(int i=0;i<strip.size();i++){
    for(int j=i+1; j< min((int)strip.size(),(i+5)) ;j++){
        double foo = sqrt((points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second));
        if(i!=j)
        d = min(d, foo);
    }
  }
  return d;
}
double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  vector<pair<int,int>> points, dj;
  for(int i=0;i<x.size();i++){
    points.push_back(make_pair(x[i],y[i]));
  }
  dj=points;
  sort(points.begin(),points.end());
  sort(dj.begin(),dj.end(), mycomp);
  double mindist = closest(points,dj,0,(points.size()-1));

  return mindist;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
