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