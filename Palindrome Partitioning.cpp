#include <string>
#include <iostream>
#include <vector>
#include <cassert>
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

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<size_t> cut_positions;
        vector<vector<string>> result;
        step(s, 0, cut_positions, result);
        return result;
    }

    void step(const string &s, size_t begin, vector<size_t> &cut_positions, vector<vector<string>> &result) {
        // end the recursion
        if(s.size() - begin <= 1) {
            result.push_back(to_string_vec(s, cut_positions));
            return;
        }

        for(size_t cut_pos = begin+1; cut_pos < s.size(); ++cut_pos) {
            if(is_palindrome(s, begin, cut_pos) == false) continue;
            // try this cut pos
            cut_positions.push_back(cut_pos);
            step(s, cut_pos, cut_positions, result);
            // backtracking the cut pos
            cut_positions.erase(cut_positions.end()-1);
        }

        if(is_palindrome(s, begin, s.size())){
            result.push_back(to_string_vec(s, cut_positions));
        }
    }

    bool is_palindrome(const string& str, size_t begin, size_t end) {
        size_t back = end-1;
        while(begin < back) {
            if(str[begin] != str[back]) return false;
            ++begin;
            --back;
        }
        return true;
    }
};

int main() {
    Solution s;

    auto res = s.partition("abba");
    for(auto partition: res) {
        for(auto item: partition) {
            cout << item << " ";
        }
        cout << endl;
    }
}

