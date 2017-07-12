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
#include <set>
#include <map>

using namespace std;
class Solution {
    constexpr static int num_of_lines = 4;

    std::vector<std::vector<int>> lines;
    int total_sum;
    int line_sum;
public:
    Solution() {
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
    int least_length_needed() const {
        std::array<int, num_of_lines> line_lengths;
        for (int i = 0; i < line_lengths.size(); ++i) {
            line_lengths[i] = std::accumulate(lines[i].begin(), lines[i].end(), 0);
        }

        auto max_iter = std::max_element(line_lengths.begin(), line_lengths.end());
        int needed = 0;
        for(auto iter = line_lengths.begin(); iter != line_lengths.end(); ++iter){
            if(iter != max_iter)
                needed = needed + (*max_iter - *iter);
        }
        return needed;
    }
    void sort_lines(){
        std::sort(lines.begin(), lines.end(), [](const std::vector<int>& lhs, const std::vector<int>& rhs){
           return std::accumulate(lhs.begin(), lhs.end(), 0) < std::accumulate(rhs.begin(), rhs.end(), 0);
        });
    }
public:
    bool makesquare(vector<int> nums) {
        reset();

        if(nums.size() < 4)
            return false;

        total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % num_of_lines != 0) {
            std::cout << boost::format("[total_sum is %d, not mutiplies of %d, reminder is %d]\n")
                         % total_sum
                         % 4
                         % (total_sum%num_of_lines);
            return false;
        }
        line_sum = total_sum/ static_cast<int>(num_of_lines);



        auto b = recursive(nums.begin(), nums.end());
        return b;
    }

    bool recursive(vector<int>::iterator begin, vector<int>::iterator end) {
        int rest_element = std::distance(begin, end);

        // check if success
        if (rest_element == 0)
            return all_line_has_same_length();

        // pruning
        int unchecked_number_sum = std::accumulate(begin, end, 0);
        if (unchecked_number_sum < least_length_needed())
            return false;

        bool success = true;
//        sort_lines();
        for (int i = 0; i < lines.size(); ++i) {
            auto &line = lines[i];
            line.push_back(*begin);
            if (recursive(begin + 1, end) == false) {
                success = false;
            } else {
                return true;
            }
            line.pop_back();
        }
        return success;
    }
};

void benchmark(Solution& s, std::vector<int> input, bool expected){
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

    benchmark(s, {5969561, 8742425, 2513572, 3352059, 9084275, 2194427, 1017540, 2324577, 6810719, 8936380,
                  7868365, 2755770, 9954463, 9912280, 4713511}, false);
//
//    print_res(s.makesquare({2, 3, 4, 5, 1, 2, 3, 298, 32, 123, 123, 723, 1234,
//                            8713, 1278, 12378, 34728, 23748,78, 234781,4718347, 1427384
//                           }) == false);

    return 0;
}