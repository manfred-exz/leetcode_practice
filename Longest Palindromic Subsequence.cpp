//
// Created by manfred-exz on 2018/2/26.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        auto dp = vector<vector<int>>(s.length(), vector<int>(s.length()));
        // each char itself is a palindrome
        for (int i = 0; i < s.length(); ++i) {
            dp[i][i] = 1;
        }

        for(int i = s.length()-1; i >= 0; --i) {
            for(int j = i+1; j < s.length(); ++j) {
                if(s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][s.length()-1];
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("cbbd");
}