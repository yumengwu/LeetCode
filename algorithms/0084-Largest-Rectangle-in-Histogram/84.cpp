#include "../header.h"

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return heights[0];
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n - 1 && heights[i] > heights[i + 1] || i == n - 1) {
                int mh = heights[i];
                for (int j = i; j >= 0; --j) {
                    if (heights[j] < mh) {
                        mh = heights[j];
                    }
                    res = max(res, mh * (i - j + 1));
                }
            }
        }
        return res;
    }
};