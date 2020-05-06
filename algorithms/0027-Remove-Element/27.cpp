#include "../header.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] != val) {
                nums[idx++] = nums[i];
            }
        }
        return idx;
    }
};
