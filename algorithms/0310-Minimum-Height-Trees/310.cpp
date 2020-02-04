#include "../header.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            return {0};
        }
        if (n == 2) {
            return {0, 1};
        }
        vector<vector<int>> graph(n, vector<int>());
        map<int, int> cnt;
        for (int i = 0; i < edges.size(); ++i) {
            ++cnt[edges[i][0]];
            ++cnt[edges[i][1]];
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        set<int> st;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second == 1) {
                st.insert(it->first);
            }
        }
        while (cnt.size() > 2) {
            set<int> tempset;
            for (int i : st) {
                for (int j : graph[i]) {
                    if (cnt.count(j) && --cnt[j] == 1) {
                        tempset.insert(j);
                    }
                }
            }
            for (int i : st) {
                cnt.erase(i);
            }
            st = tempset;
        }
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            res.push_back(it->first);
        }
        return res;
    }
};