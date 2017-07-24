//
// Created by manfred on 7/16/17.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define OUTPUT_DEBUG_STR

struct value_to_list_index_pair {
    int value, list_index;
};

struct window {
    std::vector<value_to_list_index_pair>& data;

    // runtime
    int begin, end;
    bool cache = false;
    std::vector<int> count_num_from_list;
    int head_num_list;  // there must be only one number from [head_num_list] in a valid range

    int smallest_begin, smallest_end;

    window(size_t num_of_list, std::vector<value_to_list_index_pair>& data)
        : begin(0), end(0), count_num_from_list(num_of_list, 0), head_num_list(-1), data(data),
          smallest_begin(0), smallest_end(static_cast<int>(data.size()))
    {}

    bool is_valid_range(){
        if(!cache)
            cache = std::all_of(count_num_from_list.begin(), count_num_from_list.end(), [](int rhs){ return rhs > 0; });
        return cache;
    }

    bool has_next(){
        return end < data.size();
    }

    bool check_smallest(int begin, int end) {
        if (data[end-1].value - data[begin].value == data[smallest_end-1].value - data[smallest_begin].value)
            return data[begin].value < data[smallest_begin].value;

        return data[end-1].value - data[begin].value < data[smallest_end-1].value - data[smallest_begin].value;
    }

    bool check_and_set_smallest(int begin, int end){
        bool b = check_smallest(begin, end);
        if(b){
            smallest_begin = begin;
            smallest_end = end;
        }
        return b;
    }

    void move_begin() {
        --count_num_from_list[data[begin].list_index];
        ++begin;
        head_num_list = data[begin].list_index;
    }

    void move_end() {
        ++end;
        ++count_num_from_list[data[end-1].list_index];
    }

    void move_to_next(){
        move_end();
        if(end - begin == 1) {
            head_num_list = data[begin].list_index;
            return;
        }

        auto& curr = data[end-1];
#ifdef OUTPUT_DEBUG_STR
        std::cout << "met num: " << curr.value << ", from list " << curr.list_index;
#endif
        // only when we shrink the size from begin, can we get a smaller range
        if(curr.list_index == head_num_list){
#ifdef OUTPUT_DEBUG_STR
            std::cout << " make current range shrink to (" << data[begin].value << ", " << data[end - 1].value << ")";
#endif
            // move begin
            while(count_num_from_list[head_num_list] >= 2)
                move_begin();
            // check if we have smaller range
            if(is_valid_range()) {
                bool res = check_and_set_smallest(begin, end);
#ifdef OUTPUT_DEBUG_STR
                if(res)
                    std::cout << " make smallest range shrink to (" << data[smallest_begin].value << ", "
                              << data[smallest_end - 1].value << ")";
#endif
            }
        }

#ifdef OUTPUT_DEBUG_STR
        std::cout << std::endl;
#endif
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>> nums) {
        std::vector<value_to_list_index_pair> value_list_map;
        for (int i = 0; i < nums.size(); ++i) {
            vector<int> &list = nums[i];
            for (int j = 0; j < list.size(); ++j) {
                value_list_map.push_back({list[j], i});
            }
        }


        std::sort(value_list_map.begin(), value_list_map.end(),
                  [](const value_to_list_index_pair &lhs, const value_to_list_index_pair &rhs) {
                      return lhs.value < rhs.value;
                  });

        window w(nums.size(), value_list_map);
        while(w.has_next()){
            w.move_to_next();
        }
        return {value_list_map[w.smallest_begin].value, value_list_map[w.smallest_end-1].value};
    }
};

int main(){
    Solution s;
    auto res = s.smallestRange({{10, 10}, {11, 11}});
    std::cout << res[0] << ", " << res[1] << std::endl;
}