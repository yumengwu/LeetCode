#include "../header.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        map<int, int> m;
        for (int i = 1; i <= 9; ++i) {
            m[i] = 1;
        }
        vector<vector<int>> res;
        vector<int> temp;
        helper(res, temp, m, k, n);
        return res;
    }
    
    void helper(vector<vector<int>> & res, vector<int> & temp, map<int, int> & m, int k, int n) {
        if (k == 0) {
            if (n == 0) {
                res.push_back(temp);
            }
            return;
        }
        for (int i = 1; i <= 9; ++i) {
            if (i <= n && m[i] && (temp.size() == 0 || i > temp.back())) {
                temp.push_back(i);
                m[i] = 0;
                helper(res, temp, m, k - 1, n - i);
                m[i] = 1;
                temp.pop_back();
            }
            if (i > n) {
                return;
            }
        }
    }
};