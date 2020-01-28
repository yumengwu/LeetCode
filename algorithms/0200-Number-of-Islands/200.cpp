#include "../header.h"

// BFS solution
// class Solution {
// public:
//     struct point {
//         int i;
//         int j;
//     };
//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.size() == 0) {
//             return 0;
//         }
//         int res = 0;
//         int n = grid.size(), m = grid[0].size();
//         queue<point> q;
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (grid[i][j] == '1') {
//                     point p;
//                     p.i = i;
//                     p.j = j;
//                     q.push(p);
//                     while (q.size()) {
//                         point pp = q.front();
//                         q.pop();
//                         if (pp.i > 0 && grid[pp.i - 1][pp.j] == '1') {
//                             grid[pp.i - 1][pp.j] = '0';
//                             point ppp;
//                             ppp.i = pp.i - 1;
//                             ppp.j = pp.j;
//                             q.push(ppp);
//                         }
//                         if (pp.i < n - 1 && grid[pp.i + 1][pp.j] == '1') {
//                             grid[pp.i + 1][pp.j] = '0';
//                             point ppp;
//                             ppp.i = pp.i + 1;
//                             ppp.j = pp.j;
//                             q.push(ppp);
//                         }
//                         if (pp.j > 0 && grid[pp.i][pp.j - 1] == '1') {
//                             grid[pp.i][pp.j - 1] = '0';
//                             point ppp;
//                             ppp.i = pp.i;
//                             ppp.j = pp.j - 1;
//                             q.push(ppp);
//                         }
//                         if (pp.j < m - 1 && grid[pp.i][pp.j + 1] == '1') {
//                             grid[pp.i][pp.j + 1] = '0';
//                             point ppp;
//                             ppp.i = pp.i;
//                             ppp.j = pp.j + 1;
//                             q.push(ppp);
//                         }
//                     }
//                     grid[i][j] = '1';
//                 }
//             }
//         }
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (grid[i][j] == '1') {
//                     res++;
//                 }
//             }
//         }
//         return res;
//     }
// };

// union find solution

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }
        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }
        vector<vector<int>> uf(m, vector<int>(n, -1));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    int temp = -1;
                    if (i > 0 && grid[i - 1][j] == '1') {
                        int up = find(uf, m, n, (i - 1) * n + j);
                        if (temp == -1) {
                            temp = up;
                        }
                    }
                    if (j > 0 && grid[i][j - 1] == '1') {
                        int left = find(uf, m, n, i * n + j - 1);
                        if (temp == -1) {
                            temp = left;
                        }
                        else {
                            uni(uf, m, n, left, temp);
                        }
                    }
                    if (temp != -1) {
                        uf[i][j] = temp;
                    }
                    else {
                        uf[i][j] = i * n + j;
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (uf[i][j] > -1 && uf[i][j] == i * n + j) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
    
    int find(vector<vector<int>> & uf, int m, int n, int index) {
        int temp = uf[index / n][index % n];
        if (temp == -1) {
            return -1;
        }
        else if (temp == index) {
            return temp;
        }
        else {
            return find(uf, m, n, temp);
        }
    }
    
    void uni(vector<vector<int>> & uf, int m, int n, int index, int target) {
        uf[index / n][index % n] = target;
    }
};

int main()
{
    return 0;
}