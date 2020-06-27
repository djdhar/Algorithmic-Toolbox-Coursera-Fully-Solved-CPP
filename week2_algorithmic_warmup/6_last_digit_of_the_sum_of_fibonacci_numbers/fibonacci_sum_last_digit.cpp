#include <iostream>
using namespace std;
int fibonacci_sum_naive(long long n) {
    if(n==1)
        return n;
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
    //a[0]=0;
    return a[n%60];
    /*
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    cout<< previous<<" "<<current<<" "<<sum<<" ";

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum = (sum+current)%10;
        cout<<sum<<" ";
    }

    return sum % 10;
    */
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n);
}
