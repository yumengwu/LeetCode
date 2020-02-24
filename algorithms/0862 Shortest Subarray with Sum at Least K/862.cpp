#include "../header.h"

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size(), res = INT_MAX;
        map<int, int> m;
        vector<int> sums(n + 1);
        for (int i = 1; i <= n; ++i) {
            sums[i] = sums[i - 1] + A[i - 1];
        }
        for (int i = 0; i <= n; ++i) {
            auto pos = m.upper_bound(sums[i] - K);
            for (auto it = m.begin(); it != pos; ++it) {
                res = min(res, i - it->second);
            }
            m.erase(m.begin(), pos);
            m[sums[i]] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    Solution s;
    vector<int> v{-28,81,-20,28,-29};
    cout<<s.shortestSubarray(v, 89)<<endl;
    return 0;
}