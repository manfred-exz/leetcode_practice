//
// Created by manfred on 12/8/2015.
//
#include <string>
#include <map>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> charCount;

        /* init all the  */
        for (auto ch : s)
            bool insertSucc = charCount.insert({ch, 0}).second;

        string noDupStr = "";
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            charCount[ch] += 1;
            noDupStr.append(1, ch);

            /* find a dup char */
            if(charCount[ch] == 2){
                auto dup_char_pos = noDupStr.find(ch);
                string removedStr = noDupStr.substr(0, dup_char_pos + 1);
                noDupStr = noDupStr.substr(dup_char_pos + 1);

                for (auto _ch : removedStr) {
                    charCount[_ch] -= 1;
                }
            }

        }
        return 0;
    }
};

int main(){
    map<char, int> test_map;

    printf("%d\n", test_map.insert({'a', 0}).second);

    printf("%d\n", test_map.insert({'a', 1}).second);

    return 0;
}