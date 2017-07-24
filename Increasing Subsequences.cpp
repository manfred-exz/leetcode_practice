//
// Created by manfred on 7/16/17.
//

#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int> nums) {
        set<vector<int>> res;
        vector<int> current_seq;
        dfs(res, current_seq, 0, nums);
        return vector<vector<int>>(res.begin(), res.end());
    }

    void dfs(set<vector<int>> &res, std::vector<int>& current_seq, int index, vector<int> &nums){
        if(current_seq.size() >= 2)
            res.insert(current_seq);

        for (int i = index; i < nums.size(); ++i) {
            if(current_seq.size() == 0 || nums[i] >= current_seq.back()) {
                current_seq.push_back(nums[i]);
                dfs(res, current_seq, i + 1, nums);
                current_seq.pop_back();
            }
        }
    }
};

int main(){
    Solution s;
    auto res = s.findSubsequences({4, 6, 7, 7});
    for (int i = 0; i < res.size(); ++i) {
        std::cout << ": ";
        for (int j = 0; j < res[i].size(); ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}