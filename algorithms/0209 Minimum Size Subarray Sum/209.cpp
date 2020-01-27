#include "../header.h"

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int left = 0, right = 0, res = INT_MAX, cur = 0;
        while (right < n) {
            while (cur < s && right < n) {
                cur += nums[right++];
            }
            while (cur >= s) {
                res = min(res, right - left);
                cur -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};