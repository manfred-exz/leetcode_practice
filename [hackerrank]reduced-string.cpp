//
// Created by manfred on 7/23/2017.
//

#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){
    int idx = 1;
    while(idx < s.length()) {
        if(idx >= 1 && s[idx] == s[idx-1]){
            s.erase(s.begin() + idx);
            s.erase(s.begin() + idx-1);
            idx = idx - 1;
        } else {
            idx += 1;
        }
    }
    if(s.empty()) s = "Empty String";
    return s;
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
