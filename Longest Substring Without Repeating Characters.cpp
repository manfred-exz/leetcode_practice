#include <cassert>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    class SubString{
        size_t begin, end;
        string& str_;
    public:
        SubString(string& str) : begin(0), end(0), str_(str) {}
        SubString& operator=(const SubString& rhs) {
            begin = rhs.begin;
            end = rhs.end;
            str_ = rhs.str_;
            return *this;
        }

        bool operator<(const SubString rhs) const {
            return this->length() < rhs.length();
        }
        bool operator>(const SubString rhs) const {
            return rhs.operator<(*this);
        }
        std::pair<bool, size_t> is_char_repeated(char to_check_char){
            for (size_t i = begin; i < end; ++i) {
                if(str_[i] == to_check_char)
                    return {true, i};
            }
            return {false, 0};
        };
        size_t length() const { return end - begin; }
        void clear_add_next_char(size_t repeated_char_index) { ++end; begin = repeated_char_index + 1; }
        void add_next_char(){
            ++end;
        }
    };
public:
    int lengthOfLongestSubstring(string s) {
        SubString longest(s), longest_tail(s);

        for(int i = 0; i < s.size(); ++i){
            const char curr = s[i];
            auto is_char_repeated = longest_tail.is_char_repeated(curr);
            if(is_char_repeated.first == false) {
                longest_tail.add_next_char();
            } else {
                longest_tail.clear_add_next_char(is_char_repeated.second);

            }
        if(longest_tail > longest)
            longest = longest_tail;
        }

        return static_cast<int>(longest.length());
    }
};

int main(){
    Solution s;
    assert(s.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(s.lengthOfLongestSubstring("bbbbb") == 1);
    assert(s.lengthOfLongestSubstring("pwwkew") == 3);
    assert(s.lengthOfLongestSubstring("dvdf") == 3);
    return 0;
}