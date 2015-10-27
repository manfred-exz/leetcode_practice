//
// Created by manfred on 10/27/2015.
//

/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers (both index1 and
 * index2) are not zero-based.
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            pairs.push_back(pair<int, int>(nums[i], i+1));
        }

        int head = 0, tail = (int)nums.size() - 1;
        sort(pairs.begin(), pairs.end(), [](const pair<int, int> a, const pair<int, int> b) -> bool{
            return a.first < b.first;
        });

        while (head != tail) {
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
            head = tail = -1;

        if(pairs[head].second > pairs[tail].second)
            swap(pairs[head], pairs[tail]);

        return vector<int>{pairs[head].second, pairs[tail].second};
    }
};

int main(){
    Solution s;
//    vector<int> nums{2, 7, 11, 15};
//    int target = 9;

    vector<int> nums{-1, -2, -3, -4, -5};
    int target = -8;

//    vector<int> nums{3, 2, 4};
//    int target = 6;

    auto result = s.twoSum(nums, target);

    cout << result[0] << " " <<  result[1] << endl;

    return 0;
}