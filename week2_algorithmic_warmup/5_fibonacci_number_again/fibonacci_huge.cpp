#include <iostream>
using namespace std;
long long pisano( long long m){
    long long prev=0;
    long long current =1;
    //cout<<prev<<" ";
    //cout<<current<<" ";
    for(long long i=0;i<m*m;i++){
        
        
        long long temp = (prev+current)%m;
        prev=current;
        current = temp;
        //cout<<current<<" ";
        if(prev==0 && current==1)
            return i+1;
    }
}

long long get_fibonacci_huge_naive(long long n, long long m) {
   long long psn = pisano(m);
   //std::cout<<psn<<std::endl;
   n=n%psn;
   long long prev=0;
   long long current=1;
   if(n==0) return 0;
   if (n==1) return 1;

   for(long long i=0;i<n-1;i++){
       long long temp = (prev+current)%m;
        prev=current;
        current = temp;
    }
    return (current%m);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
