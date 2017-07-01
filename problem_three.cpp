//
// Created by manfred on 7/9/2016.
//
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;



struct Pos{
    size_t row, col;
};

class Board{
public:
    vector<vector<char>> data;
    size_t num_row, num_col;
    size_t down_cnt;

    Board(size_t row, size_t col){
        num_row = row;
        num_col = col;
        down_cnt = 0;

        data.resize(row);
        for (int i = 0; i < data.size(); ++i) {
            data[i].resize(col, '?');
        }
    }

    char& at(const Pos &pos){
        return data[pos.row][pos.col];
    }

    char& at(const size_t row, const size_t col){
        return data[row][col];
    }

    Pos nextPos(Pos pos){
        if(pos.col < num_col-1)
            pos.col += 1;
        else{
            pos.col = 0;
            if(pos.row < num_row-1)
                pos.row += 1;
            else
                pos.row = 0;
        }

        return pos;
    }

    Pos nextPos(Pos pos, char inst){
        if(inst == 'R' && pos.col < num_col-1)
            pos.col += 1;
        else if(inst == 'C' && pos.row < num_row-1)
            pos.row += 1;
        else
            pos = nextPos(pos);
        return pos;
    }

    Pos nextNotDownPos(Pos pos){
        pos = nextPos(pos);
        while(at(pos) == 'D')
            pos = nextPos(pos);
        return pos;
    };

    bool isLastPos(Pos pos){
        return pos.row == num_row-1 && pos.col == num_col-1;
    }

    bool allDown(){
        return down_cnt == num_row * num_col;
    }

    void makeDown(Pos pos){
        at(pos) = 'D';
        down_cnt += 1;
    }
};

void proceed(Board &board, Pos &pos, double &numTouches);

void proceed(Board &board, Pos &pos, double &numTouches) {
    double expectation;

    if(board.allDown())
        return;

    if(board.isLastPos(pos)){
        board.makeDown(pos);
        pos = {0, 0};
        if(!board.allDown())
            numTouches += 1;
        return;
    }

    char curr = board.at(pos);
    switch (curr){
        case 'R':
            board.makeDown(pos);
            pos = board.nextPos(pos, 'R');
            break;
        case 'C':
            board.makeDown(pos);
            pos = board.nextPos(pos, 'C');
            break;
        case 'D':
            pos = board.nextNotDownPos(pos);
            break;
        case '?':
            Board boardR(board), boardC(board);
            boardR.at(pos) = 'R';
            boardC.at(pos) = 'C';
            double numTouchR = numTouches, numTouchC = numTouches;
            Pos posR = pos, posC = pos;
            proceed(boardR, posR, numTouchR);
            proceed(boardC, posC, numTouchC);

            numTouches = 0.5 * (numTouchR + numTouchC);
            break;
        default:
            return;
    }

}


int main(){
    /* input */
    size_t num_col, num_row;
    cin >> num_row >> num_col;
    Board board(num_row, num_col);

    for (int i = 0; i < board.num_row; ++i) {
        for (int j = 0; j < board.num_col; ++j) {
            cin >> board.at(i, j);
        }
    }

    Pos pos{0, 0};
    double numOfTouches = 1;
    while(!board.allDown()){
        proceed(board, pos, numOfTouches);
    }

    cout << numOfTouches << endl;


    return 0;
}

