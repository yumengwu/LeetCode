#include "../header.h"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if (n == 0) {
            return true;
        }
        if (n == 1) {
            return true;
        }
        unordered_map<int, int> cnt;
        map<int, vector<int>> m;
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
            vector<int> v = m[first];
            for (int i = 0; i < v.size(); ++i) {
                if (--cnt[v[i]] == 0) {
                    l.push_back(v[i]);
                }
            }
        }
        for (int i = 0; i < numCourses; ++i) {
            if (cnt[i]) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<int>> v{{1, 0}, {2, 0}};
    Solution s;
    cout<<s.canFinish(2, v)<<endl;
    return 0;
}