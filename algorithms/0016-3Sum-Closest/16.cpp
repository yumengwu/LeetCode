#include "../header.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) {
            return 0;
        }
        int clo = nums[0] + nums[1] + nums[2];
        int diff = abs(clo - target);
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int temp = nums[i] + nums[l] + nums[r];
                int td = abs(temp - target);
                if (td < diff) {
                    if (td == 0) return temp;
                    diff = td;
                    clo = temp;
                }
                if (temp < target) ++l;
                else --r;
            }
        }
        return clo;
    }
};
