#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int* leftProduct = new int [nums.size()];
        int* rightProduct = new int [nums.size()];

        /* fill in left product array */
        {
            int product = 1;
            for (auto i = 0; i < nums.size() - 1; ++i) {
                product *= nums[i];
                leftProduct[i] = product;
            }
        }

        /* fill in right product array */
        {
            int product = 1;
            for (auto i = nums.size() - 1; i > 0; --i) {
                product *= nums[i];
                rightProduct[i] = product;
            }
        }

        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            int left = (i == 0 ? 1 : leftProduct[i-1]);
            int right = (i == nums.size() - 1 ? 1 : rightProduct[i+1]);

            result[i] = left * right;
        }

        delete[](leftProduct);
        delete[](rightProduct);
        return result;
    }

    /* this version uses constant space */
    vector<int> productExceptSelfImproved(vector<int> &nums) {
        vector<int> result(nums.size());
        vector<int>& rightProduct = result;

        /* fill in right product array */
        {
            int product = 1;
            for (auto i = nums.size() - 1; i > 0; --i) {
                product *= nums[i];
                rightProduct[i] = product;
            }
        }


        int left = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if(i != 0) left *= nums[i-1];
            int right = (i == nums.size() - 1 ? 1 : rightProduct[i+1]);

            result[i] = left * right;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> input{1, 2, 3, 4};
    {
        auto res = sol.productExceptSelf(input);
        for (auto _res : res) {
            cout << _res << endl;
        }
    }

    {
        auto res = sol.productExceptSelfImproved(input);
        for (auto _res : res) {
            cout << _res << endl;
        }
    }


}