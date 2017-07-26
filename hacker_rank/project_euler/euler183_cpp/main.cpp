#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cassert>

using namespace std;
constexpr double kEulerNumber = std::exp(1.0);

std::vector<int> get_non_2_5_factor(int num) {
    std::vector<int> res;
    while(num % 2 == 0){
        num /= 2;
    }
    while(num % 5 == 0){
        num /= 5;
    }
    int max_factor = static_cast<int>(std::ceil(std::sqrt(num)));
    for (int factor = 2; factor < max_factor + 1; ++factor) {
        if(num == 1)
            break;
        while(num % factor == 0) {
            res.push_back(factor);
            num /= factor;
        }
    }

    if(num != 1){
        res.push_back(num);
    }

    return res;
}

bool is_k_for_max_p_terminating(int n) {
    // for why this is the k for max(P), check the onenote link at top
    auto k_for_max_p = static_cast<int>(std::round(n / kEulerNumber));
    while(k_for_max_p % 2 == 0){
        k_for_max_p /= 2;
    }
    while(k_for_max_p % 5 == 0) {
        k_for_max_p /= 5;
    }
    auto non_2_5_factors = get_non_2_5_factor(n);
    for(int factor: non_2_5_factors){
        if(k_for_max_p % factor == 0){
            k_for_max_p /= factor;
        }
    }

    return k_for_max_p == 1;
}

int d(int n) {
    static std::unordered_map<int, int> dp;
    auto iter = dp.find(n);
    if(iter != dp.end())
        return iter->second;
    
    if (is_k_for_max_p_terminating(n)) {
        dp[n] = -n;
        return -n;
    } else {
        dp[n] = n;
        return n;
    }
}

int64_t sum_d(int n) {
    static std::map<int, int64_t> dp;
    int64_t sum = 0;

    int i = 5;
    if(!dp.empty()) {
        i = dp.rbegin()->first + 1;
        sum = dp.rbegin()->second;
        assert(i > 5);
    }
    for (; i < n + 1; ++i) {
        const int64_t d_i = d(i);
        sum += d_i;
    }
    dp[n] = sum;
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int n;
        std::cin >> n;
        std::cout << sum_d(n) << std::endl;
    }
    return 0;
}

//int main() {
//    int q;
//    std::cin >> q;
//    for (int i = 0; i < q; ++i) {
//        int n = 10000 * (i+1);
//        std::cout << sum_d(n) << std::endl;
//    }
//    return 0;
//}
