#include <string>
#include <vector>
#include <iostream>

using namespace std;



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        // idx is the end char idx of the common string
        int idx = 0;
        for (idx = 0; idx < strs[0].length(); ++idx) {
            // test if the rest has same char with the first str.
            bool all_same = true;
            for (int j = 1; j < strs.size(); ++j) {
                if(strs[j].length() <= idx || strs[j].at(idx) != strs[0].at(idx))
                    all_same = false;
            }

            if(!all_same)
                break;
        }

        if(idx == 0)
            return "";
        else
            return strs[0].substr(0, idx);
    }
};

int main(){
    Solution s;
    vector<string> strs{"a"};
//    vector<string> strs{"abh", "bc", "ebd"};
//    vector<string> strs{"abh", "bc", "ebd"};

    cout << s.longestCommonPrefix(strs) << endl;


    return 0;
}