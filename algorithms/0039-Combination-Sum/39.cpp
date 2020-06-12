#include "../header.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.size() == 0) {
            return res;
        }
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        helper(res, temp, candidates, 0, target);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& arr, int idx, int target) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        else if (target < 0) {
            return;
        }
        for (int i = idx; i < arr.size(); ++i) {
            if (arr[i] > target) {
                break;
            }
            temp.push_back(arr[i]);
            helper(res, temp, arr, i, target - arr[i]);
            temp.pop_back();
        }
    }
};


