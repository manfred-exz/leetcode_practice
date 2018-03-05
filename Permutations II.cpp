//
// Created by manfred-exz on 2018/3/5.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        backtracking(nums, 0, result);
        return result;
    }

    // nums[0, idx) are chosen numbers, nums[idx] is the next number to choose
    void backtracking(vector<int> param, int idx, vector<vector<int>>& result) {
        if(idx == param.size() - 1) {
            result.push_back(param);
            return;
        } else {
            std::sort(param.begin() + idx, param.end());
            for(int to_swap = idx; to_swap < param.size(); ++to_swap) {
                // if the number to be chosen is the same as the attempted one. pass it
                if(to_swap > idx && param[to_swap] == param[to_swap-1])
                    continue;
                std::swap(param[to_swap], param[idx]);
                backtracking(param, idx+1, result);
                std::swap(param[to_swap], param[idx]);
            }
        }
    }
};

void print(const vector<vector<int>> &result) {
    for(auto row: result) {
        for(auto item: row) {
            cout << item << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution s;
    std::vector<int> nums{2, 2, 1, 1};
    auto res = s.permuteUnique(nums);
    print(res);
}