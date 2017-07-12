//
// Created by manfred-exz on 7/12/2017.
//
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int> nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];


        // dp[i] is the max value you can rob if house i is the last house you can rob(but you can choose not to rob)
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(dp[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = std::max(nums[i] + dp[i-2], dp[i-1]);
        }

        return std::max(dp[nums.size()-1], dp[nums.size()-2]);
    }
};

int main(){
    Solution s;
    assert(s.rob({}) == 0);
    assert(s.rob({1}) == 1);
    assert(s.rob({3, 4, 1, 2}) == 6);
    assert(s.rob({3,412,3412,341,523,412,352,3423,423,42,342}) == 7703);

    return 0;
}