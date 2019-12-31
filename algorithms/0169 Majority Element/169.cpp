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