#include "../header.h"

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int, int>> v(arr.size());
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            v[i] = make_pair(cnt_bits(arr[i]), arr[i]);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; ++i) {
            arr[i] = v[i].second;
        }
        return arr;
    }
    
    int cnt_bits(int num) {
        int cnt = 0;
        for (int i = 0; i < 32; ++i) {
           cnt += (num & 1 << i ? 1 : 0);
        }
        return cnt;
    }
};