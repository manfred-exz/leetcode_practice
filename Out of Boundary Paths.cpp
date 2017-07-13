//
// Created by manfred-exz on 7/13/2017.
//

/* the number will overflow if you use int32_t, should use uint32_t or larger types */

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

class Grid {
    std::vector<std::vector<unsigned int>> num_of_paths;
    int num_rows_, num_cols_;
public:
    Grid(int num_rows, int num_cols)
            : num_rows_(num_rows), num_cols_(num_cols) {
        num_of_paths.resize(num_rows);
        for (auto &row: num_of_paths)
            row.resize(num_cols, 0);
    }

    int num_rows() const {
        return num_rows_;
    }

    int num_cols() const {
        return num_cols_;
    }

    int At(int row, int col) {
        if (row < 0 || row >= num_rows() || col < 0 || col >= num_cols()) return 1;
        return num_of_paths[row][col];
    }

    unsigned int &GetRef(int row, int col) {
        return num_of_paths[row][col];
    }

    void MarkBoundary() {
        for (int i = 0; i < num_rows_; ++i) {
            for (int j = 0; j < num_cols_; ++j) {
                unsigned int &ref = GetRef(i, j);
                if(i == 0) ref += 1;
                if(i == num_rows_ - 1) ref += 1;
                if(j == 0) ref += 1;
                if(j == num_cols_ - 1) ref += 1;
            }
        }
    }
};

class Grids {
    std::vector<Grid> grids_;
public:
    Grids(int N, int num_rows, int num_cols) {
        grids_.resize(N, Grid(num_rows, num_cols));
        AtNumOfMove(1).MarkBoundary();
        for (int i = 2; i <= N; ++i) {
            CalcNumOfMove(i);
        }
    }

    Grid &AtNumOfMove(int rest_moves) {
        assert(rest_moves >= 1);
        return grids_[rest_moves - 1];
    }

    void CalcNumOfMove(int rest_moves) {
        assert(rest_moves >= 2);
        Grid &grid = AtNumOfMove(rest_moves);
        Grid &prev_grid = AtNumOfMove(rest_moves - 1);
        for (int row = 0; row < grid.num_rows(); ++row) {
            for (int col = 0; col < grid.num_cols(); ++col) {
                grid.GetRef(row, col) = (prev_grid.At(row-1, col) + prev_grid.At(row+1, col)
                        + prev_grid.At(row, col-1) + prev_grid.At(row, col+1)) % 1000000007u;
            }
        }
    }
};

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N <= 0) return 0;
        Grids grids(N, m, n);
        return grids.AtNumOfMove(N).At(i, j);
    }
};

int main(){
    Solution s;
    std::cout << s.findPaths(2, 2, 2, 0, 0) << std::endl;
    std::cout << s.findPaths(1, 3, 3, 0, 1) << std::endl;
    std::cout << s.findPaths(10, 10, 10, 0, 0) << std::endl;
    std::cout << s.findPaths(36, 5, 50, 15, 3) << std::endl;
    std::cout << s.findPaths(50, 50, 50, 0, 0) << std::endl;
    return 0;
}