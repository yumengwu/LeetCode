#include "../header.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1;
        int num = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0) {
                ++cnt;
                num = nums[i];
            }
            else if (nums[i] == num) {
                ++cnt;
            }
            else {
                --cnt;
            }
        }
        return num;
    }
};

/*
static int _ = [] () {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
} ();

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int cur = nums[0], cnt = 1, n = nums.size();
        for (int i = 1; i < n; ++i) {
            if (cur == nums[i]) {
                ++cnt;
            }
            else {
                if (--cnt == 0) {
                    cur = nums[i];
                    cnt = 1;
                }
            }
        }
        return cur;
    }
};
*/

