//
// Created by manfred-exz on 7/19/2017.
//
#include <vector>
#include <array>
#include <cassert>
#include <iostream>

using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        auto check_curr = [](std::array<bool, 9>& is_filled, char curr) -> bool {
            if(curr == '.')
                return true;
            else if(is_filled[curr - '1'] == true)
                return false;
            else {
                is_filled[curr - '1'] = true;
                return true;
            }
        };

        // check cols
        for (int col = 0; col < 9; ++col) {
            std::array<bool, 9> is_filled;
            is_filled.fill(false);
            for (int row = 0; row < 9; ++row) {
                if(check_curr(is_filled, board[row][col]) == false)
                    return false;
            }
        }
        // check rows
        for (int row = 0; row < 9; ++row) {
            std::array<bool, 9> is_filled;
            is_filled.fill(false);
            for (int col = 0; col < 9; ++col) {
                if(check_curr(is_filled, board[row][col]) == false)
                    return false;
            }
        }
        // check grids
        for (int grid_row = 0; grid_row < 3; ++grid_row) {
            for (int grid_col = 0; grid_col < 3; ++grid_col) {
                std::array<bool, 9> is_filled;
                is_filled.fill(false);
                for (int row = grid_row * 3; row < grid_row * 3 + 3; ++row) {
                    for (int col = grid_col * 3; col < grid_col * 3 + 3; ++col) {
                        if(check_curr(is_filled, board[row][col]) == false)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};

bool Call(std::vector<string> input){
    assert(input.size() == 9);
    vector<vector<char>> board(9, std::vector<char>(9));
    for (int row = 0; row < input.size(); ++row) {
        for (size_t col = 0; col < input[row].size(); ++col) {
            board[row][col] = input[row].at(col);
        }
    }

    Solution s;
    return s.isValidSudoku(board);
}

int main(){
    std::cout << boolalpha;
    std::cout << Call({".87654321","2........","3........","4........","5........","6........","7........","8........","9........"}) << std::endl;

    return 0;
}