#include "../header.h"

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        unordered_set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(nums[i]);
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (s.find(nums[i]) == s.end()) {
                continue;
            }
            int len = 1;
            int cur = nums[i] - 1;
            while (s.find(cur) != s.end()) {
                ++len;
                s.erase(cur--);
            }
            cur = nums[i] + 1;
            while (s.find(cur) != s.end()) {
                ++len;
                s.erase(cur++);
            }
            s.erase(nums[i]);
            res = max(res, len);
        }
        return res;
    }
};