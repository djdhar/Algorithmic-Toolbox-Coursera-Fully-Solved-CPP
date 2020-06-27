#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    
    int a[60];
    a[0]=0;
    a[1]=1;
    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for(int i=2;i<60;i++){
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum = (sum+current)%10;

        a[i]=sum;
    }
    long long x = 0;
    if(from!=0) x = a[(from-1)%60];
    long long y = a[to%60];
    //std::cout<<y<<" *"<<x<<std::endl;
    if(y>=x) return (y-x);
    else return (y+10-x);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
