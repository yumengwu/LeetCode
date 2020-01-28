#include "../header.h"

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        int res = 0;
        map<int, int> m;
        int cnt = 0;
        int pre = 0;
        for (int i = 0, j = 0; i < A.size(); ++i) {
            if ((++m[A[i]]) == 1) {
                cnt++;
            }
            if (cnt > K) {
                --m[A[j++]];
                cnt--;
                pre = 0;
            }
            while (m[A[j]] > 1) {
                ++pre;
                --m[A[j++]];
            }
            if (cnt == K) {
                res += pre + 1;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> v{1,2,1,3,4};
    Solution s;
    cout<<s.subarraysWithKDistinct(v, 3)<<endl;
    return 0;
}