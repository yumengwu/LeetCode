#include "../header.h"

// BFS
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<list<int>> m(n, list<int>());
        for (int i = 0; i < edges.size(); ++i) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int, int>> q;
        q.push(make_pair(-1, 0));
        vector<bool> used(n, false);
        while (q.size()) {
            pair<int, int> top = q.front();
            q.pop();
            used[top.second] = true;
            auto arr = m[top.second];
            for (int idx : arr) {
                if (idx == top.first) {
                    continue;
                }
                if (used[idx]) {
                    return false;
                }
                q.push(make_pair(top.second, idx));
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v{{0,1}, {0,2}, {0,3}, {1,4}};
    cout<<s.validTree(5, v)<<endl;
    return 0;
}