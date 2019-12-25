#include "../header.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) {
            return res;
        }
        helper(nums, res, nums.size(), 0);
        return res;
    }
    void swap(vector<int> & nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    void helper(vector<int> & nums, vector<vector<int>> & res, int len, int index) {
        if (index == len) {
            res.push_back(nums);
        }
        else {
            for(int i = index; i < len; ++i){
                swap(nums,index,i);
                helper(nums, res, len, index + 1);
                swap(nums, index, i);
            }
        }
    }
};