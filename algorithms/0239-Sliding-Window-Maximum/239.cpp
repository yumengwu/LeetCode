#include "../header.h"

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
        for (int i = 0; i < k; ++i) {
            q.push(make_pair(nums[i], i));
        }
        res.push_back(q.top().first);
        for (int i = 1; i <= n - k; ++i) {
            q.push(make_pair(nums[i + k - 1], i + k - 1));
            while (q.size() && q.top().second < i) {
                q.pop();
            }
            res.push_back(q.top().first);
        }
        return res;
    }
private:
    struct Compare {
        bool operator()(pair<int, int> p1, pair<int, int> p2) {
            return p1.first < p2.first;
        }
    };
};

int main()
{
    return 0;
}