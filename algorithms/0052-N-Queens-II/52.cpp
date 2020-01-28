#include "../header.h"

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<string> board(n, string(n, '.'));
        if (n == 0) {
            return ++res;
        }
        helper(res, board, n, 0);
        return res;
    }
    
    void helper(int & res, vector<string> & board, int n, int next) {
        if (next == n) {
            ++res;
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (check(board, next, i)) {
                board[next][i] = 'Q';
                helper(res, board, n, next + 1);
                board[next][i] = '.';
            }
        }
    }
    
    bool check(vector<string> & board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; ++i) {
            if (board[row][i] == 'Q') {
                return false;
            }
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};