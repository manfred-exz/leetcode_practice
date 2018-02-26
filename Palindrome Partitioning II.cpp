//
// Created by manfred-exz on 2018/2/24.
//

#include <string>
#include <map>
#include <iostream>
#include <utility>
#include <vector>
#include <cassert>
#include <limits>

using namespace std;

vector<string> to_string_vec(const string &s, const vector<size_t> &cut_positions) {
    vector<string> palindromes;
    size_t prev = 0;
    for (auto cut_position : cut_positions) {
        palindromes.push_back(string(s, prev, cut_position - prev));
        prev = cut_position;
    }
    palindromes.push_back(string(s, prev));
    return palindromes;
}

class PalindromeChecker{
    string str;
    // (begin, back) -> is_palindrome
    map<size_t, map<size_t, bool>> dp;
public:
    explicit PalindromeChecker(string s) : str(std::move(s)) {}

    int check_on_dp(size_t begin, size_t back) {
        auto begin_iter = dp.find(begin);
        if(begin_iter != dp.end()) {
            auto back_iter = begin_iter->second.find(back);
            if (back_iter != begin_iter->second.end())
                return back_iter->second ? 1 : -1;
        }
        return 0;
    }

    bool is_palindrome(size_t begin, size_t end) {
        size_t back = end-1;

        while(begin < back) {
            int dp_res = check_on_dp(begin, back);
            if(dp_res != 0) return dp_res > 0;

            if(str[begin] != str[back]) {
                dp[begin][back] = false;
                return false;
            }
            ++begin;
            --back;
        }

        dp[begin][back] = true;
        return true;
    }
};

class Solution {
public:
    size_t minCut(string s) {
        vector<size_t> cut_positions;
        PalindromeChecker checker(s);
        size_t min_cut = std::numeric_limits<size_t>::max();
        step(s, 0, cut_positions, min_cut, checker);
        return min_cut;
    }

    void step(const string &s, size_t begin, vector<size_t> &cut_positions, size_t& min_cut, PalindromeChecker &checker) {
        if(cut_positions.size() >= min_cut) return;

        // end the recursion
        if(s.size() - begin <= 1) {
            min_cut = std::min(min_cut, cut_positions.size());
            return;
        }

        if(checker.is_palindrome(begin, s.size())){
            min_cut = std::min(min_cut, cut_positions.size());
        }

        for(size_t cut_pos = s.size()-1; cut_pos > begin; --cut_pos) {
            if(checker.is_palindrome(begin, cut_pos) == false) continue;
            // try this cut pos
            cut_positions.push_back(cut_pos);
            step(s, cut_pos, cut_positions, min_cut, checker);
            // backtracking the cut pos
            cut_positions.erase(cut_positions.end()-1);
        }
    }
};

int main() {
    Solution s;

    cout << s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi");
}

