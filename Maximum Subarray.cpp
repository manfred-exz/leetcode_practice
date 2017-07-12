//
// Created by manfred on 7/10/2017.
//
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <iostream>
#include <functional>
#include <chrono>
#include <boost/format.hpp>
#include <map>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int> nums) {
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max = dp[0];

        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = (dp[i-1] > 0 ? dp[i-1] : 0) + nums[i];
            max = std::max(max, dp[i]);
        }

        return max;
    }
};

int main(){
    Solution s;
    assert(s.maxSubArray({1}) == 1);
    assert(s.maxSubArray({-1}) == -1);
    assert(s.maxSubArray({-2,1,-3,4,-1,2,1,-5,4}) == 6);


    return 0;
}

