#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result = vector<int>();
        /* empty matrix */
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return result;

        unsigned long bottom_limit = matrix.size() - 1;
        unsigned long right_limit = matrix[0].size() - 1;
        unsigned long top_limit = 0, left_limit = 0;
        int x = 0, y = 0;

        /* a single row */
        if(bottom_limit == top_limit) {
            for (int i = 0; i < matrix[0].size(); ++i) {
                result.push_back(matrix[0][i]);
            }
            return result;
        }

        /* a single column */
        if(left_limit == right_limit){
            for (int i = 0; i < matrix.size(); ++i) {
                result.push_back(matrix[i][0]);
            }
            return result;

        }

        int cnt = 0;
        while(true){
            while(x < right_limit){
                result.push_back(matrix[y][x]);
                ++cnt;
                ++x;
            }

            while(y < bottom_limit){
                result.push_back(matrix[y][x]);
                ++cnt;
                ++y;
            }

            if(top_limit != bottom_limit) {
                while (x > left_limit) {
                    result.push_back(matrix[y][x]);
                    ++cnt;
                    --x;
                }
            }

            if(left_limit != right_limit) {
                while (y > top_limit) {
                    result.push_back(matrix[y][x]);
                    ++cnt;
                    --y;
                }
            }

            ++top_limit;
            ++left_limit;
            --bottom_limit;
            --right_limit;

            if(top_limit > bottom_limit || left_limit > right_limit)
                break;

            ++y;
            ++x;
        }

        if(cnt != matrix.size() * matrix[0].size())
            result.push_back(matrix[y][x]);


        return result;

    }
};

int main() {
    auto solution = Solution();

    auto matrix = vector<vector<int>>();
    int width = 5, height = 3;
    for (int i = 0; i < height; ++i) {
        vector<int> row;
        for (int j = 0; j < width; ++j) {
            row.push_back(i * width + j);
            printf("%3d ", i * width + j);
        }
        matrix.push_back(row);
        putchar('\n');
    }

    auto result = solution.spiralOrder(matrix);

    for (int i = 0; i < result.size(); ++i) {
        printf("%d ", result[i]);
    }

    return 0;
}

