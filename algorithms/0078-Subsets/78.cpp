#include "../header.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(1, vector<int>(0));
        if (n == 0) {
            return res;
        }
        for (int i = 0; i < n; ++i) {
            int ii = res.size();
            for (int j = 0; j < ii; ++j) {
                vector<int> v = res[j];
                v.push_back(nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
};