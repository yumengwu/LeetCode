#include "../header.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for (int i = 0; i < 9; ++i) {
            s.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (s.find(board[i][j]) != s.end()) {
                        return false;
                    }
                    s.insert(board[i][j]);
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            s.clear();
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (s.find(board[j][i]) != s.end()) {
                        return false;
                    }
                    s.insert(board[j][i]);
                }
            }
        }
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                s.clear();
                for (int ii = i * 3; ii < i * 3 + 3; ++ii) {
                    for (int jj = j * 3; jj < j * 3 + 3; ++jj) {
                        if (board[ii][jj] != '.') {
                            if (s.find(board[ii][jj]) != s.end()) {
                                return false;
                            }
                            s.insert(board[ii][jj]);
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}