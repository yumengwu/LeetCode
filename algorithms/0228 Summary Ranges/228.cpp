#include "../header.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        string str;
        if (n == 0) {
            return res;
        }
        else if (n == 1) {
            str = to_string(nums[0]);
            res.push_back(str);
            return res;
        }
        int l = nums[0], ls = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == l + 1) {
                l = nums[i];
            }
            else {
                if (l == ls) {
                    str = to_string(ls);
                    res.push_back(str);
                }
                else {
                    str = to_string(ls);
                    str += "->";
                    str += to_string(l);
                    res.push_back(str);
                }
                ls = nums[i];
                l = ls;
            }
        }
        if (l == ls) {
            str = to_string(l);
            res.push_back(str);
        }
        else {
            str = to_string(ls);
            str += "->";
            str += to_string(l);
            res.push_back(str);
        }
        return res;
    }
};