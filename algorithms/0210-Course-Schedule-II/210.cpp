#include "../header.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        int n = prerequisites.size();
        if (n == 0) {
            for (int i = 0; i < numCourses; ++i) {
                res.push_back(i);
            }
            return res;
        }
        unordered_map<int, int> cnt;
        map<int, vector<int>> m;
        unordered_set<int> has;
        list<int> l;
        for (int i = 0; i < numCourses; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            ++cnt[prerequisites[i][0]];
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (cnt[i] == 0) {
                l.push_back(i);
            }
        }
        while (l.size()) {
            int first = l.front();
            l.pop_front();
            if (has.find(first) == has.end()) {
                res.push_back(first);
                has.insert(first);
            }
            vector<int> v = m[first];
            for (int i = 0; i < v.size(); ++i) {
                if (--cnt[v[i]] == 0) {
                    l.push_back(v[i]);
                    if (has.find(v[i]) == has.end()) {
                        res.push_back(v[i]);
                        has.insert(v[i]);
                    }
                }
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (cnt[i]) {
                res.clear();
                return res;
            }
        }
        return res;
    }
};