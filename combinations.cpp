//
// Created by manfred on 7/9/2016.
//

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int n, k;

    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        vector<int> one_comb;
        vector<vector<int>> result;

        /* special case */
        if(k > n)
            return result;
        if(n == 1){
            result.push_back(vector<int>{1});
            return result;
        }


        /* init 'one_comb' with the smallest combination */
        for (int i = 0; i < k; ++i) {
            one_comb.push_back(i+1);
        }

        if(n == k){
            result.push_back(one_comb);
            return result;
        }

        if(k == 1){
            for (int i = 0; i < n; ++i) {
                result.push_back({i+1});
            }
            return result;
        }

        while(true){
            result.push_back(one_comb);
            step(one_comb);

            if(one_comb[0] == n-k+1){
                result.push_back(one_comb);
                break;
            }
        }

        return result;
    }

    void step(vector<int>& comb){
        int diff = n-k;
        for (auto i = comb.size()-1; i >= 0; --i) {
            auto max = i + 1 + diff;
            if(comb[i] < max){
                ++comb[i];
                for (int j = i+1; j < comb.size(); ++j) {
                    comb[j] = comb[j-1]+1;
                }
                break;
            }
        }

    }
};

int main(){
    Solution s;
//    auto result = s.combine(4, 2);
    auto result = s.combine(2, 2);
//    auto result = s.combine(20, 16);

    for(auto comb: result){
        for(auto num: comb)
            cout << num << ',';
        cout << endl;
    }

    return 0;
}