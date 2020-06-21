#include "../header.h"

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0, m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (i == 0 || grid[i - 1][j] == 0)
                        ++cnt;
                    if (i == m - 1 || grid[i + 1][j] == 0)
                        ++cnt;
                    if (j == 0 || grid[i][j - 1] == 0)
                        ++cnt;
                    if (j == n - 1 || grid[i][j + 1] == 0)
                        ++cnt;
                }
            }
        }
        return cnt;
    }
};

