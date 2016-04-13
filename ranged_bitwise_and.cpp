//
// Created by manfred on 4/13/2016.
//

#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m > n) return 0;
        if(m == n) return m;

        unsigned int start = (unsigned int) m;
        int len = n - m + 1;
        int diff = n - m;

        /* there's a lot of 0s at the end */
        int num_zero_bits = int(log2(len-1)) + 1;
        unsigned int res = 0;

        for(int curr_bit_pos = num_zero_bits; curr_bit_pos <= int(log2(start)); ++curr_bit_pos){
            int curr_bit = get_bit(start, curr_bit_pos);
            int curr_endings = get_endings(start, curr_bit_pos + 1);

            if(curr_bit == 1 && curr_endings + diff < exp2(curr_bit_pos +1))
                set_bit(res, curr_bit_pos);
        }

        return res;
    }
private:
    unsigned int get_bit(unsigned int num, int pos){
        unsigned int mask = 1u << pos;
        return (num & mask) == 0 ? 0 : 1;
    }

    unsigned int get_endings(unsigned int num, int num_of_endings){
        int mask = 0;
        while(num_of_endings--){
            mask <<= 1;
            mask |= 1;
        }

        return num & mask;
    }

    void set_bit(unsigned int& num, int pos){
        num |= (1 << pos);
    }

};

int main(){
    Solution s;

    cout << s.rangeBitwiseAnd(4, 5) << endl;

    return 0;
}