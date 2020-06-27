#include <iostream>
#include <vector>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    /*
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
    */
   int maxi=0, maxi2=0;
   int id=0,id2=0;
   for(int i=0;i<numbers.size();i++){
       if(maxi<numbers[i]){
       maxi=numbers[i];
       id=i;
       }
   }
   //numbers[id]=0;
   for(int i=0;i<numbers.size();i++){
       if(maxi2<numbers[i] && i!=id){
       maxi2=numbers[i];
       id2=i;
       }
   }
   return (long long)maxi*(long long)maxi2;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProduct(numbers)<< "\n";
    return 0;
}
