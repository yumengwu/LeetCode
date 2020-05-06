#include "../header.h"

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) {
            res.push_back(getStr(lower, upper));
            return res;
        }
        if (nums[0] > lower) {
            res.push_back(getStr(lower, nums[0] - 1));
        }
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            if (nums[i] != nums[i + 1] - 1) {
                res.push_back(getStr(nums[i] + 1, nums[i + 1] - 1 <= upper ? nums[i + 1] - 1 : upper));
            }
            if (nums[i + 1] > upper) {
                return res;
            }
        }
        if (nums.back() < upper) {
            res.push_back(getStr(nums.back() + 1, upper));
        }
        return res;
    }
    
    string getStr(int start, int end) {
        string res = to_string(start);
        if (end > start) {
            res += "->";
            res += to_string(end);
        }
        return res;
    }
};