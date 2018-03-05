//
// Created by manfred-exz on 2018/3/5.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        backtracking(nums, 0, result);
        return result;
    }

    // nums[0, idx) are chosen numbers, nums[idx] is the next number to choose
    void backtracking(vector<int>& param, int idx, vector<vector<int>>& result) {
        if(idx == param.size() - 1) {
            result.push_back(param);
            return;
        } else {
            //
            for(int to_swap = idx; to_swap < param.size(); ++to_swap) {
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
    std::vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    auto res = s.permute(nums);
    print(res);
}