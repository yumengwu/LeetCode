#include "../header.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        int n = nums.size();
        if (n == 0) {
            return v;
        }
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            ++cnt[nums[i]];
        }
        map<int, vector<int>> m;
        for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it) {
            m[it->second].push_back(it->first);
        }
        for (map<int, vector<int>>::reverse_iterator it = m.rbegin(); it != m.rend(); ++it) {
            if (k <= 0) {
                break;
            }
            for (int i = 0; i < min(k, int(it->second.size())); ++i) {
                v.push_back(it->second[i]);
            }
            k -= it->second.size();
        }
        return v;
    }
};