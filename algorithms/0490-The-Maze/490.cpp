#include "../header.h"

class Solution {
public:
    vector<vector<int>> direc{{0,-1},{-1,0},{0,1},{1,0}};
    
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return helper(maze, start[0], start[1], destination[0], destination[1]);
    }
    
    bool helper(vector<vector<int>>& maze, int si, int sj, int di, int dj) {
        if (si == di && sj == dj) return true;
        bool res = false;
        int m = maze.size(), n = maze[0].size();
        maze[si][sj] = -1;
        for (int i = 0; i < direc.size(); ++i) {
            int x = si, y = sj;
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] != 1) {
                x += direc[i][0];
                y += direc[i][1];
            }
            x -= direc[i][0];
            y -= direc[i][1];
            if (maze[x][y] != -1) {
                res |= helper(maze, x, y, di, dj);
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    return 0;
}