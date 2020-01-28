#include "../header.h"

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if (n == 0 || n == 1) {
            return 0;
        }
        priority_queue<int, vector<int>, Compare> q;
        for (int i = 0; i < n; ++i) {
            q.push(sticks[i]);
        }
        int res = 0;
        while (q.size() > 1) {
            int temp = q.top();
            q.pop();
            temp += q.top();
            q.pop();
            q.push(temp);
            res += temp;
        }
        return res;
    }
    
private:
    struct Compare {
        bool operator()(int i1, int i2) {
            return i2 < i1;
        }
    };
};