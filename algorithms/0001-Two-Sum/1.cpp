#include "../header.h"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> res;
        if (n < 2) {
            return res;
        }
        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[target - nums[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (m.find(nums[i]) != m.end() && m[nums[i]] != i) {
                res.push_back(i);
                res.push_back(m[nums[i]]);
                break;
            }
        }
        return res;
    }
};