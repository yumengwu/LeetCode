#include "../header.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(1, vector<int>(0));
        if (n == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        int ls = 0;
        for (int i = 0; i < n; ++i) {
            int ii = res.size();
            int j = i > 0 && nums[i] == nums[i - 1] ? ls : 0;
            ls = res.size();
            for (; j < ii; ++j) {
                vector<int> v = res[j];
                v.push_back(nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
};