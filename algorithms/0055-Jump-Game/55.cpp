#include "../header.h"

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return true;
        }
        int curmax = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i > curmax || curmax >= n - 1) {
                break;
            }
            curmax = max(curmax, i + nums[i]);
            if (curmax >= n - 1) {
                return true;
            }
        }
        return false;
    }
};