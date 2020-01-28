#include "../header.h"

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        if (n == 0) {
            res.push_back(newInterval);
            return res;
        }
        bool has = false;
        int idx = 0;
        while (idx < n) {
            if (!has && newInterval[0] < intervals[idx][0]) {
                if (res.empty() || newInterval[0] > res.back()[1]) {
                    res.push_back(newInterval);
                }
                else {
                    res.back()[1] = max(res.back()[1], newInterval[1]);
                }
                has = true;
            }
            else {
                if (res.empty() || intervals[idx][0] > res.back()[1]) {
                    res.push_back(intervals[idx]);
                }
                else {
                    res.back()[1] = max(res.back()[1], intervals[idx][1]);
                }
                ++idx;
            }
        }
        if (!has) {
            if (newInterval[0] > res.back()[1]) {
                res.push_back(newInterval);
            }
            else {
                res.back()[1] = max(res.back()[1], newInterval[1]);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> v{{0,2},{2,6},{10,12},{13,17},{18,22}};
    vector<int> ins{7,9};
    Solution s;
    v = s.insert(v, ins);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i][0]<<' '<<v[i][1]<<endl;
    }
    return 0;
}