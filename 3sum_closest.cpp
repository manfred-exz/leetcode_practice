//
// Created by manfred on 10/27/2015.
//
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

    }

    int twoSumClosest(vector<int>& nums, int target){
        int head = 0, tail = nums.size() - 1;

        while(head != tail){
            int currentSum = nums[head] + nums[tail];

            if(currentSum == target)
                break;

            if(currentSum > target){
                --tail;
                continue;
            }

            if(currentSum < target){
                ++head;
                continue;
            }
        }

    }
};