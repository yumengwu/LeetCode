#include "../header.h"

class Solution {
public:
    struct point {
        int i;
        int j;
    };
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) {
            return 0;
        }
        int res = 0;
        int n = grid.size(), m = grid[0].size();
        queue<point> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    point p;
                    p.i = i;
                    p.j = j;
                    q.push(p);
                    while (q.size()) {
                        point pp = q.front();
                        q.pop();
                        if (pp.i > 0 && grid[pp.i - 1][pp.j] == '1') {
                            grid[pp.i - 1][pp.j] = '0';
                            point ppp;
                            ppp.i = pp.i - 1;
                            ppp.j = pp.j;
                            q.push(ppp);
                        }
                        if (pp.i < n - 1 && grid[pp.i + 1][pp.j] == '1') {
                            grid[pp.i + 1][pp.j] = '0';
                            point ppp;
                            ppp.i = pp.i + 1;
                            ppp.j = pp.j;
                            q.push(ppp);
                        }
                        if (pp.j > 0 && grid[pp.i][pp.j - 1] == '1') {
                            grid[pp.i][pp.j - 1] = '0';
                            point ppp;
                            ppp.i = pp.i;
                            ppp.j = pp.j - 1;
                            q.push(ppp);
                        }
                        if (pp.j < m - 1 && grid[pp.i][pp.j + 1] == '1') {
                            grid[pp.i][pp.j + 1] = '0';
                            point ppp;
                            ppp.i = pp.i;
                            ppp.j = pp.j + 1;
                            q.push(ppp);
                        }
                    }
                    grid[i][j] = '1';
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    res++;
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}