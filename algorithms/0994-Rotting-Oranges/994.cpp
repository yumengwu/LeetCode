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

/*
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return -1;
        }
        int n = grid[0].size();
        set<pair<int, int>> st;
        int remain = 0, idx = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) {
                    st.insert(make_pair(i, j));
                }
                else if (grid[i][j] == 1) {
                    ++remain;
                }
            }
        }
        while (remain && st.size()) {
            set<pair<int, int>> temp;
            for (auto it = st.begin(); it != st.end(); ++it) {
                int i = it->first, j = it->second;
                if (i > 0 && grid[i - 1][j] == 1) {
                    grid[i - 1][j] = 2;
                    temp.insert(make_pair(i - 1, j));
                }
                if (i < m - 1 && grid[i + 1][j] == 1) {
                    grid[i + 1][j] = 2;
                    temp.insert(make_pair(i + 1, j));
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    grid[i][j - 1] = 2;
                    temp.insert(make_pair(i, j - 1));
                }
                if (j < n - 1 && grid[i][j + 1] == 1) {
                    grid[i][j + 1] = 2;
                    temp.insert(make_pair(i, j + 1));
                }
            }
            st = temp;
            remain -= st.size();
            ++idx;
        }
        return remain == 0 ? idx : -1;
    }
};*/

int main()
{
    Solution s;
    vector<vector<int>> v{{0,2,2}};
    cout<<s.orangesRotting(v)<<endl;
    return 0;
}
