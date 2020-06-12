#include "../header.h"

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> v(26, 0);
        for (char c : S) {
            ++v[c - 'a'];
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq;
        int total = 0, mc = 0;
        for (int i = 0; i < 26; ++i) {
            if (v[i]) {
                pq.push(make_pair(i + 'a', v[i]));
                total += v[i];
                mc = max(mc, v[i]);
            }
        }
        if (((total & 1) == 0) && mc > total / 2 || (total & 1) && mc > (total / 2 + 1)) {
            return "";
        }
        string res;
        while (pq.size()) {
            pair<char, int> p = pq.top();
            pq.pop();
            res += p.first;
            if (--p.second) {
                if (p.second > pq.top().second) {
                    pair<char, int> pp = pq.top();
                    pq.pop();
                    res += pp.first;
                    if (--pp.second) {
                        pq.push(pp);
                    }
                }
                pq.push(p);
            }
        }
        return res;
    }

private:
    struct Compare {
        bool operator()(const pair<char, int>& p1, const pair<char, int>& p2) {
            return p1.second < p2.second;
        }
    };
};

