#include <iostream>
using namespace std;

int fibonacci_sum_squares_naive(long long n) {
    //cout<<(n%30)<<endl;
    if (n%30 <= 1)
        return n%30;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;
    //cout<<previous<<" "<<current<<" ";

    for (long long i = 2; i <= n%30; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current)%10;
        sum += (current%10 * current%10)%10;
        //cout<<sum%10<<" ";
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);
}
