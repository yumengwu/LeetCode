#include "../header.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len = word.length();
        if (len == 0) {
            return false;
        }
        int m = board.size();
        if (m == 0) {
            return false;
        }
        int n = board[0].size();
        if (n == 0) {
            return false;
        }
        if (m * n < word.length()) {
            return false;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (helper(board, m, n, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char>>& board, int m, int n, int i, int j, string word, int start) {
        if (start == word.length() - 1) {
            return board[i][j] == word[start];
        }
        if (board[i][j] == word[start]) {
            char temp = board[i][j];
            board[i][j] = '.';
            bool equal = false;
            if ((!equal) && i > 0) {
                equal |= helper(board, m, n, i - 1, j, word, start + 1);
            }
            if ((!equal) && i < m - 1) {
                equal |= helper(board, m, n, i + 1, j, word, start + 1);
            }
            if ((!equal) && j > 0) {
                equal |= helper(board, m, n, i, j - 1, word, start + 1);
            }
            if ((!equal) && j < n - 1) {
                equal |= helper(board, m, n, i, j + 1, word, start + 1);
            }
            board[i][j] = temp;
            return equal;
        }
        else {
            return false;
        }
    }
};