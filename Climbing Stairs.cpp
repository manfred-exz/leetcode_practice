//
// Created by manfred on 7/11/2017.
//
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> num_of_ways(n+1);
        num_of_ways[0] = 1;
        num_of_ways[1] = 1;

        for (int i = 2; i <= n; ++i) {
            num_of_ways[i] = num_of_ways[i-1] + num_of_ways[i-2];
        }

        return num_of_ways[n];
    }
};

int main(){
}