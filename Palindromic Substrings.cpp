//
// Created by manfred-exz on 2018/2/26.
//
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        auto count_expand = [&](int start, int end) {
            int count = 0;
            while(0 <= start && end < s.size() && s[start] == s[end]) {
                ++count;
                --start, ++end;
            }
            return count;
        };

        int count = 0;
        for(int i = 0; i < s.size(); ++i) {
            count += count_expand(i, i);
            count += count_expand(i, i+1);
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.countSubstrings("aaa");
}