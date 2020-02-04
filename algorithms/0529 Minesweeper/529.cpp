#include "../header.h"

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) {
            return {};
        }
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        helper(board, click[0], click[1]);
        return board;
    }
    
    void helper(vector<vector<char>>& b, int row, int col) {
        int m = b.size(), n = b[0].size();
        int cnt = 0;
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i < 0 || i >= m || j < 0 || j >= n || (i == row && j == col)) {
                    continue;
                }
                if (b[i][j] == 'M') {
                    ++cnt;
                }
            }
        }
        if (cnt) {
            b[row][col] = cnt + '0';
            return;
        }
        b[row][col] = 'B';
        for (int i = row - 1; i <= row + 1; ++i) {
            for (int j = col - 1; j <= col + 1; ++j) {
                if (i < 0 || i >= m || j < 0 || j >= n || (i == row && j == col)) {
                    continue;
                }
                if (b[i][j] == 'E') {
                   helper(b, i, j);
                }
            }
        }
    }
};