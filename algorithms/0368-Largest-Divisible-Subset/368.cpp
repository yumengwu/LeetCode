#include "../header.h"

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> len(n, 1);
        vector<int> id(n, 0);
        for (int i = 1; i < n; ++i) {
            id[i] = i;
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        id[i] = j;
                    }
                }
            }
        }
        int maxlen = len[0];
        int maxidx = 0;
        for (int i = 0; i < n; ++i) {
            if (len[i] > maxlen) {
                maxlen = len[i];
                maxidx = i;
            }
        }
        res.resize(maxlen);
        for (int i = 0; i < maxlen; ++i) {
            res[res.size() - 1 - i] = nums[maxidx];
            maxidx = id[maxidx];
        } 
        return res;
    }
};

int main()
{
    vector<int> v{3,4,16,8};
    Solution s;
    v = s.largestDivisibleSubset(v);
    for (int i = 0; i < v.size(); ++i) {
        cout<<v[i]<<' ';
    }cout<<endl;
    return 0;
}