#include "../header.h"

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        if (k == 0) {
            return;
        }
        for (int i = 0; i < (n - k) / 2; ++i) {
            swap(nums[i], nums[n - k - 1 - i]);
        }
        for (int i = 0; i < k / 2; ++i) {
            swap(nums[n - k + i], nums[n - i - 1]);
        }
        for (int i = 0; i < n / 2; ++i) {
            swap(nums[i], nums[n - i - 1]);
        }
    }
};