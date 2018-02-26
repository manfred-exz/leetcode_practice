#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            int last = -1;
            for(int i = start; i < candidates.size(); ++i) {
                // skip the duplicates
                if(candidates[i] == last) continue;
                last = candidates[i];

                path.push_back(candidates[i]);
                backtrack(candidates, result, path, remain - candidates[i], i+1);
                path.pop_back();
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    auto combs = s.combinationSum2(candidates, 8);
    for(auto comb : combs) {
        for(auto item: comb) {
            cout << item << " ";
        }
        cout << endl;
    }
    return 0;
}