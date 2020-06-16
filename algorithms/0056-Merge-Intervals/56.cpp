#include "../header.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        if (n == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                if (res.back()[1] < intervals[i][1]) {
                    res.back()[1] = intervals[i][1];
                }
            }
            else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

/* class Solution { */
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> res;
//         if (intervals.empty()) {
//             return res;
//         }
//         sort(intervals.begin(), intervals.end());
//         res.push_back(intervals.front());
//         for (int i = 1; i < intervals.size(); ++i) {
//             if (intervals[i][0] >res.back()[1]) {
//                 res.push_back(intervals[i]);
//             }
//             else if (intervals[i][1] > res.back()[1]) {
//                 res.back()[1] = intervals[i][1];
//             }
//         }
//         return res;
//     }
/* }; */

/* class Solution { */
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> res;
//         vector<int> start, end;
//         for (int i = 0; i < intervals.size(); ++i) {
//             start.push_back(intervals[i][0]);
//             end.push_back(intervals[i][1]);
//         }
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
    vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    v = s.merge(v);
    return 0;
}
