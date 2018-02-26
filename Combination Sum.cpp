#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> path;
        backtrack(candidates, result, path, target, 0);
        return result;
    }

    void backtrack(const vector<int>& candidates, vector<vector<int>>& result, vector<int> &path, int remain, int start) {
        if(remain < 0)
            return;
        else if(remain == 0)
            result.push_back(path);
        else {
            for(int i = start; i < candidates.size(); ++i) {
                path.push_back(candidates[i]);
                backtrack(candidates, result, path, remain - candidates[i], i);
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
//    s.combinationSum()
    return 0;
}