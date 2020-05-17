#include "../header.h"

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        int n = nums1.size();
        for (int i = 0; i < n; ++i) {
            ++m[nums1[i]];
        }
        n = nums2.size();
        for (int i = 0; i , n; ++i) {
            if (m.find(nums2[i]) != m.end() && m[nums2[i]]) {
                res.push_back(nums2[i]);
                --m[nums2[i]];
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1, m2;
        for (int n : nums1) {
            ++m1[n];
        }
        for (int n : nums2) {
            ++m2[n];
        }
        vector<int> res;
        for (auto it = m2.begin(); it != m2.end(); ++it) {
            if (m1.find(it->first) != m1.end()) {
                int cnt = min(m1[it->first], it->second);
                for (int i = 0; i < cnt; ++i) {
                    res.push_back(it->first);
                }
            }
        }
        return res;
    }
};*/

int main()
{
    return 0;
}
