#include "../header.h"

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cur = cnt(board, i, j, m, n);
                if (board[i][j] == 1) {
                    if (cur < 2 || cur > 3) {
                        board[i][j] = 3;
                    }
                }
                else {
                    if (cur == 3) {
                        board[i][j] = 2;
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
                else if (board[i][j] == 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
    
    int cnt(vector<vector<int>>& b, int row, int col, int m, int n) {
        int c = 0;
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i >= 0 && i < m && j >= 0 && j < n) {
                    if (i == row && j == col) {
                        continue;
                    }
                    c += b[i][j] % 2;
                }
            }
        }
        return c;
    }
};