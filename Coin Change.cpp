//
// Created by manfred on 7/13/2017.
//
#include <cassert>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> coins, int amount) {
        std::vector<int> dp(amount + 1, -1);    // with amount i, there's least dp[i] coins to make up the amount
        dp[0] = 0;

        for (int rest_amount = 0; rest_amount <= amount; ++rest_amount) {
            int &cost = dp[rest_amount];
            for(int coin: coins){
                if(rest_amount - coin < 0) continue;
                if(dp[rest_amount - coin] == -1) continue;
                int cost_with_this_coin = dp[rest_amount - coin] + 1;
                if(cost == -1 || cost_with_this_coin < cost)
                    cost = cost_with_this_coin;
            }
        }

        return dp[amount];
    }
};

int main() {
    Solution s;
    std::cout << s.coinChange({1, 2, 5}, 11) << std::endl;
    std::cout << s.coinChange({2}, 3) << std::endl;
    std::cout << s.coinChange({186, 419, 83, 408}, 6249) << std::endl;

    return 0;
}