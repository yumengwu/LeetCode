#include "../header.h"

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        if (n <= 3) {
            return res;
        }
        vector<int> temp;
        helper(res, temp, 2, n, n);
        return res;
    }
    
    void helper(vector<vector<int>>& res, vector<int>& temp, int start, int n, int N) {
        if (n == 1) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i <= N >> 1; ++i) {
            if (n % i == 0) {
                temp.push_back(i);
                helper(res, temp, i, n / i, N);
                temp.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = s.getFactors(37);
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}