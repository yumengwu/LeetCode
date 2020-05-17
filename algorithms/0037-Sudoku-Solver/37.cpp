#include "../header.h"

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> v;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    v.push_back(make_pair(i, j));
                }
            }
        }
        helper(board, v, 0);
    }
    
    bool helper(vector<vector<char>>& b, vector<pair<int, int>> & v, int next) {
        if (next == v.size()) {
            return true;
        }
        pair<int, int> cur = v[next];
        for (int i = 0; i < 9; ++i) {
            if (check(b, cur.first, cur.second, i + '1')) {
                b[cur.first][cur.second] = i + '1';
                if (helper(b, v, next + 1)) {
                    return true;
                }
                b[cur.first][cur.second] = '.';
            }
        }
        return false;
    }
    
    bool check(vector<vector<char>>& b, int row, int col, char val) {
        for (int i = 0; i < 9; ++i) {
            if (b[i][col] == val || b[row][i] == val) {
                return false;
            }
        }
        int ii = 3 * (row / 3), jj = 3 * (col / 3);
        for (int i = ii; i < ii + 3; ++i) {
            for (int j = jj; j < jj + 3; ++j) {
                if (b[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> v;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    v.push_back({i, j});
                }
            }
        }
        helper(board, v, 0);
    }
    
    bool helper(vector<vector<char>>& board, vector<vector<int>>& v, int start) {
        if (start >= v.size()) {
            return true;
        }
        for (char c = '1'; c <= '9'; ++c) {
            if (checkAt(board, v[start][0], v[start][1], c)) {
                board[v[start][0]][v[start][1]] = c;
                if (helper(board, v, start + 1)) {
                    return true;
                }
                board[v[start][0]][v[start][1]] = '.';
            }
        }
        return false;
    }
    
    bool checkAt(vector<vector<char>>& board, int row, int col, char val) {
        for (int i = 0; i < 9; ++i) {
            if (i != col && board[row][i] == val) {
                return false;
            }
        }
        for (int i = 0; i < 9; ++i) {
            if (i != row && board[i][col] == val) {
                return false;
            }
        }
        int ii = 3 * (row / 3), jj = 3 * (col / 3);
        for (int i = ii; i < ii + 3; ++i) {
            for (int j = jj; j < jj + 3; ++j) {
                if (i != row && j != col && board[i][j] == val) {
                    return false;
                }
            }
        }
        return true;
    }
};*/

