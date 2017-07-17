//
// Created by manfred-exz on 7/17/2017.
//

#include <vector>
#include <cmath>
#include <iostream>

class Solution {
public:
    int get_bit(int data, int index){
        return (data >> index) & 0x1;
    }

    void set_bit(int &data, int index){
        data |= (0x1 << index);
    }

    void clear_bit(int &data, int index) {
        data &= ~(0x1 << index);
    }

    int recursive(int& curr, int bit_index, int num) {
        if(curr > num) return 0;
        if(bit_index < 0) {
            if(curr <= num) return 1;
            else return 0;
        }

        int one = 0, zero = 0;
        if(get_bit(curr, bit_index+1) == 0 || curr == 0) {
            set_bit(curr, bit_index);
            one = recursive(curr, bit_index - 1, num);
        }
        clear_bit(curr, bit_index);
        zero = recursive(curr, bit_index-1, num);
        return one + zero;
    }

    int findIntegers(int num) {
        if(num == 0) return 1;
        if(num == 1) return 2;
        int curr = 0;
        return recursive(curr, log2(num), num);
    }
};

int main(){
    Solution s;
    std::cout << s.findIntegers(5) << std::endl;
    std::cout << s.findIntegers(6) << std::endl;
    std::cout << s.findIntegers(7) << std::endl;
    std::cout << s.findIntegers(8) << std::endl;
    std::cout << s.findIntegers(9) << std::endl;
    std::cout << s.findIntegers(10) << std::endl;
    std::cout << s.findIntegers(11) << std::endl;
    std::cout << s.findIntegers(12) << std::endl;
    std::cout << s.findIntegers(13) << std::endl;
    std::cout << s.findIntegers(14) << std::endl;
    std::cout << s.findIntegers(15) << std::endl;
    std::cout << s.findIntegers(16) << std::endl;
    return 0;
}