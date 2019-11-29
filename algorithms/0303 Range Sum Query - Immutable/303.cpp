#include "../header.h"

class NumArray {
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        v.resize(n);
        if (n == 0) {
            return;
        }
        v[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            v[i] = v[i - 1] + nums[i];
        }
    }
    
    vector<int> v;
    
    int sumRange(int i, int j) {
        if (i == 0) {
            return v[j];
        }
        else {
            return v[j] - v[i - 1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */