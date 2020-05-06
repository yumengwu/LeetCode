#include "../header.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 4) {
            return {};
        }
        vector<vector<int>> res;
        for (int i = 0; i < n - 3; ++i) {
            while (i > 0 && i < n - 3 && nums[i] == nums[i - 1]) ++i;
            if (i == n - 3) break;
            for (int j = i + 1; j < n - 2; ++j) {
                while (j > i + 1 && j < n - 2 && nums[j] == nums[j - 1]) ++j;
                if (j == n - 2) break;
                helper(res, nums, target - nums[i] - nums[j], i, j);
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& nums, int target, int idx1, int idx2) {
        int n = nums.size();
        int l = idx2 + 1, r = n - 1;
        while (l < r) {
            bool nextl = false, nextr = false;
            if (nums[l] + nums[r] == target) {
                res.push_back({nums[idx1], nums[idx2], nums[l], nums[r]});
                nextl = true;
                nextr = true;
            }
            else if (nums[l] + nums[r] < target) {
                nextl = true;
            }
            else {
                nextr = true;
            }
            if (nextl) {
                ++l;
                while (l < r && nums[l] == nums[l - 1]) ++l;
            }
            if (nextr) {
                --r;
                while (l < r && nums[r] == nums[r + 1]) --r;
            }
        }
    }
};
