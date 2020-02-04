#include "../header.h"

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        int i = 0, j = nums.size() - 1, idx = 0;
        while (i <= j && idx < nums.size()) {
            nums[idx++] = temp[i++];
            if (idx == nums.size()) {
                break;
            }
            nums[idx++] = temp[j--];
        }
    }
};