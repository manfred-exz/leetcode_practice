//
// Created by manfred-exz on 2018/3/2.
//
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    static bool isParterner(int a, int b) {
        return a / 2 == b / 2;
    }

    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int minSwapsCouples(vector<int> row) {
        assert(row.size() % 2 == 0);
        int count = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if(isParterner(row[i], row[i+1])) continue;
            // locate the parterner and swap to the right position
            for (int j = i + 1; j < row.size(); ++j) {
                if (isParterner(row[i], row[j])) {
                    swap(row[i+1], row[j]);
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.minSwapsCouples({5,4,2,6,3,1,0,7});
    return 0;
}