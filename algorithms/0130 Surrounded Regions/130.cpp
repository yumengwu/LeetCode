#include "../header.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m = board.size();
        if (m == 0) {
            return;
        }
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O') {
                    board[i][j] = '.';
                    q.push(make_pair(i, j));
                    while (q.size()) {
                        pair<int, int> p = q.front();
                        q.pop();
                        if (p.first > 0 && board[p.first - 1][p.second] == 'O') {
                            board[p.first - 1][p.second] = '.';
                            q.push(make_pair(p.first - 1, p.second));
                        }
                        if (p.first < m - 1 && board[p.first + 1][p.second] == 'O') {
                            board[p.first + 1][p.second] = '.';
                            q.push(make_pair(p.first + 1, p.second));
                        }
                        if (p.second > 0 && board[p.first][p.second - 1] == 'O') {
                            board[p.first][p.second - 1] = '.';
                            q.push(make_pair(p.first, p.second - 1));
                        }
                        if (p.second < n - 1 && board[p.first][p.second + 1] == 'O') {
                            board[p.first][p.second + 1] = '.';
                            q.push(make_pair(p.first, p.second + 1));
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<char>> v{{'X','O','O','X','X','X','O','X','O','O'},{'X','O','X','X','X','X','X','X','X','X'},{'X','X','X','X','O','X','X','X','X','X'},{'X','O','X','X','X','O','X','X','X','O'},{'O','X','X','X','O','X','O','X','O','X'},{'X','X','O','X','X','O','O','X','X','X'},{'O','X','X','O','O','X','O','X','X','O'},{'O','X','X','X','X','X','O','X','X','X'},{'X','O','O','X','X','O','X','X','O','O'},{'X','X','X','O','O','X','O','X','X','O'}};
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<"-------------------\n";
    s.solve(v);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[0].size(); ++j) {
            cout<<v[i][j];
        }
        cout<<endl;
    }
    return 0;
}