#include "../header.h"

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        vector<unsigned long long> v(target + 1, 0);
        v[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i - nums[j] >= 0) {
                    v[i] += v[i - nums[j]];
                }
                else {
                    break;
                }
            }
        }
        return v[target];
    }
};