#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include<cmath>

using std::vector;

struct Segment {
  int start, end;
};

bool comp (Segment a, Segment b){
  return a.end<b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  std::sort(segments.begin(),segments.end(),comp);
  /*
  vector<Segment> sg;
  sg.push_back(segments[0]);


  for(int i=1;i<segments.size();i++){
    if(sg[sg.size()-1].end>=segments[i].start)
      sg[sg.size()-1].end = std::max(segments[i].end,sg[sg.size()-1].end);
    else
    {
      sg.push_back(segments[i]);
    }
    
  }*/
  vector<int> points;
  points.push_back(segments[0].end);
  //write your code here
  for (size_t i = 1; i < segments.size(); ++i) {
    if(points[points.size()-1]>=segments[i].start && points[points.size()-1]<=segments[i].end){

    }
    else
    points.push_back(segments[i].end);
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
