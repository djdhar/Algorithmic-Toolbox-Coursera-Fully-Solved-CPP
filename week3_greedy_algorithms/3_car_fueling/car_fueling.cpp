#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    vector<int> v = stops;
    int full = tank;
    for(int i=1;i<stops.size();i++){
        v[i]=stops[i]-stops[i-1];
    }
    int fill=0;
    v.push_back(dist-stops[stops.size()-1]);

    // write your code here
    dist=tank;
    for(int i=0;i<stops.size();i++){
        dist=dist-v[i];
        //cout<<"dist = "<<dist<<std::endl;
        if(dist>=v[i+1])
        {

        }
        else if(full<v[i+1]){
            return -1;
        }
        else{
            dist=tank;
            fill++;
        }
       // tank = tank-
    }
    return fill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
