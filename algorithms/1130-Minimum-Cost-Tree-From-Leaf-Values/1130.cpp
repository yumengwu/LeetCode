#include "../header.h"

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return 0;
        }
        vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>(n));
        return helper(arr, v, 0, n - 1).first;
    }
    
    pair<int, int> helper(vector<int>& arr, vector<vector<pair<int, int>>> & v, int i, int j) {
        if (v[i][j].second) {
            return v[i][j];
        }
        if (i == j) {
            v[i][j].first = 0;
            v[i][j].second = arr[i];
            return v[i][j];
        }
        if (i == j - 1) {
            v[i][j].first = arr[i] * arr[j];
            v[i][j].second = max(arr[i], arr[j]);
            return v[i][j];
        }
        int mf = INT_MAX, ms;
        for (int k = i; k < j; ++k) {
            if (j >= arr.size()) {
                 break;
            }
            pair<int, int> p1 = helper(arr, v, i, k), p2 = helper(arr, v, k + 1, j);
            int cur = p1.second * p2.second + p1.first + p2.first;
            if (cur < mf) {
                mf = cur;
                ms = max(p1.second, p2.second);
            }
        }
        v[i][j].first = mf;
        v[i][j].second = ms;
        return v[i][j];
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3,4};
    cout<<s.mctFromLeafValues(v)<<endl;
    return 0;
}