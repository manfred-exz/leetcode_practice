//
// Created by manfred on 7/11/2017.
//
#include <vector>
#include <iostream>
#include <cassert>
#include <limits>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> prices) {
        bool is_buying = true;
        int buy_price = std::numeric_limits<int>::max();
        int sell_price = std::numeric_limits<int>::min();
        int max_profit = 0;

        for (int i = 0; i < prices.size(); ++i) {
            int current_price = prices[i];

            if(current_price < sell_price){
                if(sell_price > buy_price) {
                    max_profit += sell_price - buy_price;
                    buy_price = std::numeric_limits<int>::max();
                    sell_price = std::numeric_limits<int>::min();
                }
            }

            if(current_price > sell_price) sell_price = current_price;

            if(current_price < buy_price) {
                buy_price = current_price;
                sell_price = std::numeric_limits<int>::min();
            }
        }

        if(sell_price > buy_price){
            max_profit += sell_price - buy_price;
        }

        return max_profit;
    }
};

int main(){
    Solution s;

    assert(s.maxProfit({7, 1, 5, 3, 6, 4}) == 7);
    assert(s.maxProfit({7, 6, 4, 3, 1}) == 0);
    assert(s.maxProfit({}) == 0);
    assert(s.maxProfit({5}) == 0);
    assert(s.maxProfit({832,92,278,13,52,4,31,341,5,1234,234,15,123,424}) == 2200);

    return 0;
}