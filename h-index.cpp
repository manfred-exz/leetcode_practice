//
// Created by manfred on 11/24/2015.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        map<int, int> counter;

        sort(citations.begin(), citations.end(), std::greater<int>());

        

        for (auto item : citations)
            cout << item << " " ;

        cout << endl;
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> vec{3, 0, 6, 1, 5};

    std::cout << s.hIndex(vec) << std::endl;

    return 0;
}