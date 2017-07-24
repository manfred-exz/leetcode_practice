//
// Created by manfred on 7/20/17.
//
#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>

using namespace std;
#define _PRINT

class BinaryIter {
public:
    BinaryIter(vector<int> &nums) : low(0), high(nums.size() - 1), nums(nums) {}

    bool search(int value) {
        int old_mid = mid();
        if (nums[mid()] < value)
            low = mid() + 1;
        else if (nums[mid()] > value)
            high = mid() - 1;
        else ;  // seems should do anything
        return old_mid != mid();
    }

    int value() { return nums[mid()]; }

    int mid() { return low + (high - low) / 2; }

    bool in_surrounding(int value) {
        if (value < nums[mid()]) {
            return mid() <= 0 || nums[mid() - 1] < value;
        }

        if (nums[mid()] < value) {
            return mid() + 1 >= nums.size() || value < nums[mid() + 1];
        }

        return true;
    }

    int left_nums_count() { return mid(); }

    int right_nums_count() { return static_cast<int>(nums.size()) - mid() - 1; }

private:
    int low, high;
    vector<int> &nums;
};

class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        // binary search nums1
        BinaryIter iter_1(nums1), iter_2(nums2);
        while(true) {
#ifdef _PRINT
            std::cout << "num1[" << iter_1.mid() << "] == " << iter_1.value() << std::endl;
            std::cout << "num2[" << iter_2.mid() << "] == " << iter_2.value() << std::endl;
#endif
            if (iter_1.in_surrounding(iter_2.value()) && iter_2.in_surrounding(iter_1.value())) {
#ifdef  _PRINT
                std::cout << " both in surrounding" << std::endl;
#endif
                int left_count = iter_1.left_nums_count() + iter_2.left_nums_count();
                int right_count = iter_1.right_nums_count() + iter_2.right_nums_count();
                if (left_count == right_count)
                    return (iter_1.value() + iter_2.value()) / 2.0;
                if (abs(left_count - right_count) == 1) {
                    if (nums1.size() % 2 == 1) return iter_1.value();
                    else if (nums2.size() % 2 == 1) return iter_2.value();
                    else
                        assert(false);
                }
            }
            int value_2 = iter_2.value();
            int value_1 = iter_1.value();
            bool res_1 = iter_1.search(value_2);
            bool res_2 = iter_2.search(value_1);
#ifdef _PRINT
            std::cout << "num1[" << iter_1.mid() << "] search to value " << iter_1.value() << std::endl;
            std::cout << "num2[" << iter_2.mid() << "] search to value " << iter_2.value() << std::endl;
#endif
            if(!res_1 && !res_2)
                break;
        }


        return (iter_1.value() + iter_2.value()) / 2.0;
    }
};

int main() {
    Solution s;
//    assert(s.findMedianSortedArrays({1, 2, 5}, {7, 12}) == 5);
//    assert(s.findMedianSortedArrays({1, 2, 5}, {7, 12, 100}) == 6);
//    assert(s.findMedianSortedArrays({1, 3}, {2}) == 2);
    assert(s.findMedianSortedArrays({1, 2, 3, 67, 123}, {3, 4, 10, 40, 203}) == 7);
    return 0;
}