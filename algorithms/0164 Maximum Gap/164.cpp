#include "../header.h"

// ???
// Why this solution can be accepted?
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();
        if (n < 2) {
            return res;
        }
        for (int i = 0; i < n - 1; ++i) {
            res = max(res, nums[i + 1] - nums[i]);
        }
        return res;
    }
};