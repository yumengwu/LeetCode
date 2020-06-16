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

/* class Solution { */
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         vector<vector<int>> res;
//         vector<int> start, end;
//         for (int i = 0; i < intervals.size(); ++i) {
//             start.push_back(intervals[i][0]);
//             end.push_back(intervals[i][1]);
//         }
//         start.push_back(newInterval[0]);
//         end.push_back(newInterval[1]);
//         sort(start.begin(), start.end());
//         sort(end.begin(), end.end());
//         for (int i = 0, j = 0; i < start.size(); ++i) {
//             if (i == start.size() - 1 || start[i + 1] > end[i]) {
//                 res.push_back({start[j], end[i]});
//                 j = i + 1;
//             }
//         }
//         return res;
//     }
/* }; */

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
