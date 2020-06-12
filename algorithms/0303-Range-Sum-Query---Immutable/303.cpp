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

/*
class NumArray {
public:
    NumArray(vector<int>& nums) {
        v.resize(nums.size(), 0);
        if (nums.size() == 0) {
            return;
        }
        v[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            v[i] = nums[i] + v[i - 1];
        }
    }

    int sumRange(int i, int j) {
        int p = i == 0 ? 0 : v[i - 1];
        return v[j] - p;
    }

private:
    vector<int> v;
};*/

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
