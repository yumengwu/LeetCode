#include "../header.h"

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<string, int> m;
        map<int, string> mm;
        m[vecToStr(cells)] = 0;
        mm[0] = vecToStr(cells);
        int idx1 = -1, idx2 = -1, idx = 0;
        vector<int> temp;
        while (true) {
            temp = cells;
            ++idx;
            temp[0] = temp[7] = 0;
            for (int i = 1; i < 7; ++i) {
                temp[i] = cells[i - 1] == cells[i + 1] ? 1 : 0;
            }
            cells = temp;
            if (idx == N) {
                return cells;
            }
            string curStr = vecToStr(cells);
            if (m.find(curStr) == m.end()) {
                m[curStr] = idx;
                mm[idx] = curStr;
            }
            else {
                idx1 = m[curStr];
                idx2 = idx;
                break;
            }
        }
        for (map<string, int>::iterator it = m.begin(); it != m.end(); ++it) {
            cout<<(it->first)<<": "<<(it->second)<<endl;
        }
        if (idx2 - idx1 == 1) {
            string str = mm[idx1];
            for (int i = 0; i < 8; ++i) {
                temp[i] = str[i] - '0';
            }
            return temp;
        }
        else {
            string str = mm[(N - idx1) % (idx2 - idx1) + idx1];
            for (int i = 0; i < 8; ++i) {
                temp[i] = str[i] - '0';
            }
            return temp;
        }
    }
    string vecToStr(vector<int> v) {
        string res = "";
        for (int i = 0; i < 8; ++i) {
            res += v[i] + '0';
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,0,0,1,0,0,1,0};
    v = s.prisonAfterNDays(v, 1000000000);
    for (int i = 0; i < 8; ++i) {
        cout<<v[i]<<' ';
    }
    cout<<endl;
    return 0;
}