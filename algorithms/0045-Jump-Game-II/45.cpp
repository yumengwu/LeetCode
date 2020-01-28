#include "../header.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return 0;
        }
        vector<int> v(n, INT_MAX);
        v[0] = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (i > 0 && nums[i] == nums[i - 1] - 1) {
                continue;
            }
            for (int j = 0; j < nums[i] && i + j + 1 < n; ++j) {
                v[i + j + 1] = min(v[i + j + 1], v[i] + 1);
            }
        }
        return v[n - 1];
    }
};