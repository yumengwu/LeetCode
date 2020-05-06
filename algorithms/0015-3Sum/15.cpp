#include "../header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3 || nums.back() < 0 || nums.front() > 0) {
            return res;
        }
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] > 0) {
                break;
            }
            if (nums[i] == 0) {
                if (i < nums.size() - 2 && nums[i + 1] == 0 && nums[i + 2] == 0) {
                    res.push_back({0, 0, 0});
                }
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) {
                        ++j;
                    }
                    while (j < k && nums[k] == nums[k - 1]) {
                        --k;
                    }
                    ++j;
                    --k;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                }
                else {
                    --k;
                }
            }
            
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         if (n < 3 || nums.front() > 0 || nums.back() < 0) {
//             return {};
//         }
//         vector<vector<int>> res;
//         if (n == 3) {
//             if (nums[0] + nums[1] + nums[2] == 0) {
//                 res.push_back({nums[0], nums[1], nums[2]});
//             }
//             return res;
//         }
//         for (int i = 0; i < n; ++i) {
//             while (i > 0 && i < n && nums[i] == nums[i - 1]) ++i;
//             if (i == n) break;
//             if (nums[i] == 0) {
//                 if (i + 1 < n && i + 2 < n && nums[i + 1] == 0 && nums[i + 2] == 0) {
//                     res.push_back({0, 0, 0});
//                 }
//                 while (i < n && nums[i] == 0) ++i;
//             }
//             if (i == n) break;
//             if (nums[i] > 0) break;
//             helper(res, nums, -nums[i], i);
//         }
//         return res;
//     }
    
//     void helper(vector<vector<int>>& res, vector<int>& nums, int target, int idx) {
//         int n = nums.size();
//         int l = idx + 1, r = n - 1;
//         while (l < r) {
//             bool nextl = false, nextr = false;
//             if (nums[l] + nums[r] == target) {
//                 res.push_back({nums[idx], nums[l], nums[r]});
//                 nextl = nextr = true;
//             }
//             else if (nums[l] + nums[r] < target) {
//                 nextl = true;
//             }
//             else {
//                 nextr = true;
//             }
//             if (nextl) {
//                 ++l;
//                 while (l < n && (l == idx || nums[l] == nums[l - 1])) ++l;
//             }
//             if (nextr) {
//                 --r;
//                 while (0 <= r && (r == idx || nums[r] == nums[r + 1])) --r;
//             }
//         }
//     }
// };
