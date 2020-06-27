#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>

using std::vector;


class TreeNode{
  public:
  int start;
  int end;
  TreeNode *left;
  TreeNode *right;
  TreeNode (int s, int e){
    start=s;
    end=e;
    left=NULL;
    right=NULL;
  }
};

TreeNode *getTree (vector<int> &starts, vector<int> &ends){
  std::queue<TreeNode*> q[2];

  for(int i=0;i<starts.size();i++){
      q[0].push(new TreeNode(starts[i],ends[i]));
  }
  int k=0;
  TreeNode *finalroot;
  while(1){
  if(q[k%2].size()==1)
    return q[k%2].front();

  while(q[k%2].size()){
      TreeNode *l = q[k%2].front();
      q[k%2].pop();
      TreeNode *r=NULL;
      if(q[k%2].size()){
        TreeNode *r = q[k%2].front();
        q[k%2].pop();
      }
      TreeNode *root;
      if(r==NULL)
        root = l;
      else{
        root = new TreeNode(l->start,r->end);
        root->left=l;
        root->right=r;
      }
      q[(k+1)%2].push(root);
     // k++;      
  }
  k++;
}
  return NULL;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  vector<std::pair<int,int>> v;
  for(int i=0;i<starts.size();i++){
    v.push_back(std::make_pair(starts[i],ends[i]));
  }
  std::sort(v.begin(),v.end());

  int n1=v.size(),n2=points.size(),i=0,j=0,k;
  for(i=0;i<n2;i++)
  {
    k=0;
    for(j=0;j<n1;j++)
    {
      if(points[i]>=v[j].first && points[i]<=v[j].second)
        k++;
      else if(points[i]<v[j].first)
        j=n1;
    }
    cnt[i] = k;
  }
  
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
