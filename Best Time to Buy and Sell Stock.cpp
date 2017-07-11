//
// Created by manfred on 7/11/2017.
//
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> prices) {
        if(prices.empty()) return 0;

        int buy_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size(); ++i) {
            int current_price = prices[i];
            int current_profit = current_price - buy_price;
            if(current_profit > max_profit)
                max_profit = current_profit;
            buy_price = std::min(buy_price, current_price);
        }

        return max_profit;
    }
};

int main(){
    Solution s;

    assert(s.maxProfit({7, 1, 5, 3, 6, 4}) == 5);
    assert(s.maxProfit({7, 6, 4, 3, 1}) == 0);


    std::cout << s.maxProfit({7, 1, 5, 3, 6, 4}) << std::endl;
    return 0;
}