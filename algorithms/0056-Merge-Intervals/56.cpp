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

int main()
{
    vector<vector<int>> v{{1,3},{2,6},{8,10},{15,18}};
    Solution s;
    v = s.merge(v);
    return 0;
}