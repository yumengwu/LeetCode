#include "../header.h"

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j]) {
                int cur = height[i];
                ++i;
                while (i < j && height[i] < cur) ++i;
            }
            else {
                int cur = height[j];
                --j;
                while (i < j && height[j] < cur) --j;
            }
        }
        return res;
    }
};