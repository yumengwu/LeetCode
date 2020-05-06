#include "../header.h"

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, int> food_idx;
        int n = orders.size();
        for (int i = 0; i < n; ++i) {
            food_idx[orders[i][2]] = 0;
        }
        vector<vector<string>> res(1);
        res[0].push_back("Table");
        int cnt = 0;
        for (auto it = food_idx.begin(); it != food_idx.end(); ++it) {
            it->second = cnt++;
            res[0].push_back(it->first);
        }
        map<int, map<string, int>> m;
        for (int i = 0; i < n; ++i) {
            int idx = stoi(orders[i][1]);
            ++m[idx][orders[i][2]];
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            vector<string> row(res[0].size());
            row[0] = to_string(it->first);
            for (int i = 1; i < row.size(); ++i) {
                row[i] = "0";
            }
            for (auto iitt = it->second.begin(); iitt != it->second.end(); ++iitt) {
                row[food_idx[iitt->first] + 1] = to_string(iitt->second);
            }
            res.push_back(row);
        }
        return res;
    }
};

