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

int main()
{
    return 0;
}