#include "../header.h"

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0, n;
        n = intervals.size();
        if (n == 0 || n == 1) {
            return n;
        }
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            ++m[intervals[i][0]];
            --m[intervals[i][1]];
        }
        int room = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            res = max(res, room += it->second);
        }
        return res;
    }
};