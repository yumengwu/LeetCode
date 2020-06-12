#include "../header.h"

class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        int idx = 0, n = nums.size();
        while (idx < n) {
            vector<int> v(nums[idx], nums[idx + 1]);
            res.insert(res.end(), v.begin(), v.end());
            idx += 2;
        }
        return res;
    }
};

