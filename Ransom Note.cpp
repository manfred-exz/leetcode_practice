//
// Created by manfred-exz on 7/17/2017.
//
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        std::vector<int> char_count(256, 0);
        for(char c: magazine){
            ++char_count[c];
        }

        for(char c: ransomNote){
            --char_count[c];
            if(char_count[c] < 0)
                return false;
        }
        return true;
    }
};