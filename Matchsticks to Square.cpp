//
// Created by manfred-exz on 6/28/2017.
//

/*
 * Solve Log
 * analyse:
 *      1. combine into 4 equal number. so the result will be 4 group of numbers, each add up to the same sum
 *      2. other than the biggest 4 numbers, the rest must be added to those 4 numbers
 * */
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <iostream>
#include <functional>
#include <chrono>
#include <boost/format.hpp>

using namespace std;
class Solution {
    std::vector<std::vector<int>> lines;
    size_t num_of_lines;
    int total_sum;
    int line_sum;
public:
    Solution() : num_of_lines(4) {
        lines.resize(num_of_lines);
    }
    bool all_line_has_same_length() const {
        return std::all_of(lines.begin(), lines.end(), [this](const std::vector<int>& rhs){
            return std::accumulate(rhs.begin(), rhs.end(), 0) == line_sum;
        });
    }
    void reset(){
        lines.clear();
        lines.resize(4);
        total_sum = line_sum = 0;
    }

public:
    bool makesquare(const vector<int>& nums) {
        reset();
        total_sum = std::accumulate(nums.begin(), nums.end(), 0);
//        if(total_sum % num_of_lines != 0)
//            return false;
        line_sum = total_sum/ static_cast<int>(num_of_lines);
        auto b = recursive(nums.begin(), nums.end());
        return b;
    }

    bool recursive(vector<int>::const_iterator begin, vector<int>::const_iterator end){
        if(begin == end)
            return all_line_has_same_length();

        bool success = true;
        for (int i = 0; i < lines.size(); ++i) {
            auto& line = lines[i];
            line.push_back(*begin);
            if(recursive(begin+1, end) == false) {
                success = false;
            } else {
                return true;
            }
            line.pop_back();
        }
        return success;
    }
};

void print_res(bool b){
    std::cout << b << std::endl;
}

void benchmark(Solution& s, const std::vector<int>& input, bool expected){
    using namespace std::chrono;
    auto start_time = system_clock::now();
    bool res = s.makesquare(input);
    auto end_time = system_clock::now();

    std::cout << boost::format("res: %s.\t\ttime used: %8d micros.\n")
                             % (res == expected ? "success" : "failed")
                             % duration_cast<microseconds>(end_time - start_time).count();
}

int main(){
    std::cout << std::boolalpha << std::scientific;

    Solution s;
    benchmark(s, {1, 1, 2, 2, 2}, true);
    benchmark(s, {3, 3, 3, 3, 4}, false);
    benchmark(s, {1, 1, 1, 1}, true);
    benchmark(s, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, true);
    benchmark(s, {1, 1, 1, 1, 1, 1, 1, 1, 1}, false);
//
//    print_res(s.makesquare({2, 3, 4, 5, 1, 2, 3, 298, 32, 123, 123, 723, 1234,
//                            8713, 1278, 12378, 34728, 23748,78, 234781,4718347, 1427384
//                           }) == false);

    return 0;
}