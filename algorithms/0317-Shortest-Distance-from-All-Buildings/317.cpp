#include "../header.h"

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return -1;
        }
        int n = grid[0].size();
        if (n == 0) {
            return -1;
        }
        int cntb = 0;
        vector<vector<pair<int, int>>> v(m, vector<pair<int, int>>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    v[i][j].first = grid[i][j];
                    if (grid[i][j] == 1) ++cntb;
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j].first == 1) {
                    bfs(v, i, j, m, n);
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (v[i][j].first < 0 && v[i][j].second == cntb) {
                    res = min(res, -v[i][j].first);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    
    void bfs(vector<vector<pair<int, int>>>& v, int r, int c, int m, int n) {
        queue<pair<int, int>> q;
        q.push(make_pair(r, c));
        set<pair<int, int>> visited;
        int cursub = 0;
        while (q.size()) {
            vector<pair<int, int>> vv;
            set<pair<int, int>> nst;
            while (q.size()) {
                vv.push_back(q.front());
                q.pop();
            }
            for (int i = 0; i < vv.size(); ++i) {
                visited.insert(vv[i]);
                v[vv[i].first][vv[i].second].first -= cursub;
                ++v[vv[i].first][vv[i].second].second;
                if (vv[i].first > 0 && v[vv[i].first - 1][vv[i].second].first <= 0) {
                    pair<int, int> tp = make_pair(vv[i].first - 1, vv[i].second);
                    if (!visited.count(tp)) nst.insert(tp);
                }
                if (vv[i].first < m - 1 && v[vv[i].first + 1][vv[i].second].first <= 0) {
                    pair<int, int> tp = make_pair(vv[i].first + 1, vv[i].second);
                    if (!visited.count(tp)) nst.insert(tp);
                }
                if (vv[i].second > 0 && v[vv[i].first][vv[i].second - 1].first <= 0) {
                    pair<int, int> tp = make_pair(vv[i].first, vv[i].second - 1);
                    if (!visited.count(tp)) nst.insert(tp);
                }
                if (vv[i].second < n - 1 && v[vv[i].first][vv[i].second + 1].first <= 0) {
                    pair<int, int> tp = make_pair(vv[i].first, vv[i].second + 1);
                    if (!visited.count(tp)) nst.insert(tp);
                }
            }
            for (auto it = nst.begin(); it != nst.end(); ++it) {
                q.push(*it);
            }
            ++cursub;
        }
    }
};