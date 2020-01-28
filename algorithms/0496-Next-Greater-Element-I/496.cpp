#include "../header.h"

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> m;
        stack<int> st;
        int len1 = nums1.size(), len2 = nums2.size();
        vector<int> res(len1, -1);
        for (int i = 0; i < len2; ++i) {
            while (!st.empty() && st.top() < nums2[i]) {
                m[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        for (int i = 0; i < len1; ++i) {
            if (m.find(nums1[i]) != m.end()) {
                res[i] = m[nums1[i]];
            }
        }
        return res;
    }
};