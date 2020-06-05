#include "../header.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        if (candidates.size() == 0) {
            return res;
        }
        vector<int> temp;
        helper(res, temp, candidates, 0, target);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& temp, vector<int>& arr, int idx, int target) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        while (idx < arr.size()) {
            if (arr[idx] > target) {
                break;
            }
            temp.push_back(arr[idx]);
            helper(res, temp, arr, idx + 1, target - arr[idx]);
            temp.pop_back();
            ++idx;
            while (idx < arr.size() && arr[idx] == arr[idx - 1]) {
                ++idx;
            }
        }
    }
};

