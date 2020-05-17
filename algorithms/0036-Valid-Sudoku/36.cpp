#include "../header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            bool cs[9] = {false};
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                if (cs[board[i][j] - '1']) {
                    return false;
                }
                cs[board[i][j] - '1'] = true;
            }
        }
        for (int i = 0; i < 9; ++i) {
            bool cs[9] = {false};
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.') {
                    continue;
                }
                if (cs[board[j][i] - '1']) {
                    return false;
                }
                cs[board[j][i] - '1'] = true;
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                bool cs[9] = {false};
                for (int ii = i * 3; ii < i * 3 + 3; ++ii) {
                    for (int jj = j * 3; jj < j * 3 + 3; ++jj) {
                        if (board[ii][jj] == '.') {
                            continue;
                        }
                        if (cs[board[ii][jj] - '1']) {
                            return false;
                        }
                        cs[board[ii][jj] - '1'] = true;
                    }
                }
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char st[9];
        for (int i = 0; i < 9; ++i) {
            memset(st, 0, 9);
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (st[board[i][j] - '1']) {
                        return false;
                    }
                    st[board[i][j] - '1'] = 1;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            memset(st, 0, 9);
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (st[board[j][i] - '1']) {
                        return false;
                    }
                    st[board[j][i] - '1'] = 1;
                }
            }
        }
        for (int ii = 0; ii < 3; ++ii) {
            for (int jj = 0; jj < 3; ++jj) {
                memset(st, 0, 9);
                for (int i = ii * 3; i < ii * 3 + 3; ++i) {
                    for (int j = jj * 3; j < jj * 3 + 3; ++j) {
                        if (board[i][j] != '.') {
                            if (st[board[i][j] - '1']) {
                                return false;
                            }
                            st[board[i][j] - '1'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};*/

int main()
{
    return 0;
}
