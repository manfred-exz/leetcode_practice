//
// Created by manfred on 10/27/2015.
//


#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums) {
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); ++i) {
            vector<int> one_result;
            int target = -nums[i];
            one_result = twoSum(nums, target, i);
            if(one_result[0] != -1) {
                one_result.push_back(nums[i]);
                sort(one_result.begin(), one_result.end());

                result.push_back(one_result);
                printf("one_result (%d, %d, %d)\n", one_result[0], one_result[1], one_result[2]);
            }
        }


        return 0;
    }

    vector<int> twoSum(vector<int>& nums, int target, int skip) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            pairs.push_back(pair<int, int>(nums[i], i+1));
        }

        int head = 0, tail = (int)nums.size() - 1;
        sort(pairs.begin(), pairs.end(), [](const pair<int, int> a, const pair<int, int> b) -> bool{
            return a.first < b.first;
        });

        while (head != tail) {
            if(pairs[head].second == skip){
                ++head;
                continue;
            }

            if(pairs[tail].second == skip){
                --tail;
                continue;
            }

            int currentSum = pairs[head].first + pairs[tail].first;

            if (currentSum == target)
                break;

            if (currentSum > target) {
                --tail;
                continue;
            }

            if (currentSum < target) {
                ++head;
                continue;
            }
        }

        /* no solution */
        if(pairs[head].first + pairs[tail].first != target)
            return vector<int>{-1, -1};

        return vector<int>{pairs[head].first, pairs[tail].first};
    }
};

int main(){
    Solution s;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    s.threeSumClosest(nums);
}