//
// Created by manfred-exz on 6/28/2017.
//
#include <cassert>
#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    std::vector<int> working, original;
public:
    Solution(vector<int> nums) {
        srand(time(nullptr));
        working = nums;
        original = std::move(nums);
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        working = original;
        return working;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        for (int i = working.size() - 1; i >= 0; --i) {
            int j = rand() % (i + 1);
            std::swap(working[i], working[j]);
        }
        return working;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main(){
    Solution obj({1, 2, 3});

    for (int i = 0; i < 5; ++i) {
        auto random_vec = obj.shuffle();

        for (int j = 0; j < random_vec.size(); ++j) {
            std::cout << random_vec[j] << " ";
        }
        std::cout << std::endl;
    }
}