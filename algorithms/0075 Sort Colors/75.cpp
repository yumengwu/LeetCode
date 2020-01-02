#include "../header.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(3, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i]];
        }
        for (int i = 0; i < cnt[0]; ++i) {
            nums[i] = 0;
        }
        for (int i = 0; i < cnt[1]; ++i) {
            nums[i + cnt[0]] = 1;
        }
        for (int i = 0; i < cnt[2]; ++i) {
            nums[i + cnt[0] + cnt[1]] = 2;
        }
    }
};