#include "../header.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), idx = -1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                idx = mid;
                break;
            }
            if (nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        if (idx < 0) {
            return {-1, -1};
        }
        l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        int resl = l;
        l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > target) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        int resr = r - 1;
        return {resl, resr};
    }
};

