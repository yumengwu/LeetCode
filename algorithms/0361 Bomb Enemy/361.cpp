#include "../header.h"

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) {
            return 0;
        }
        int m = grid[0].size();
        if (m == 0) {
            return 0;
        }
        vector<vector<int>> vu(n, vector<int>(m, 0)), vd(n, vector<int>(m, 0)), vl(n, vector<int>(m, 0)), vr(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 'W') {
                    int temp;
                    temp = i == 0 ? 0 : vu[i - 1][j];
                    vu[i][j] = grid[i][j] == 'E' ? temp + 1 : temp;
                    temp = j == 0 ? 0 : vl[i][j - 1];
                    vl[i][j] = grid[i][j] == 'E' ? temp + 1 : temp;
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (grid[i][j] != 'W') {
                    int temp;
                    temp = i == n - 1 ? 0 : vd[i + 1][j];
                    vd[i][j] = grid[i][j] == 'E' ? temp + 1 : temp;
                    temp = j == m - 1 ? 0 : vr[i][j + 1];
                    vr[i][j] = grid[i][j] == 'E' ? temp + 1 : temp;
                }
            }
        }
        int curm = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') {
                    curm = max(curm, vu[i][j] + vd[i][j] + vl[i][j] + vr[i][j]);
                }
            }
        }
        return curm;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> v{ {'0','E','0','0'},
                            {'E','0','W','E'},
                            {'0','E','0','0'}};
    cout<<s.maxKilledEnemies(v)<<endl;
    return 0;
}