#include "../header.h"

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) {
            return;
        }
        int n = rooms[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) {
                    helper(rooms, i - 1, j, 1);
                    helper(rooms, i + 1, j, 1);
                    helper(rooms, i, j - 1, 1);
                    helper(rooms, i, j + 1, 1);
                }
            }
        }
    }
    
    void helper(vector<vector<int>>& rooms, int i, int j, int val) {
        int m = rooms.size(), n = rooms[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] < 0) {
            return;
        }
        if (val < rooms[i][j]) {
            rooms[i][j] = val;
            helper(rooms, i - 1, j, val + 1);
            helper(rooms, i + 1, j, val + 1);
            helper(rooms, i, j - 1, val + 1);
            helper(rooms, i, j + 1, val + 1);
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{2147483647,-1,0,2147483647},
                        {2147483647,2147483647,2147483647,-1},
                        {2147483647,-1,2147483647,-1},
                        {0,-1,2147483647,2147483647}};
    s.wallsAndGates(v);
    return 0;
}