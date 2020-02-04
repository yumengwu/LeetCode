#include "../header.h"

// dfs
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>());
        vector<bool> used(n, false);
        for (int i = 0; i < edges.size(); ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                ++cnt;
                dfs(graph, used, i);
            }
        }
        return cnt;
    }
    
    void dfs(vector<vector<int>> & graph, vector<bool> & used, int cur) {
        used[cur] = true;
        for (int next : graph[cur]) {
            if (!used[next]) {
                dfs(graph, used, next);
            }
        }
    }
};