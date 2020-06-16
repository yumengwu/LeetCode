#include "../header.h"

// O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int max = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (sum >= 0) {
                sum += nums[i];
            }
            else {
                sum = nums[i];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};

/* divide and conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSub(nums, 0, nums.size() - 1);
    }

    int maxSub(vector<int>& nums, int l, int r) {
        if (l >= r) {
            return nums[l];
        }
        int mid = l + (r - l) / 2;
        return max(max(maxSub(nums, l, mid - 1), maxSub(nums, mid + 1, r)), maxCross(nums, l, mid, r));
    }

    int maxCross(vector<int>& nums, int l, int m, int r) {
        int ls = nums[m], rs = 0, sm = nums[m];
        int i = m - 1;
        while (i >= l) {
            sm += nums[i--];
            ls = max(ls, sm);
        }
        i = m + 1;
        sm = 0;
        while (i <= r) {
            sm += nums[i++];
            rs = max(rs, sm);
        }
        return ls + rs;
    }
};*/

