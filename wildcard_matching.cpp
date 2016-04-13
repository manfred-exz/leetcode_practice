//
// Created by manfred on 12/19/2015.
//
#include <algorithm>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:

    bool isMatch(string s, string p) {
        int starPos = -1;
//        const char* ss=s;
        int suPos = 0;

        int sPos = 0, pPos = 0;
        while (sPos < s.length()) {
            if ((p[pPos] == '?') || (p[pPos] == s[sPos])) {
                ++sPos;
                ++pPos;
                continue;
            }
            if (p[pPos] == '*') {
                starPos = pPos;
                ++pPos;
                suPos = sPos;
                continue;
            }
            if (starPos != -1) {
                p = starPos + 1;
                ++suPos;
                sPos = suPos;
                continue;
            }
            return false;
        }

        while (p[pPos] == '*') { ++pPos; }
        return !*p;
    }
//    bool isMatch(string s, string p) {
//        unsigned long sPos = 0, pPos =0;  /* the first char pos in p that has NOT be examined */
//        unsigned long tmpPos;
//
//        while(pPos < p.length()) {
//            if(p[pPos] == '?'){
//                if(sPos >= s.length())
//                    return false;
//                ++pPos;
//                ++sPos;
//                continue;
//            }
//
//            if(p[pPos] == '*'){
//                /* this * is already the last pattern character, then anything left in s is matched. */
//                if(pPos == p.length() - 1)
//                    return true;
//
//                /* in case *? */
//                if(pPos == p.length() - 2 && p[pPos+1] == '?'){
//                    if(sPos < s.length())
//                        return true;
//                }
//
//                auto nextStarPos = p.find_first_of("?*", pPos+1);
//                if(nextStarPos == string::npos) nextStarPos = p.length();
//                string sub = p.substr(pPos+1, nextStarPos - (pPos+1));
//
//                tmpPos = s.find(sub, sPos);
//                if(tmpPos == string::npos)
//                    return false;
//                else{
//                    sPos = tmpPos + sub.length();
//                    pPos = nextStarPos;
//                }
//
//                continue;
//            }
//
//            /* some char left in p but nothing in s */
//            if(sPos >= s.length())
//                return false;
//
//            /* nor ? or * */
//            if(s[sPos] == p[pPos]) {
//                ++pPos;
//                ++sPos;
//            }
//            else
//                return false;
//        }
//
//
//        return pPos >= p.length() && sPos >= s.length();
//    }
};

int main() {
    Solution sol;
    bool res = sol.isMatch("b", "*?*?");
    if (res) cout << "true" << endl;
    else cout << "false" << endl;
}