#include "../header.h"

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int half = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            half += nums[i];
        }
        if (half % 2 != 0) {
            return false;
        }
        half /= 2;
        vector<bool> v(half + 1, false);
        v[0] = true;
        for (int num : nums) {
            for (int i = half; i >= num; --i) {
                v[i] = v[i] || v[i - num];
            }
        }
        return v[half];
    }
};