#include "../header.h"
/*
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
};*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        for (int num : nums) {
            vector<vector<int>> temp;
            if (res.empty()) {
                temp.push_back({num});
            }
            else {
                for (int i = 0; i < res.size(); ++i) {
                    for (int j = 0; j <= res[i].size(); ++j) {
                        res[i].insert(res[i].begin() + j, num);
                        temp.push_back(res[i]);
                        res[i].erase(res[i].begin() + j);
                    }
                }
            }
            res = temp;
        }
        return res;
    }
};

