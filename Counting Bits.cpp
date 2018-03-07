//
// Created by manfred-exz on 2018/3/6.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp;
        dp.reserve(num+1);
        dp.push_back(0);
        int to_chop = 1;
        for(int i = 1; i <= num; ++i) {
            if(i >= to_chop * 2)
                to_chop *= 2;
            dp.push_back(dp[i-to_chop] + 1);
        }
        return dp;
    }
};

int main() {
    Solution s;
    auto res = s.countBits(5);
    for(int item : res) {
        cout << item << " ";
    }
    return 0;
}