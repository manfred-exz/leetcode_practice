//
// Created by manfred-exz on 7/17/2017.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n == 0) return {};
        vector<int> res;
        recursive(res, 0, n);
        return res;
    }

    void recursive(vector<int>& res, int curr, int n) {
        if(curr > n) return;
        if(curr != 0) res.push_back(curr);

        if(curr * 10 <= n){
            for (int i = 0; i < 10; ++i) {
                if(curr == 0 && i == 0) continue;
                recursive(res, curr * 10 + i, n);
            }
        }
    }
};

int main(){
    Solution s;
    auto res = s.lexicalOrder(13);
    for(int i: res){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}