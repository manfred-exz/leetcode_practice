//
// Created by manfred on 7/18/17.
//
#include <vector>
#include <limits>
#include <iostream>

using namespace std;
class Solution {
public:
    bool increasingTriplet(vector<int> nums) {
        if(nums.size() < 3) return false;

        int curr_min = std::numeric_limits<int>::max();
        int upper_limit = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); ++i) {
            int curr_num = nums[i];
            if(curr_num > curr_min) {
                upper_limit = std::min(upper_limit, curr_num);
            }

            if(curr_num > upper_limit)
                return true;

            curr_min = std::min(curr_min, curr_num);
        }

        return false;
    }
};

int main() {
    Solution s;
    std::cout << boolalpha;
    std::cout << s.increasingTriplet({1, 2, 3, 4, 5}) << std::endl;
    std::cout << s.increasingTriplet({5, 4, 3, 2, 1}) << std::endl;
    std::cout << s.increasingTriplet({1, 4, 5, 2, 3}) << std::endl;
    return 0;
}