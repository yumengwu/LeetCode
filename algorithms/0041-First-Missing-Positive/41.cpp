#include "../header.h"

/*
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        set<int> st;
        for (int i : nums) {
            st.insert(i);
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (!st.count(i)) {
                return i;
            }
        }
        return nums.size() + 1;
    }
};*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0) {
                nums[i] = INT_MAX;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                helper(nums, i);
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
    
    void helper(vector<int>& nums, int idx) {
        if (nums[idx] <= nums.size()) {
            if (nums[idx] != idx + 1) {
                int n = nums[idx];
                nums[idx] = -2;
                if (nums[n - 1] > 0) {
                    helper(nums, n - 1);
                }
                nums[n - 1] = -1;
                if (nums[idx] != -1) {
                    nums[idx] = n;
                }
            }
            else {
                nums[idx] = -1;
            }
        }
    }
};

