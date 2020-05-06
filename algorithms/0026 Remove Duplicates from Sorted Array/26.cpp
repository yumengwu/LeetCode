#include "../header.h"

static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, n = nums.size();
        if (n <= 1) {
            return n;
        }
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[idx]) {
                nums[++idx] = nums[i];
            }
        }
        return idx + 1;
    }
};
