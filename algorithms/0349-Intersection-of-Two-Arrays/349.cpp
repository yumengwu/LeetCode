#include "../header.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> s(nums1.begin(), nums1.end());
        for (int i = 0; i < nums2.size(); ++i) {
            if (s.count(nums2[i])) {
                res.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return res;
    }
};

/*
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s, t;
        for (int i : nums1) {
            s.insert(i);
        }
        for (int i : nums2) {
            if (s.count(i)) {
                t.insert(i);
            }
        }
        vector<int> res;
        for (auto it = t.begin(); it != t.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
};*/

