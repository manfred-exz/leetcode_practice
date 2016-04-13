//
// Created by manfred on 12/19/2015.
//

/* https://leetcode.com/problems/sqrtx/ */
/* use newton's iterative method to solve the function f(x) = x^2 - n; f(x) = 0; */
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;

        double lastX = 0;
        double testX = 1;

        while(testX != lastX){
            lastX = testX;
            testX = (testX + x/testX) / 2;
        }

        return int(testX);
    }
};