#include "../header.h"

class Solution {
public:
    struct point {
        int i;
        int j;
        point() {
            i = 0;
            j = 0;
        }
        point(int a, int b) {
            i = a;
            j = b;
        }
    };
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<point> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    point p(i, j);
                    q.push(p);
                }
            }
        }
        int cnt = 0;
        while (q.size()) {
            ++cnt;
            vector<point> v;
            while (q.size()) {
                v.push_back(q.front());
                q.pop();
            }
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].i > 0 && grid[v[i].i - 1][v[i].j] == 1) {
                    grid[v[i].i - 1][v[i].j] = 2;
                    point pp(v[i].i - 1, v[i].j);
                    q.push(pp);
                }
                if (v[i].i < n - 1 && grid[v[i].i + 1][v[i].j] == 1) {
                    grid[v[i].i + 1][v[i].j] = 2;
                    point pp(v[i].i + 1, v[i].j);
                    q.push(pp);
                }
                if (v[i].j > 0 && grid[v[i].i][v[i].j - 1] == 1) {
                    grid[v[i].i][v[i].j - 1] = 2;
                    point pp(v[i].i, v[i].j - 1);
                    q.push(pp);
                }
                if (v[i].j < m - 1 && grid[v[i].i][v[i].j + 1] == 1) {
                    grid[v[i].i][v[i].j + 1] = 2;
                    point pp(v[i].i, v[i].j + 1);
                    q.push(pp);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return cnt > 0 ? cnt - 1 : 0;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{0,2,2}};
    cout<<s.orangesRotting(v)<<endl;
    return 0;
}